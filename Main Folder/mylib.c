// mylib.c
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include<stdbool.h>
#include<string.h>


// Function to create a new stack
Stack* stack_create(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) {
        perror("Stack creation failed");
        exit(EXIT_FAILURE);
    }

    stack->array = (int*)malloc(capacity * sizeof(int));
    if (!stack->array) {
        perror("Stack array creation failed");
        free(stack);
        exit(EXIT_FAILURE);
    }

    stack->top = -1;
    stack->capacity = capacity;

    return stack;
}

// Function to check if the stack is empty
bool stack_is_empty(const Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
bool stack_is_full(const Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Function to push an element onto the stack
void stack_push(Stack* stack, int element) {
    if (stack_is_full(stack)) {
        fprintf(stderr, "Stack overflow\n");
        exit(EXIT_FAILURE);
    }

    stack->array[++stack->top] = element;
}

// Function to pop an element from the stack
int stack_pop(Stack* stack) {
    if (stack_is_empty(stack)) {
        fprintf(stderr, "Stack underflow\n");
        exit(EXIT_FAILURE);
    }

    return stack->array[stack->top--];
}

// Function to get the top element of the stack without popping it
int stack_peek(const Stack* stack) {
    if (stack_is_empty(stack)) {
        fprintf(stderr, "Stack is empty\n");
        exit(EXIT_FAILURE);
    }

    return stack->array[stack->top];
}

// Function to destroy the stack and free memory
void stack_destroy(Stack* stack) {
    free(stack->array);
    free(stack);
}

// Function to create a new queue
Queue* queue_create(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (!queue) {
        perror("Queue creation failed");
        exit(EXIT_FAILURE);
    }

    queue->array = (int*)malloc(capacity * sizeof(int));
    if (!queue->array) {
        perror("Queue array creation failed");
        free(queue);
        exit(EXIT_FAILURE);
    }

    queue->front = 0;
    queue->rear = capacity - 1;
    queue->capacity = capacity;
    queue->size = 0;

    return queue;
}

// Function to check if the queue is empty
bool queue_is_empty(const Queue* queue) {
    return queue->size == 0;
}

// Function to check if the queue is full
bool queue_is_full(const Queue* queue) {
    return queue->size == queue->capacity;
}

// Function to enqueue an element into the queue
void queue_enqueue(Queue* queue, int element) {
    if (queue_is_full(queue)) {
        fprintf(stderr, "Queue overflow\n");
        exit(EXIT_FAILURE);
    }

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = element;
    queue->size++;
}

// Function to dequeue an element from the queue
int queue_dequeue(Queue* queue) {
    if (queue_is_empty(queue)) {
        fprintf(stderr, "Queue underflow\n");
        exit(EXIT_FAILURE);
    }

    int element = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;

    return element;
}

// Function to get the front element of the queue without dequeuing it
int queue_front(const Queue* queue) {
    if (queue_is_empty(queue)) {
        fprintf(stderr, "Queue is empty\n");
        exit(EXIT_FAILURE);
    }

    return queue->array[queue->front];
}

// Function to get the rear element of the queue without dequeuing it
int queue_rear(const Queue* queue) {
    if (queue_is_empty(queue)) {
        fprintf(stderr, "Queue is empty\n");
        exit(EXIT_FAILURE);
    }

    return queue->array[queue->rear];
}


// Function to destroy the queue and free memory
void queue_destroy(Queue* queue) {
    free(queue->array);
    free(queue);
}

Vector* vector_create() {
    Vector* vec = (Vector*)malloc(sizeof(Vector));
    if (!vec) {
        perror("Vector creation failed");
        exit(EXIT_FAILURE);
    }

    vec->array = NULL;
    vec->size = 0;
    vec->capacity = 0;

    return vec;
}

void vector_destroy(Vector* vec) {
    free(vec->array);
    free(vec);
}

int vector_add(Vector* vec, int element) {
    if (vec->size == vec->capacity) {
        vec->capacity = vec->capacity == 0 ? 1 : vec->capacity * 2;
        vec->array = (int*)realloc(vec->array, vec->capacity * sizeof(int));
        if (!vec->array) {
            perror("Vector expansion failed");
            exit(EXIT_FAILURE);
        }
    }

    vec->array[vec->size++] = element;
    return 0;  // Success
}

int vector_get(const Vector* vec, size_t index) {
    if (index >= vec->size) {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    return vec->array[index];
}

int vector_remove(Vector* vec, size_t index) {
    if (index >= vec->size) {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
size_t i ;
    for ( i = index; i < vec->size - 1; ++i) {
        vec->array[i] = vec->array[i + 1];
    }

    vec->size--;

    return 0;  // Success
}


// ArrayList
ArrayList* arraylist_create() {
    ArrayList* list = (ArrayList*)malloc(sizeof(ArrayList));
    if (!list) {
        perror("ArrayList creation failed");
        exit(EXIT_FAILURE);
    }

    list->array = NULL;
    list->size = 0;
    list->capacity = 0;

    return list;
}

void arraylist_destroy(ArrayList* list) {
    free(list->array);
    free(list);
}

int arraylist_add(ArrayList* list, int element) {
    if (list->size == list->capacity) {
        list->capacity = list->capacity == 0 ? 1 : list->capacity * 2;
        list->array = (int*)realloc(list->array, list->capacity * sizeof(int));
        if (!list->array) {
            perror("ArrayList expansion failed");
            exit(EXIT_FAILURE);
        }
    }

    list->array[list->size++] = element;
    return 0;  // Success
}

int arraylist_get(const ArrayList* list, size_t index) {
    if (index >= list->size) {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    return list->array[index];
}

int arraylist_remove(ArrayList* list, size_t index) {
    if (index >= list->size) {
        fprintf(stderr, "Index out of bounds\n");
        return -1; // Failure
    }
size_t i ;
    for ( i = index; i < list->size - 1; ++i) {
        list->array[i] = list->array[i + 1];
    }

    list->size--;

    return 0; // Success
}


// LinkedList
LinkedList* linkedlist_create() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    if (!list) {
        perror("LinkedList creation failed");
        exit(EXIT_FAILURE);
    }

    list->head = NULL;
    list->size = 0;

    return list;
}

void linkedlist_destroy(LinkedList* list) {
    Node* current = list->head;
    Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    free(list);
}

int linkedlist_add(LinkedList* list, int element) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        perror("Node creation failed");
        exit(EXIT_FAILURE);
    }

    newNode->data = element;
    newNode->next = list->head;
    list->head = newNode;
    list->size++;

    return 0;  // Success
}

int linkedlist_get(const LinkedList* list, size_t index) {
    Node* current = list->head;
size_t i ;
    for ( i = 0; i < index; ++i) {
        if (current == NULL) {
            fprintf(stderr, "Index out of bounds\n");
            exit(EXIT_FAILURE);
        }
        current = current->next;
    }

    if (current == NULL) {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }

    return current->data;
}

// HashMap
HashMap* hashmap_create(size_t capacity) {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    if (!map) {
        perror("HashMap creation failed");
        exit(EXIT_FAILURE);
    }

    map->entries = (Entry*)malloc(capacity * sizeof(Entry));
    if (!map->entries) {
        perror("HashMap entries creation failed");
        free(map);
        exit(EXIT_FAILURE);
    }

    map->capacity = capacity;
size_t i ;
    // Initialize entries
    for ( i = 0; i < capacity; ++i) {
        map->entries[i].key = -1;  // Assume -1 is not a valid key
    }

    return map;
}

void hashmap_destroy(HashMap* map) {
    free(map->entries);
    free(map);
}

int hashmap_put(HashMap* map, int key, int value) {
    size_t index = key % map->capacity;

    // Linear probing for collision resolution
    while (map->entries[index].key != -1) {
        if (map->entries[index].key == key) {
            // Key already exists, update the value
            map->entries[index].value = value;
            return 0;  // Success
        }

        index = (index + 1) % map->capacity;
    }

    // Found an empty slot
    map->entries[index].key = key;
    map->entries[index].value = value;

    return 0;  // Success
}

int hashmap_get(const HashMap* map, int key) {
    size_t index = key % map->capacity;

    // Linear probing for collision resolution
    while (map->entries[index].key != -1) {
        if (map->entries[index].key == key) {
            return map->entries[index].value;
        }

        index = (index + 1) % map->capacity;
    }

    // Key not found
    fprintf(stderr, "Key not found in the HashMap\n");
    exit(EXIT_FAILURE);
}

int hashmap_remove(HashMap* map, int key) {
    size_t index = key % map->capacity;

    
    while (map->entries[index].key != -1) {
        if (map->entries[index].key == key) {
           
            map->entries[index].key = -1; 
            map->entries[index].value = 0; 
            return 0; // Success
        }

        index = (index + 1) % map->capacity;
    }

    fprintf(stderr, "Key not found in the HashMap\n");
    return -1; // Failure
}



// Function to create a new binary tree
BinaryTree* binarytree_create() {
    BinaryTree* tree = (BinaryTree*)malloc(sizeof(BinaryTree));
    if (!tree) {
        perror("BinaryTree creation failed");
        exit(EXIT_FAILURE);
    }

    tree->root = NULL;
    return tree;
}

// Helper function to recursively destroy the binary tree
void destroy_tree_nodes(TreeNode* node) {
    if (node) {
        destroy_tree_nodes(node->left);
        destroy_tree_nodes(node->right);
        free(node);
    }
}

// Function to destroy the binary tree
void binarytree_destroy(BinaryTree* tree) {
    destroy_tree_nodes(tree->root);
    free(tree);
}

// Helper function to recursively insert a new node into the binary tree
TreeNode* insert_recursive(TreeNode* node, int data) {
    if (node == NULL) {
        TreeNode* new_node = (TreeNode*)malloc(sizeof(TreeNode));
        if (!new_node) {
            perror("TreeNode creation failed");
            exit(EXIT_FAILURE);
        }

        new_node->data = data;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }

    if (data < node->data) {
        node->left = insert_recursive(node->left, data);
    } else if (data > node->data) {
        node->right = insert_recursive(node->right, data);
    }

    return node;
}

// Function to insert a new node into the binary tree
void binarytree_insert(BinaryTree* tree, int data) {
    tree->root = insert_recursive(tree->root, data);
}

// Helper function to recursively traverse the binary tree in-order
void traverse_inorder_recursive(const TreeNode* node) {
    if (node) {
        traverse_inorder_recursive(node->left);
        printf("%d ", node->data);
        traverse_inorder_recursive(node->right);
    }
}

// Function to traverse the binary tree in-order
void binarytree_traverse_inorder(const BinaryTree* tree) {
    traverse_inorder_recursive(tree->root);
    printf("\n");
}

// Helper function to recursively perform preorder traversal
void traverse_preorder_recursive(const TreeNode* node) {
    if (node) {
        printf("%d ", node->data);
        traverse_preorder_recursive(node->left);
        traverse_preorder_recursive(node->right);
    }
}

// Function to perform preorder traversal of the binary tree
void binarytree_traverse_preorder(const BinaryTree* tree) {
    traverse_preorder_recursive(tree->root);
    printf("\n");
}

// Helper function to recursively perform postorder traversal
void traverse_postorder_recursive(const TreeNode* node) {
    if (node) {
        traverse_postorder_recursive(node->left);
        traverse_postorder_recursive(node->right);
        printf("%d ", node->data);
    }
}

// Function to perform postorder traversal of the binary tree
void binarytree_traverse_postorder(const BinaryTree* tree) {
    traverse_postorder_recursive(tree->root);
    printf("\n");
}

// Function to create a new doubly linked list
DoublyLinkedList* doublylinkedlist_create() {
    DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    if (!list) {
        perror("DoublyLinkedList creation failed");
        exit(EXIT_FAILURE);
    }

    list->head = NULL;
    list->size = 0;
    return list;
}

// Function to destroy the doubly linked list
void doublylinkedlist_destroy(DoublyLinkedList* list) {
    DoublyNode* current = list->head;
    DoublyNode* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    free(list);
}

// Function to add a new node to the end of the doubly linked list
void doublylinkedlist_add(DoublyLinkedList* list, int data) {
    DoublyNode* new_node = (DoublyNode*)malloc(sizeof(DoublyNode));
    if (!new_node) {
        perror("DoublyNode creation failed");
        exit(EXIT_FAILURE);
    }

    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
    } else {
        DoublyNode* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }

        current->next = new_node;
        new_node->prev = current;
    }

    list->size++;
}

