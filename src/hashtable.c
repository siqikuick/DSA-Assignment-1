#include <stdio.h>
#include <stdlib.h>

#include "hashtable.h"

HashTable* create_hash_table() {
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    table->hash_node = (HashNode**)malloc(sizeof(HashNode*) * MAX_SIZE);
    for (int i = 0; i < MAX_SIZE; i++) {
        table->hash_node[i] = NULL;
    }

    return table;
}

unsigned int hash(int key) {
    unsigned int hash = 1234;
    hash = ((hash << 5) + hash) + key;
    return hash % MAX_SIZE;
}

void hash_insert(HashTable* table, int key, ListNode* value) {
    unsigned int hash_key = hash(key);
    HashNode* prev_node = table->hash_node[hash_key];
    if (prev_node != NULL) {
        HashNode* new_node = (HashNode*)malloc(sizeof(HashNode));
        new_node->value = value;
        new_node->next = prev_node;
        table->hash_node[hash_key] = new_node;
    }
    else {
        HashNode* new_node = (HashNode*)malloc(sizeof(HashNode));
        new_node->value = value;
        new_node->next = NULL;
        table->hash_node[hash_key] = new_node;
    }
}

ListNode* hash_get(HashTable* table, int key) {
    unsigned int hash_key = hash(key);
    if (table->hash_node[hash_key] != NULL) {
        return table->hash_node[hash_key]->value;
    }
    else {
        return NULL;
    }
}

void hash_delete(HashTable* table, int key) {
    unsigned int hash_key = hash(key);
    if (table->hash_node[hash_key] != NULL) {
        free(table->hash_node[hash_key]);
        table->hash_node[hash_key] = NULL;
    }
    else {
        printf("Key not found\n");
    }
}

void _print_hash_table(HashTable* table) {
    for (int i = 0; i < MAX_SIZE; i++) {
        if (table->hash_node[i] != NULL) {
            printf("Hash key: %d, Value: %d\n", i, table->hash_node[i]->value->value);
        }
    }
}

void destroy_hash_table(HashTable* table) {
    for (int i = 0; i < MAX_SIZE; i++) {
        if (table->hash_node[i] != NULL) {
            free(table->hash_node[i]);
        }
    }
    free(table->hash_node);
    free(table);
}