#ifndef ADT_LIST_H
#define ADT_LIST_H

#define LIST_NULL ((int) -1)
#define MAX_SIZE 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
    Node* tail;
    int size;
    struct Node* tailPointers[MAX_SIZE];
} List;

/**
 * Create a new list
 * @return the new list
*/
List adt_new();

/**
 * Retrieve element at position i (O(1) time)
 * @param list the list to retrieve from
 * @param index the index to retrieve from
 * @return the element at position i
*/
int adt_get(List list, int index);

/**
 * Insert element at position i (O(1) time)
 * @param list the list to insert into
 * @param data the data to insert
 * @return 0 if successful, -1 if not
*/
int adt_insert(List list, int position, int data);

/**
 * Remove element at position i (O(1) time)
 * @param list the list to remove from
 * @param index the index to remove from
 * @return 0 if successful, -1 if not
*/
int adt_remove(List list, int index);

#endif