#ifndef ADT_LIST_H
#define ADT_LIST_H

#include "nodes.h"

/**
 * @brief Initialize a new list
*/
List* adt_new();

/**
 * @brief Append a new node to the list
 *
 * @param list The list to append the node to
 * @param value The value of the new node
*/
ListNode* adt_append(List* list, int value);

/**
 * @brief Insert a new node after a given node
 *
 * @param list The list to insert the node into
 * @param node The node to insert the new node after
 * @param value The value of the new node
 * @return The new node that was inserted
*/
ListNode* adt_insert_after(List* list, ListNode* node, int value);

void adt_remove(List* list, int position);

/**
 * @brief Get a node from the list based on its position and value.
 * Position does not start from 0, it starts from 1
 *
 * @param list The list to get the node from
 * @param position The position of the node
 * @param value The value of the node
 * @return The node that was found
*/
ListNode* adt_get(List* list, int position, int value);

/**
 * @brief Print the list
 *
 * @param list The list to print
*/
void adt_print(List* list);

/**
 * @brief Destroy the list
 *
 * @param list The list to destroy
*/
void adt_destroy(List* list);

#endif