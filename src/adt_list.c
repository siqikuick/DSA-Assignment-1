#include "adt_list.h"
#include <stdio.h>
#include <stdlib.h>

List adt_new()
{
    List list;
    list.head = (Node*)malloc(sizeof(Node));
    list.head->data = LIST_NULL;
    list.head->next = NULL;
    list.tail = list.head;
    list.size = 0;
    list.tailPointers[0] = list.head;

    return list;
}

int adt_insert(List list, int position, int data)
{
    if (position == 0) {
        // Use head pointers
        Node* node = (Node*)malloc(sizeof(Node));
        node->next = list.head;
        node->data = data;
        list.head = node;
        list.size++;

        return 0;
    }
    else {
        // Use tail pointers
        int sublistIndex = position / MAX_SIZE;
        Node* currentTail = list.tailPointers[sublistIndex];
        // Create a new node, insert it between currentTail and its next node.
        Node* node = (Node*)malloc(sizeof(Node));
        node->data = data;

        // Iterate through the remaining position % MAX_SIZE nodes
        // Update currentTail to its next pointer until the desired position is reached.
        for (int i = 0; i < position % MAX_SIZE; i++) {
            if (currentTail->next == NULL) {
                // If the next pointer is NULL, then we have reached the end of the list.
                // Insert the node at the end of the list.
                currentTail->next = node;
                list.tail = node;
                list.size++;

                list.tailPointers[sublistIndex] = node;

                return 0;
            }
            else {
                currentTail = currentTail->next;
            }
        }

        // node->next = currentTail->next; // TO FIX: Segfault here
        // currentTail->next = node;

        // // Update the tail pointer for the sublist.
        // list.tailPointers[sublistIndex] = node;

        // list.size++;

        return 0;
    }
}

int adt_remove(List list, int index)
{
    return 0;
}

int adt_get(List list, int index)
{
    return 0;
}
