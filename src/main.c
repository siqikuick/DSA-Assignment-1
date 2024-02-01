#include <stdio.h>
#include "adt_list.h"
#include "hashtable.h"

int main(int argc, char const* argv[])
{
    List* list = adt_new();

    // Append 10 nodes to the list
    for (int i = 0; i < 10; i++) {
        adt_append(list, i);
    }

    printf("List after appending 10 nodes:\n"); // Desired output: 9 8 7 6 5 4 3 2 1 0
    adt_print(list);

    // printf("== Debug Hash Table ==\n");
    // _print_hash_table(list->table);

    // Insert a new node after the 3rd node
    adt_insert_after(list, adt_get(list, 3, 3), 48);

    printf("List after inserting a new node after the 3rd node:\n"); // Desired output: 9 8 7 100 6 5 4 3 2 1 0
    adt_print(list);

    // printf("== Debug Hash Table ==\n");
    // _print_hash_table(list->table);

    // Remove the 6th node
    adt_remove(list, 6);

    printf("List after removing the 6th node:\n"); // Desired output: 9 8 7 100 6 4 3 2 1 0
    adt_print(list);

    // printf("== Debug Hash Table ==\n");
    // _print_hash_table(list->table);

    adt_destroy(list);

    return 0;
}
