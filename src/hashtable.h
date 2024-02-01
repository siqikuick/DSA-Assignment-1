#ifndef HASHTABLE_H
#define HASHTABLE_H
#define MAX_SIZE 100

#include "nodes.h"

/**
 * @brief Creates a new hash table.
 */
HashTable* create_hash_table();

/**
 * @brief Inserts a key-value pair into the hash table.
 *
 * @param table The hash table to insert into.
 * @param key The key of the pair.
 * @param value The value of the pair.
 */
void hash_insert(HashTable* table, int key, ListNode* value);

/**
 * @brief Retrieves the value associated with the given key from the hash table.
 *
 * @param table The hash table to search in.
 * @param key The key to search for.
 * @return A pointer to the value associated with the key, or NULL if not found.
 */
ListNode* hash_get(HashTable* table, int key);

/**
 * @brief Deletes the key-value pair with the given key from the hash table.
 *
 * @param table The hash table to delete from.
 * @param key The key of the pair to delete.
 */
void hash_delete(HashTable* table, int key);

/**
 * @brief Destroys the hash table and frees the allocated memory.
 *
 * @param table The hash table to destroy.
 */
void destroy_hash_table(HashTable* table);

/**
 * @brief Prints the contents of the hash table.
 *
 * @param table The hash table to print.
 */
void _print_hash_table(HashTable* table);
#endif