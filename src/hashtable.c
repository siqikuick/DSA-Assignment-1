#include <stdio.h>
#include <stdlib.h>

#include "hashtable.h"

HashTable* create_hash_table()
{
    HashTable* table = malloc(sizeof(HashTable)); // Allocate memory for the table
    table->size = 0;
    table->table = malloc(sizeof(Node*) * MAX_SIZE);
    return table;
}

void insert_hash(HashTable* table, int key, Node* value)
{
    int index = key % MAX_SIZE; // Get the index of the key, mod max size to prevent overflow
    table->table[index] = value;
    table->size++;
}

Node* hash_lookup(HashTable* table, int key)
{
    int index = key % MAX_SIZE; // Get the index of the key, mod max size to prevent overflow
    if (table->table[index] == NULL) {
        return NULL;
    }
    return table->table[index];
}

void remove_hash(HashTable* table, int key)
{
    int index = key % MAX_SIZE; // Get the index of the key, mod max size to prevent overflow
    table->table[index] = NULL;
    table->size--;
}