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
        printf("Error: Index already exists in the list.\n");
        return -1;
    }

    // Insert the node at the specified index
    if (index == 0) {
        node->next = list->head;
        list->head = node;
    }
    else {
        Node* prev = hash_lookup(list->index_table, index - 1);
        if (prev == NULL) {
            printf("Error: Invalid index.\n");
            return -1;
        }
        node->next = prev->next;
        prev->next = node;
    }

    // Update the hashtable with the new index
    insert_hash(list->index_table, index, node);

    list->size++;
    return 0;
}

int adt_remove(List* list, int index)
{
    return 0;
}

int adt_get(List* list, int index)
{
    return 0;
}

void adt_print(List* list)
{
    Node* current = list->head;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }

    printf("Size: %d\n", list->size);
}