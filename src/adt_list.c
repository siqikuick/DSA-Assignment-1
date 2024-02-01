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

    // Check if the list is empty and the index is > 0
    if (list->size < index || index < 0) {
        printf("Error: Invalid index.\n");
        return LIST_INDEX_INVALID;
    }

    // Check if the index is valid
    if (index < 0 || index > list->size) {
        printf("Error: Invalid index.\n");
        return LIST_INDEX_INVALID;
    }

    // If the list is empty
    if (list->size == 0) {
        list->head = node;
    }
    else {
        Node* prev = hash_lookup(list->index_table, index - 1);
        node->next = prev->next;
        prev->next = node;
    }

    // Update the hashtable
    insert_hash(list->index_table, index, node);
    // Update the index of the nodes after the inserted node, I can't really think
    // of a way to do this without iterating through the list, so this is O(n)
    Node* current = node->next;
    while (current != NULL) {
        remove_hash(list->index_table, index + 1);
        insert_hash(list->index_table, index + 1, current);
        current = current->next; // Move to the next node
        index++;
    }

    list->size++;

    return LIST_SUCCESS;
}

int adt_remove(List* list, int index)
{
    if (list->size == 0) {
        printf("Error: List is empty.\n");
        return LIST_NULL;
    }

    if (hash_lookup(list->index_table, index) == NULL) {
        printf("Error: Invalid index.\n");
        return LIST_INDEX_INVALID;
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

    return LIST_SUCCESS;
}

int adt_get(List* list, int index)
{
    if (list->size == 0) {
        printf("Error: List is empty.\n");
        return LIST_NULL;
    }

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

void adt_destroy(List* list)
{
    Node* current = list->head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    destroy_hash_table(list->index_table);
    free(list);
}