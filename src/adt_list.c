#include <stdio.h>
#include <stdlib.h>

#include "adt_list.h"

List* adt_new() {
    List* list = malloc(sizeof(List));
    list->size = 0;
    list->head = NULL;
    list->index_table = create_hash_table();

    return list;
}

int adt_insert(List* list, int index, int data) {
    Node* node = malloc(sizeof(Node*));
    node->data = data;
    node->next = NULL;

    // Check if the index already exists in the hashtable
    if (hash_lookup(list->index_table, index) != NULL) {
        // If it does, split the list at that index and insert the node
        Node* prev = hash_lookup(list->index_table, index - 1);
        // Cautionary check
        if (prev == NULL) {
            printf("Error: Invalid index.\n");
            return -1;
        }
        else {
            node->next = prev->next; // Move back the pointer of the node at the index
            prev->next = node; // Set the pointer of the node before the index to the new node

            // Update the hashtable with the new index
            insert_hash(list->index_table, index, node);

            list->size++;
            return 0;
        }
    }

    // Insert the node at the specified index
    if (index == 0) { // If the index is 0, set the head to the new node
        node->next = list->head;
        list->head = node;
    }
    else {
        Node* prev = hash_lookup(list->index_table, index - 1);
        if (prev == NULL) {
            printf("Error: Invalid index.\n");
            return -1;
        }
        node->next = prev->next; // Move back the pointer of the node at the index
        prev->next = node; // Set the pointer of the node before the index to the new node
    }

    // Update the hashtable with the new index
    insert_hash(list->index_table, index, node);

    list->size++;
    return 0;
}

int adt_remove(List* list, int index)
{
    if (hash_lookup(list->index_table, index) == NULL) {
        printf("Error: Invalid index.\n");
        return -1;
    }

    Node* node = hash_lookup(list->index_table, index); // The node to remove
    Node* prev = hash_lookup(list->index_table, index - 1); // The node before the node to remove

    Node* temp = node->next;

    // If the node to remove is the head
    if (index == 0) {
        list->head = temp;
    }
    else {
        prev->next = temp;
    }

    // Update the hashtable
    remove_hash(list->index_table, index);
    // Free the node
    free(node);
    // Update the index of the nodes after the removed node, I can't really think
    // of a way to do this without iterating through the list, so this is O(n)
    Node* current = temp;
    while (current != NULL) {
        remove_hash(list->index_table, index + 1);
        insert_hash(list->index_table, index, current);
        current = current->next; // Move to the next node
        index++;
    }

    list->size--;

    return 0;
}

int adt_get(List* list, int index)
{
    if (hash_lookup(list->index_table, index) == NULL) {
        printf("Error: Index here is NULL.\n");
        return LIST_NULL;
    }
    return hash_lookup(list->index_table, index)->data;
}

void adt_print(List* list)
{
    for (int i = 0; i < list->size; i++) {
        printf("[Element at %d] %d\n", i, adt_get(list, i));
    }
    printf("\nList size: %d\n\n", list->size);
}