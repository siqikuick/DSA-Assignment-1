#ifndef HASHTABLE_H
#define HASHTABLE_H
#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct {
    int size;
    Node** table;
} HashTable;

/**
 * @brief Creates a new hash table.
 *
 * @return A pointer to the newly created hash table.
 */
HashTable* create_hash_table();

/**
 * @brief Inserts a key-value pair into the hash table.
 *
 * @param table The hash table to insert into.
 * @param key The key of the pair.
 * @param value The value of the pair.
 */
void insert_hash(HashTable* table, int key, Node* value);

/**
 * @brief Looks up a value in the hash table based on the given key.
 *
 * @param table The hash table to search in.
 * @param key The key to search for.
 * @return A pointer to the value associated with the key, or NULL if not found.
 */
Node* hash_lookup(HashTable* table, int key);

/**
 * @brief Removes a key-value pair from the hash table based on the given key.
 *
 * @param table The hash table to remove from.
 * @param key The key of the pair to remove.
 */
void remove_hash(HashTable* table, int key);

#endif