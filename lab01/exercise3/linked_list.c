#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

Node *create_node(int data) {
    struct Node *new_node = malloc(sizeof(struct Node));  // Allocate memory for a new node
    if (new_node == NULL) {
        perror("Malloc failed\n");  // Print an error message if memory allocation fails
    }
    new_node->data = data;  // Set the data of the new node
    new_node->next = NULL;  // Initialize the next pointer of the new node to NULL
    return new_node;  
}

void free_list(Node *head) {
    while (head != NULL) {  // Loop through the list
        Node *temp = head->next;  // Save the next node
        free(head);  // Free the current node
        head = temp;  // Move to the next node
    }
}

void add_to_front(struct Node **head, int data) {
    if (head == NULL) return;  // If the head is NULL, return
    struct Node *new_node = create_node(data);  // Create a new node with the given data
    if (*head != NULL) {
        new_node->next = *head;  // If the list is not empty, set the next pointer of the new node to the old head
    }
    *head = new_node;  // Update the head pointer to the new node
}

void print_list(struct Node *head) {
    struct Node *curr;
    for (curr = head; curr != NULL; curr = curr->next) {  // Loop through the list
        printf("%d->", curr->data);  // Print the data of the current node
    }
    printf("NULL\n");  // Print NULL to indicate the end of the list
}

void reverse_list(struct Node **head) {
    if (*head == NULL || head == NULL) {  // If the head is NULL or the list is empty, return
        return;
    }
    struct Node *curr = *head;  // Initialize the current node to the head
    struct Node *next = (*head)->next;  // Initialize the next node to the second node in the list
    curr->next = NULL;  // Set the next pointer of the head to NULL
    while (next != NULL) {  // Loop through the list
        struct Node *temp = next->next;  // Save the next node
        next->next = curr;  // Reverse the pointer of the next node to the current node
        curr = next;  // Move to the next node
        next = temp;
    }
    *head = curr;  // Update the head pointer to the new head
}

void add_to_back(Node **head, int data) {
    Node *new_node = create_node(data);  // Create a new node with the given data
    if (*head == NULL) {
    	*head=new_node;  // If the list is empty, set the head to the new node
        return;
    }
    
    Node *prev;
    for (Node *curr = *head; curr != NULL; curr = curr->next) {  // Find the last node in the list
        prev = curr;
    }
    prev->next = new_node;  // Add the new node to the back of the list
}

