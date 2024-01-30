#ifndef ADT_LIST_H
#define ADT_LIST_H

#include "hashtable.h"

#define LIST_NULL ((int) -1)
// #define MAX_SIZE 100

// typedef struct node {
//     int data;
//     struct node* next;
// } Node;

typedef struct {
    Node* head;
    int size;
    HashTable* index_table;
} List;

/**
 * Create a new list
 * @return the new list
*/
List* adt_new();

/**
 * Retrieve element at position i (O(1) time)
 * @param list the list to retrieve from
 * @param index the index to retrieve from
 * @return the element at position i
*/
int adt_get(List* list, int index);

/**
 * Insert element at position i (O(1) time)
 * @param list the list to insert into
 * @param index the position to insert at
 * @param data the data to insert
 * @return 0 if successful, -1 if not
*/
int adt_insert(List* list, int index, int data);

/**
 * Remove element at position i (O(1) time)
 * @param list the list to remove from
 * @param index the index to remove from
 * @return 0 if successful, -1 if not
*/
int adt_remove(List* list, int index);

void adt_print(List* list);

#endif