// Function to traverse the doubly linked list forward
void doublylinkedlist_traverse_forward(const DoublyLinkedList* list) {
    DoublyNode* current = list->head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

// Function to traverse the doubly linked list backward
void doublylinkedlist_traverse_backward(const DoublyLinkedList* list) {
    DoublyNode* current = list->head;

    // Move to the last node
    while (current != NULL && current->next != NULL) {
        current = current->next;
    }

    // Traverse backward
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }

    printf("\n");
}

// Function to sort the linked list using insertion sort
void linkedlist_sort(LinkedList* list) {
    if (list->size <= 1) {
        // Already sorted or empty list
        return;
    }

    Node* sorted = NULL;
    Node* current = list->head;

    while (current != NULL) {
        Node* next = current->next;

        // Insert current node into the sorted list
        if (sorted == NULL || current->data < sorted->data) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* search = sorted;
            while (search->next != NULL && current->data > search->next->data) {
                search = search->next;
            }
            current->next = search->next;
            search->next = current;
        }

        current = next;
    }

    // Update the head of the list to the sorted list
    list->head = sorted;
}

void doublylinkedlist_remove_at(DoublyLinkedList* list, size_t index) {
    if (index >= list->size) {
        fprintf(stderr, "Index out of bounds\n");
        return;
    }

    DoublyNode* current = list->head;
    DoublyNode* previous = NULL;
size_t i ;
    // Traverse to the node at the specified index
    for ( i = 0; i < index; ++i) {
        previous = current;
        current = current->next;
    }

    // Update the previous node's next pointer
    if (previous != NULL) {
        previous->next = current->next;
    } else {
        // If removing the head node, update the head pointer
        list->head = current->next;
    }

    // Update the next node's previous pointer
    if (current->next != NULL) {
        current->next->prev = previous;
    }

    // Free the memory of the removed node
    free(current);

    // Update the size of the list
    list->size--;
}

