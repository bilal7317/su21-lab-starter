#include <stddef.h>
#include "ll_cycle.h"
#include <stdbool.h>

// Function to check if a linked list has a cycle
int ll_has_cycle(node *head) {
    // If the list is empty, it doesn't have a cycle
    if (head == NULL) {
        return false;
    }

    // Initialize two pointers at the head of the list
    node *slow_ptr = head;  // This pointer will move one step at a time
    node *fast_ptr = head;  // This pointer will move two steps at a time

    // Loop through the list
    while (fast_ptr != NULL && fast_ptr->next != NULL) {
        slow_ptr = slow_ptr->next;  // Move the slow pointer one step forward
        fast_ptr = fast_ptr->next->next;  // Move the fast pointer two steps forward

        // If the two pointers meet, the list has a cycle
        if (slow_ptr == fast_ptr) {
            return true;
        }
    }

    // If the fast pointer reaches the end of the list, the list doesn't have a cycle
    return false;
}

