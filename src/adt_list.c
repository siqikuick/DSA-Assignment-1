#include <stdio.h>
#include <stdlib.h>

#include "adt_list.h"
#include "hashtable.h"

List* adt_new() {
    List* list = (List*)malloc(sizeof(List));
    list->head = NULL;
    list->size = 0;
    list->table = create_hash_table();

    return list;
}

ListNode* adt_append(List* list, int value) {
    ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
    new_node->value = value;
    new_node->next = list->head;
    if (list->size == 0) {
        new_node->position = 0; // Set position to 0
    }
    else {
        new_node->position = list->head->position + 1; // Increment position by 1
    }

    list->head = new_node;

    hash_insert(list->table, new_node->position + new_node->value, new_node);

    list->size++;

    return new_node;
}

ListNode* adt_insert_after(List* list, ListNode* node, int value) {
    if (list->head == NULL || list->size == 0) {
        printf("List is empty\n");
        return NULL;
    }

    if (node == NULL) {
        printf("Node is NULL\n");
        return NULL;
    }

    ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
    new_node->value = value;
    new_node->next = node->next;
    new_node->position = node->position + 1; // Increment the position by 1 using the old position
    // drawback of this approach is that subsequent nodes are not updated without iterating through the list

    node->next = new_node;

    hash_insert(list->table, new_node->position + new_node->value, new_node);

    list->size++;

    return new_node;
}

void adt_remove(List* list, int position) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (position == 0) {
        ListNode* temp = list->head;
        list->head = list->head->next;
        hash_delete(list->table, temp->position + temp->value);
        list->size--;
        return;
    }

    ListNode* current = list->head;
    for (int i = 0; current != NULL && i < position - 1; i++) {
        current = current->next;
    }

    if (current == NULL || current->next == NULL) {
        printf("Position not found\n");
        return;
    }

    hash_delete(list->table, current->position + current->value);
    current->next = current->next->next;
    list->size--;
}

ListNode* adt_get(List* list, int position, int value) {
    int key = position + value;

    if (list->table == NULL) {
        printf("Table is NULL\n");
        return NULL;
    }

    ListNode* node = hash_get(list->table, key);
    if (node == NULL) {
        return NULL;
    }

    return node;
}

void adt_print(List* list) {
    ListNode* current = list->head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }

    printf("\nNode positions:\n");

    for (int i = 0; i < MAX_SIZE; i++) {
        ListNode* node = adt_get(list, i, 0);
        if (node != NULL) {
            printf("Node at position %d: %d\n", node->position, node->value);
        }
    }

    printf("\n");
}

void adt_destroy(List* list) {
    ListNode* current = list->head;
    while (current != NULL) {
        ListNode* next = current->next;
        free(current);
        current = next;
    }
    destroy_hash_table(list->table);
    free(list);
}