void doublylinkedlist_insert_at(DoublyLinkedList* list, int data, size_t index) {
    if (index > list->size) {
        fprintf(stderr, "Index out of bounds\n");
        return;
    }

    // Create a new node
    DoublyNode* new_node = (DoublyNode*)malloc(sizeof(DoublyNode));
    if (!new_node) {
        perror("DoublyNode creation failed");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    // If the list is empty or index is 0, insert at the beginning
    if (index == 0 || list->size == 0) {
        new_node->next = list->head;
        if (list->head != NULL) {
            list->head->prev = new_node;
        }
        list->head = new_node;
    } else {
        // Traverse the list to find the insertion point
        DoublyNode* current = list->head;
        size_t i ;
        for ( i = 0; i < index - 1; ++i) {
            current = current->next;
        }

        // Insert the new node
        new_node->next = current->next;
        if (current->next != NULL) {
            current->next->prev = new_node;
        }
        current->next = new_node;
        new_node->prev = current;
    }

    list->size++;
}

int doublylinkedlist_get_at(const DoublyLinkedList* list, size_t index) {
    if (index >= list->size) {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }

    DoublyNode* current = list->head;
    size_t i = 0;
    while (current != NULL && i < index) {
        current = current->next;
        i++;
    }

    if (current == NULL) {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }

    return current->data;
}


// Function to print the detailed manual for all data structures
// Function to print the detailed manual for all data structures
void print_manual() {
    // Set colors and sizes
    set_bold_white_color();
    set_background_blue_color();
    set_text_size(6);
    
    printf("MyLib - Custom C Library Manual:\n\n");

    // Reset colors and sizes
    reset_color();

// Stack
set_bold_blue_color();
set_text_size(4);
printf("Stack:\n");
reset_color();
set_text_size(3);
printf("- stack_create(capacity) - Create a new stack with specified capacity.\n");
printf("- stack_destroy(stack) - Destroy the stack.\n");
printf("- stack_push(stack, element) - Push an element onto the stack.\n");
printf("- stack_pop(stack) - Pop an element from the stack.\n");
printf("- stack_peek(stack) - Get the top element of the stack without popping.\n\n");

// Queue
set_bold_yellow_color();
set_text_size(4);
printf("Queue:\n");
reset_color();
set_text_size(3);
printf("- queue_create(capacity) - Create a new queue with specified capacity.\n");
printf("- queue_destroy(queue) - Destroy the queue.\n");
printf("- queue_enqueue(queue, element) - Enqueue an element into the queue.\n");
printf("- queue_dequeue(queue) - Dequeue an element from the queue.\n");
printf("- queue_front(queue) - Get the front element of the queue without dequeuing.\n\n");

    // Vector
    set_bold_green_color();
    set_text_size(4);
    printf("Vector:\n");
    reset_color();
    set_text_size(3);
    printf("- vector_create() - Create a new vector.\n");
    printf("- vector_destroy(vec) - Destroy the vector.\n");
    printf("- vector_add(vec, element) - Add an element to the vector.\n");
    printf("- vector_get(vec, index) - Get the element at the specified index in the vector.\n\n");

    // ArrayList
    set_bold_blue_color();
    set_text_size(4);
    printf("ArrayList:\n");
    reset_color();
    set_text_size(3);
    printf("- arraylist_create() - Create a new ArrayList.\n");
    printf("- arraylist_destroy(list) - Destroy the ArrayList.\n");
    printf("- arraylist_add(list, element) - Add an element to the ArrayList.\n");
    printf("- arraylist_get(list, index) - Get the element at the specified index in the ArrayList.\n\n");

    // LinkedList
    set_bold_magenta_color();
    set_text_size(4);
    printf("LinkedList:\n");
    reset_color();
    set_text_size(3);
    printf("- linkedlist_create() - Create a new linked list.\n");
    printf("- linkedlist_destroy(list) - Destroy the linked list.\n");
    printf("- linkedlist_add(list, element) - Add an element to the linked list.\n");
    printf("- linkedlist_get(list, index) - Get the element at the specified index in the linked list.\n");
    printf("- linkedlist_sort(list) - Sort the linked list.\n\n");

    // HashMap
    set_bold_cyan_color();
    set_text_size(4);
    printf("HashMap:\n");
    reset_color();
    set_text_size(3);
    printf("- hashmap_create(capacity) - Create a new HashMap with the specified capacity.\n");
    printf("- hashmap_destroy(map) - Destroy the HashMap.\n");
    printf("- hashmap_put(map, key, value) - Put a key-value pair into the HashMap.\n");
    printf("- hashmap_get(map, key) - Get the value associated with the specified key in the HashMap.\n\n");

    // BinaryTree
    set_bold_yellow_color();
    set_text_size(4);
    printf("BinaryTree:\n");
    reset_color();
    set_text_size(3);
    printf("- binarytree_create() - Create a new binary tree.\n");
    printf("- binarytree_destroy(tree) - Destroy the binary tree.\n");
    printf("- binarytree_insert(tree, data) - Insert a node with the given data into the binary tree.\n");
    printf("- binarytree_traverse_inorder(tree) - Traverse the binary tree in-order.\n");
	printf("- binarytree_traverse_preorder(tree) - Traverse the binary tree pre-order.\n");
	printf("- binarytree_traverse_postorder(tree) - Traverse the binary tree post-order.\n\n");

    // DoublyLinkedList
    set_bold_red_color();
    set_text_size(4);
    printf("DoublyLinkedList:\n");
    reset_color();
    set_text_size(3);
    printf("- doublylinkedlist_create() - Create a new doubly linked list.\n");
    printf("- doublylinkedlist_destroy(list) - Destroy the doubly linked list.\n");
    printf("- doublylinkedlist_add(list, data) - Add a node with the given data to the end of the doubly linked list.\n");
    printf("- doublylinkedlist_traverse_forward(list) - Traverse the doubly linked list forward.\n");
    printf("- doublylinkedlist_traverse_backward(list) - Traverse the doubly linked list backward.\n\n");
	
	set_bold_cyan_color();
    set_text_size(4);
    printf("Colors :\n");
    reset_color();
    set_text_size(3);
	printf("- set_bold_green_color() - Changes text color to bold green.\n");
    printf("- set_background_blue_color() - Changes background color to blue.\n");
    printf("- set_bold_blue_color() - Changes text color to bold blue.\n");
    printf("- set_bold_magenta_color() - Changes text color to bold magenta.\n");
   	printf("- set_bold_cyan_color() - Changes text color to bold cyan.\n");
    printf("- set_bold_red_color() - Changes text color to bold red.\n");
   	printf("- set_bold_yellow_color() - Changes text color to bold yellow.\n");
    
	printf("- reset_color() - Resets text and background color to default.\n");
    

    // Reset to default
    reset_text_size();
}


//Set the colors customized// mylib.c
void set_pink_color() {
    printf("\033[1;35m"); // Set text color to pink
}

void set_green_color() {
    printf("\033[1;32m"); // Set text color to green
}

void set_bold_black_color() {
    printf("\033[1;30m");  // ANSI escape code for bold black text
}

void set_bold_red_color() {
    printf("\033[1;31m");  // ANSI escape code for bold red text
}

void set_bold_green_color() {
    printf("\033[1;32m");  // ANSI escape code for bold green text
}

void set_bold_yellow_color() {
    printf("\033[1;33m");  // ANSI escape code for bold yellow text
}

void set_bold_blue_color() {
    printf("\033[1;34m");  // ANSI escape code for bold blue text
}

void set_bold_magenta_color() {
    printf("\033[1;35m");  // ANSI escape code for bold magenta text
}

void set_bold_cyan_color() {
    printf("\033[1;36m");  // ANSI escape code for bold cyan text
}

void set_bold_white_color() {
    printf("\033[1;37m");  // ANSI escape code for bold white text
}

void set_background_black_color() {
    printf("\033[40m");  // ANSI escape code for black background
}

void set_background_red_color() {
    printf("\033[41m");  // ANSI escape code for red background
}

void set_background_green_color() {
    printf("\033[42m");  // ANSI escape code for green background
}

void set_background_yellow_color() {
    printf("\033[43m");  // ANSI escape code for yellow background
}

void set_background_blue_color() {
    printf("\033[44m");  // ANSI escape code for blue background
}

void set_background_magenta_color() {
    printf("\033[45m");  // ANSI escape code for magenta background
}

void set_background_cyan_color() {
    printf("\033[46m");  // ANSI escape code for cyan background
}

void set_background_white_color() {
    printf("\033[47m");  // ANSI escape code for white background
}

void reset_color() {
    printf("\033[0m");  // ANSI escape code to reset text and background color
}

void set_text_size(int size) {
    printf("\033[%d;1m", size);  // ANSI escape code to set text size
}

void reset_text_size() {
    printf("\033[0m");  // ANSI escape code to reset text size
}


//Function that prints the heading 
void print_heading(const char* text, int size, void (*color_function)()) {
    if (color_function) {
        color_function();
    }

    set_text_size(size);
    printf("%s\n", text);
    reset_text_size();

    if (color_function) {
        reset_color();
    }
}

// Function to create a new graph with a given number of vertices
Graph* graph_create(int num_vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    if (!graph) {
        perror("Graph creation failed");
        exit(EXIT_FAILURE);
    }

    graph->num_vertices = num_vertices;
    graph->adjacency_list = (GraphNode**)malloc(num_vertices * sizeof(GraphNode*));
    if (!graph->adjacency_list) {
        perror("Graph adjacency list creation failed");
        free(graph);
        exit(EXIT_FAILURE);
    }
int i;
    // Initialize adjacency lists to NULL
    for ( i = 0; i < num_vertices; ++i) {
        graph->adjacency_list[i] = NULL;
    }

    return graph;
}

// Function to add an edge between two vertices in the graph
void graph_add_edge(Graph* graph, int src, int dest) {
    // Add dest to the adjacency list of src
    GraphNode* newNode = (GraphNode*)malloc(sizeof(GraphNode));
    if (!newNode) {
        perror("Graph node creation failed");
        exit(EXIT_FAILURE);
    }

    newNode->data = dest;
    newNode->next = graph->adjacency_list[src];
    graph->adjacency_list[src] = newNode;

    // For an undirected graph, you may want to add the reverse edge as well
    // newNode = (GraphNode*)malloc(sizeof(GraphNode));
    // if (!newNode) {
    //     perror("Graph node creation failed");
    //     exit(EXIT_FAILURE);
    // }
    // newNode->data = src;
    // newNode->next = graph->adjacency_list[dest];
    // graph->adjacency_list[dest] = newNode;
}

// Function to print the adjacency list representation of the graph
void graph_print(Graph* graph) {
    printf("Graph Adjacency List:\n");
    int i;
    for ( i = 0; i < graph->num_vertices; ++i) {
        printf("%d -> ", i);
        GraphNode* current = graph->adjacency_list[i];
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
            if (current != NULL) {
                printf("-> ");
            }
        }
        printf("\n");
    }
}

