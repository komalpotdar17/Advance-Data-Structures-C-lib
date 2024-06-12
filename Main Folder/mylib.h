// mylib.h
#include <stddef.h>
#include<stdbool.h>
#ifndef MYLIB_H
#define MYLIB_H
#define V 5

/// Stack
typedef struct {
    int* array;
    int top;
    int capacity;
} Stack;

// Function declarations
Stack* stack_create(int capacity);
void stack_destroy(Stack* stack);
bool stack_is_empty(const Stack* stack);
bool stack_is_full(const Stack* stack);
void stack_push(Stack* stack, int element);
int stack_pop(Stack* stack);
int stack_peek(const Stack* stack);



// Queue
typedef struct {
    int front, rear, size;
    unsigned capacity;
    int* array;
} Queue;

// Function declarations
Queue* queue_create(int capacity);
void queue_destroy(Queue* queue);
bool queue_is_empty(const Queue* queue);
bool queue_is_full(const Queue* queue);
void queue_enqueue(Queue* queue, int item);
int queue_dequeue(Queue* queue);
int queue_front(const Queue* queue);
int queue_rear(const Queue* queue);


//Vector 
typedef struct {
    int* array;
    size_t size;
    size_t capacity;
} Vector;

// Function declarations
Vector* vector_create();
void vector_destroy(Vector* vec);
int vector_add(Vector* vec, int element);
int vector_get(const Vector* vec, size_t index);
int vector_remove(Vector* vec, size_t index);


// ArrayList
typedef struct {
    int* array;     // Dynamic array to store elements
    size_t size;    // Current number of elements in the array
    size_t capacity; // Total capacity of the array
} ArrayList;

// Function declarations
ArrayList* arraylist_create();
void arraylist_destroy(ArrayList* list);
int arraylist_add(ArrayList* list, int element);
int arraylist_get(const ArrayList* list, size_t index);
int arraylist_remove(ArrayList* list, size_t index);

// LinkedList
typedef struct Node {
    int data;           // Data of the node
    struct Node* next;  // Pointer to the next node in the list
} Node;

typedef struct {
    Node* head;   // Pointer to the first node in the list
    size_t size;  // Current number of nodes in the list
} LinkedList;

// Function declarations
LinkedList* linkedlist_create();
void linkedlist_destroy(LinkedList* list);
int linkedlist_add(LinkedList* list, int element);
int linkedlist_get(const LinkedList* list, size_t index);
void linkedlist_sort(LinkedList* list);

// HashMap
typedef struct {
    int key;    // Key of the entry
    int value;  // Value associated with the key
} Entry;

typedef struct {
    Entry* entries;  // Array of key-value pairs
    size_t capacity; // Total capacity of the array
} HashMap;

// Function declarations
HashMap* hashmap_create(size_t capacity);
void hashmap_destroy(HashMap* map);
int hashmap_put(HashMap* map, int key, int value);
int hashmap_get(const HashMap* map, int key);

//TreeNode
typedef struct TreeNode {
    int data;            // Data of the node
    struct TreeNode* left;   // Pointer to the left child
    struct TreeNode* right;  // Pointer to the right child
} TreeNode;

typedef struct {
    TreeNode* root;   // Pointer to the root of the binary tree
} BinaryTree;

// Function declarations
BinaryTree* binarytree_create();
void binarytree_destroy(BinaryTree* tree);
void binarytree_insert(BinaryTree* tree, int data);
void binarytree_traverse_inorder(const BinaryTree* tree);
void binarytree_traverse_preorder(const BinaryTree* tree);
void binarytree_traverse_postorder(const BinaryTree* tree);


// DoublyNode structure represents a node in the doubly linked list
typedef struct DoublyNode {
    int data;                   // Data of the node
    struct DoublyNode* prev;    // Pointer to the previous node
    struct DoublyNode* next;    // Pointer to the next node
} DoublyNode;

// DoublyLinkedList structure represents the doubly linked list
typedef struct {
    DoublyNode* head;           // Pointer to the first node in the list
    size_t size;                // Current number of nodes in the list
} DoublyLinkedList;

// Function declarations for doubly linked list operations
DoublyLinkedList* doublylinkedlist_create();
void doublylinkedlist_destroy(DoublyLinkedList* list);
void doublylinkedlist_add(DoublyLinkedList* list, int data);
void doublylinkedlist_traverse_forward(const DoublyLinkedList* list);
void doublylinkedlist_traverse_backward(const DoublyLinkedList* list);
int doublylinkedlist_get_at(const DoublyLinkedList* list, size_t index);
void doublylinkedlist_insert_at(DoublyLinkedList* list, int data, size_t index);
void doublylinkedlist_remove_at(DoublyLinkedList* list, size_t index);
 
// Function to print the detailed manual for all data structures
void print_manual();

// Function to set the colors for all the data structures
// Function declarations for color-setting functions
void set_bold_black_color();
void set_bold_red_color();
void set_bold_green_color();
void set_bold_yellow_color();
void set_bold_blue_color();
void set_bold_magenta_color();
void set_bold_cyan_color();
void set_bold_white_color();
void set_green_color();
void set_pink_color();

void set_background_black_color();
void set_background_red_color();
void set_background_green_color();
void set_background_yellow_color();
void set_background_blue_color();
void set_background_magenta_color();
void set_background_cyan_color();
void set_background_white_color();
void reset_color();

//Function to set the size of the data structure
void print_heading(const char* text, int size, void (*color_function)());
void reset_text_size() ;
void set_text_size();

// Function to print a section header with a specified color, text size, and title
void print_section_header(const char* color, const char* textSize, const char* title);


// Define a structure for representing a graph node
typedef struct GraphNode {
    int data;
    struct GraphNode* next;  // Pointer to the next adjacent node
} GraphNode;

// Define a structure for representing a graph
typedef struct Graph {
    int num_vertices;
    GraphNode** adjacency_list;  // Array of pointers to adjacency lists
} Graph;

// Function to create a new graph with a given number of vertices
Graph* graph_create(int num_vertices);

// Function to add an edge between two vertices in the graph
void graph_add_edge(Graph* graph, int src, int dest);

//Function to add a vertex in the graph
void graph_add_vertex(Graph* graph);

// Function to print the adjacency list representation of the graph
void graph_print(Graph* graph);

// Function to destroy the graph and free memory
void graph_destroy(Graph* graph);

// Breadth-First Search (BFS) Traversal
void graph_bfs_traversal(Graph* graph, int start_vertex);

// Depth-First Search (DFS) Traversal
void graph_dfs_traversal(Graph* graph, int start_vertex);

//prims algorithm
void primMST(int graph[V][V]);

// Encryption function
void encryptFile(const char* inputFileName, const char* outputFileName, const char* key);

// Decryption function
void decryptFile(const char* inputFileName, const char* outputFileName, const char* key);

// Hashing function
void hashFile(const char* fileName);

// Function to compress the file using run-length encoding (RLE)
bool compressFile(const char* inputFileName, const char* outputFileName);

// Function to decompress the file using run-length decoding
bool decompressFile(const char* inputFileName, const char* outputFileName);

#endif  // MYLIB_H
