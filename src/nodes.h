#ifndef NODES_H
#define NODES_H

// Common file shared between adt and hash_table

typedef struct list_node {
    int position;
    int value;
    struct list_node* next;
} ListNode;

typedef struct hash_node {
    ListNode* value;
    struct hash_node* next;
} HashNode;

typedef struct {
    HashNode** hash_node;
} HashTable;

typedef struct {
    ListNode* head;
    int size;
    HashTable* table;
} List;

#endif