// Function to destroy the graph and free memory
void graph_destroy(Graph* graph) {
	int i;
    for ( i = 0; i < graph->num_vertices; ++i) {
        GraphNode* current = graph->adjacency_list[i];
        while (current != NULL) {
            GraphNode* next = current->next;
            free(current);
            current = next;
        }
    }
    free(graph->adjacency_list);
    free(graph);
}

void graph_add_vertex(Graph* graph) {
    // Increase the number of vertices
    graph->num_vertices++;

    // Resize the adjacency list to accommodate the new vertex
    graph->adjacency_list = (GraphNode**)realloc(graph->adjacency_list, graph->num_vertices * sizeof(GraphNode*));
    if (!graph->adjacency_list) {
        perror("Graph adjacency list reallocation failed");
        exit(EXIT_FAILURE);
    }

    // Initialize the new vertex's adjacency list to NULL
    graph->adjacency_list[graph->num_vertices - 1] = NULL;
}

// Breadth-First Search (BFS) Traversal
void graph_bfs_traversal(Graph* graph, int start_vertex) {
    // Create a queue for BFS with the capacity of the graph's adjacency list
    Queue* queue = queue_create(graph->num_vertices);

    // Mark all vertices as not visited
    bool* visited = (bool*)malloc(graph->num_vertices * sizeof(bool));
    if (!visited) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    int i;
    for ( i = 0; i < graph->num_vertices; ++i) {
        visited[i] = false;
    }

    // Enqueue the starting vertex and mark it as visited
    queue_enqueue(queue, start_vertex);
    visited[start_vertex] = true;

    // Perform BFS traversal
    while (!queue_is_empty(queue)) {
        int current_vertex = queue_dequeue(queue);
        printf("%d ", current_vertex);

        // Traverse adjacent vertices of the current vertex
        GraphNode* current = graph->adjacency_list[current_vertex];
        while (current != NULL) {
            int adjacent_vertex = current->data;
            if (!visited[adjacent_vertex]) {
                queue_enqueue(queue, adjacent_vertex);
                visited[adjacent_vertex] = true;
            }
            current = current->next;
        }
    }

    // Free memory
    free(visited);
    queue_destroy(queue);
}


