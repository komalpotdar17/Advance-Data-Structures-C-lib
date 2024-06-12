#include <stdio.h>
#include <stddef.h>
#include "mylib.h"

int main() {

    //Stack 
    /*print_heading("Stack Example", 3, set_pink_color);
    Stack* stack = stack_create(5);
    size_t i; // Corrected declaration to size_t
    for ( i = 0; i < 5; ++i) {
        stack_push(stack, i * 2);
    }

    printf("Stack elements: ");
    while (!stack_is_empty(stack)) {
        printf("%d ", stack_pop(stack));
    }
    printf("\n");

    stack_destroy(stack);


    //Queue
    print_heading("Queue Example", 3, set_green_color);
    Queue* queue = queue_create(5);
    
    for (i = 0; i < 5; ++i) {
        queue_enqueue(queue, i * 2);
    }

    printf("Queue elements: ");
    while (!queue_is_empty(queue)) {
        printf("%d ", queue_dequeue(queue));
    }
    printf("\n");

    queue_destroy(queue);


    // Vector
    print_heading("Vector Example", 3, set_bold_green_color);
    Vector* vec = vector_create();

    for (i = 0; i < 5; ++i) {
        vector_add(vec, i * 2);
    }
    printf("Vector elements: ");
    for (i = 0; i < vec->size; ++i) {
        printf("%d ", vector_get(vec, i));
    }
    printf("\n");

    vector_destroy(vec);

    // ArrayList
    print_heading("ArrayList Example", 4, set_bold_blue_color);
    ArrayList* arrList = arraylist_create();

    for (i = 0; i < 5; ++i) {
        arraylist_add(arrList, i * 3);
    }

    printf("ArrayList elements: ");
    for (i = 0; i < arrList->size; ++i) {
        printf("%d ", arraylist_get(arrList, i));
    }
    printf("\n");

    arraylist_destroy(arrList);

    // LinkedList
    print_heading("LinkedList Example", 5, set_bold_magenta_color);
    LinkedList* linkedList = linkedlist_create();

    for (i = 0; i < 5; ++i) {
        linkedlist_add(linkedList, i * 4);
    }

    printf("LinkedList elements: ");
    for (i = 0; i < linkedList->size; ++i) {
        printf("%d ", linkedlist_get(linkedList, i));
    }
    printf("\n");

    // Sorting the linked list
    linkedlist_sort(linkedList);

    print_heading("Sorted LinkedList elements", 5, set_bold_magenta_color);
    for (i = 0; i < linkedList->size; ++i) {
        printf("%d ", linkedlist_get(linkedList, i));
    }
    printf("\n");

    linkedlist_destroy(linkedList);

    // HashMap
    print_heading("HashMap Example", 4, set_bold_cyan_color);
    HashMap* hashMap = hashmap_create(5);

    // Putting key-value pairs into the HashMap
    hashmap_put(hashMap, 1, 10);
    hashmap_put(hashMap, 2, 20);
    hashmap_put(hashMap, 3, 30);

    // Getting values from the HashMap
    printf("HashMap values: ");
    printf("%d ", hashmap_get(hashMap, 1));
    printf("%d ", hashmap_get(hashMap, 2));
    printf("%d ", hashmap_get(hashMap, 3));
    printf("\n");

    hashmap_destroy(hashMap);

    // BinaryTree
    print_heading("BinaryTree Example", 4, set_bold_yellow_color);
    BinaryTree* binaryTree = binarytree_create();

    binarytree_insert(binaryTree, 50);
    binarytree_insert(binaryTree, 30);
    binarytree_insert(binaryTree, 70);
    binarytree_insert(binaryTree, 20);
    binarytree_insert(binaryTree, 40);

    printf("BinaryTree In-order traversal: ");
    binarytree_traverse_inorder(binaryTree);
	printf("BinaryTree Pre-order traversal: ");
	binarytree_traverse_preorder(binaryTree);
	printf("BinaryTree Post-order traversal: ");
	binarytree_traverse_postorder(binaryTree);

    binarytree_destroy(binaryTree);

    // DoublyLinkedList
    print_heading("DoublyLinkedList Example", 3, set_bold_red_color);
    DoublyLinkedList* doublyList = doublylinkedlist_create();

    for (i = 0; i < 5; ++i) {
        doublylinkedlist_add(doublyList, i * 5);
    }

    printf("DoublyLinkedList elements forward: ");
    doublylinkedlist_traverse_forward(doublyList);

    printf("DoublyLinkedList elements backward: ");
    doublylinkedlist_traverse_backward(doublyList);

    doublylinkedlist_destroy(doublyList);*/
	
	// Graph
    print_heading("Graph Example", 4, set_bold_cyan_color);
    Graph* graph = graph_create(5);

    // Add edges to the graph
    graph_add_edge(graph, 0, 1);
    graph_add_edge(graph, 0, 4);
    graph_add_edge(graph, 1, 2);
    graph_add_edge(graph, 1, 3);
    graph_add_edge(graph, 1, 4);
    graph_add_edge(graph, 2, 3);
    graph_add_edge(graph, 3, 4);

    // Print the adjacency list representation of the graph
    graph_print(graph);

    // Destroy the graph
    graph_destroy(graph);
    
	/*char inputFileName[100]; // Assuming maximum file name length of 99 characters
    char compressedFileName[100];
    char decompressedFileName[100];

    printf("Enter the name of the input file: ");
    scanf("%s", inputFileName);

    printf("Enter the name of the compressed file: ");
    scanf("%s", compressedFileName);

    printf("Enter the name of the decompressed file: ");
    scanf("%s", decompressedFileName);

    // Compress the file
    if (!compressFile(inputFileName, compressedFileName)) {
        printf("Compression failed\n");
        return 1;
    }
    printf("File compressed successfully\n");
    
    const char* fileName = compressedFileName;

    printf("Content of binary file \"%s\" in ASCII:\n", fileName);
    
    if (!binaryToAscii(fileName)) {
        printf("Error reading file\n");
        return 1;
    }
    
    printf("Content of text file \"%s\":\n", inputFileName);
    if (!displayTextFile(inputFileName)) {
        printf("Error reading text file\n");
        return 1;
    }
    
    // Displaying detailed manual for all data structures
    print_heading("Data Structures Manual", 6, set_bold_white_color);
    print_manual();
*/	
}