// Depth-First Search (DFS) Traversal
void graph_dfs_traversal_recursive(Graph* graph, int vertex, bool* visited) {
    visited[vertex] = true;
    printf("%d ", vertex);

    // Traverse adjacent vertices of the current vertex recursively
    GraphNode* current = graph->adjacency_list[vertex];
    while (current != NULL) {
        int adjacent_vertex = current->data;
        if (!visited[adjacent_vertex]) {
            graph_dfs_traversal_recursive(graph, adjacent_vertex, visited);
        }
        current = current->next;
    }
}

void graph_dfs_traversal(Graph* graph, int start_vertex) {
    // Mark all vertices as not visited
    bool* visited = (bool*)malloc(graph->num_vertices * sizeof(bool));
    if (!visited) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    int i;
	for ( i = 0; i < graph->num_vertices; ++i) {
        visited[i] = false;
    }

    // Call the recursive function for DFS traversal
    graph_dfs_traversal_recursive(graph, start_vertex, visited);

    // Free memory
    free(visited);
}



// Function to compress the file using run-length encoding (RLE)
bool compressFile(const char* inputFileName, const char* outputFileName) {
    FILE* inputFile = fopen(inputFileName, "rb");
    if (!inputFile) {
        perror("Error opening input file");
        return false;
    }

    FILE* outputFile = fopen(outputFileName, "wb");
    if (!outputFile) {
        perror("Error creating output file");
        fclose(inputFile);
        return false;
    }

    int prevChar = fgetc(inputFile);
    int count = 1;
    int ch;

    while ((ch = fgetc(inputFile)) != EOF) {
        if (ch == prevChar) {
            count++;
        } else {
            fwrite(&count, sizeof(int), 1, outputFile);
            fwrite(&prevChar, sizeof(int), 1, outputFile);
            prevChar = ch;
            count = 1;
        }
    }

    fwrite(&count, sizeof(int), 1, outputFile);
    fwrite(&prevChar, sizeof(int), 1, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    return true;
}

// Function to decompress the file using run-length decoding
bool decompressFile(const char* inputFileName, const char* outputFileName) {
    FILE* inputFile = fopen(inputFileName, "rb");
    if (!inputFile) {
        perror("Error opening input file");
        return false;
    }

    FILE* outputFile = fopen(outputFileName, "wb");
    if (!outputFile) {
        perror("Error creating output file");
        fclose(inputFile);
        return false;
    }

    int count, ch;

    while (fread(&count, sizeof(int), 1, inputFile) == 1) {
        fread(&ch, sizeof(int), 1, inputFile);
        int i;
        for ( i = 0; i < count; i++) {
            fputc(ch, outputFile);
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    return true;
}

// Function to display binary file content as ASCII characters
bool binaryToAscii(const char* fileName) {
    FILE* file = fopen(fileName, "rb");
    if (!file) {
        perror("Error opening file");
        return false;
    }

    int ch;
    while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
    }

    fclose(file);
    return true;
}

// Function to display text file content
bool displayTextFile(const char* fileName) {
    FILE* file = fopen(fileName, "r");
    if (!file) {
        perror("Error opening file");
        return false;
    }

    int ch;
    while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
    }

    fclose(file);
    return true;
}

