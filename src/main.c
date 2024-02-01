#include <stdio.h>
#include "adt_list.h"
#include "hashtable.h"

int main(int argc, char const* argv[])
{
    List* list = adt_new();

    // Insertion test, desired output: 1 2 3 4 5, Size: 5
    printf("Insertion test:\n");

    adt_insert(list, 0, 1);
    adt_insert(list, 1, 2);
    adt_insert(list, 2, 3);
    adt_insert(list, 3, 4);
    adt_insert(list, 4, 5);

    adt_print(list);

    // Removal test, desired output: 2 4 5, Size: 3
    printf("\nRemoval test:\n");

    adt_remove(list, 0);
    adt_remove(list, 1);

    adt_print(list);

    // Injection test, desired output: 2 48 49 4 5, size: 5
    // TOFIX: Test failed with NULLs returned
    printf("\nInjection test:\n");

    adt_insert(list, 1, 48);
    adt_insert(list, 2, 49);

    adt_print(list);

    adt_destroy(list);

    List* list2 = adt_new();

    printf("\nEmpty list test:\n"); // Desired output: Size: 0

    adt_print(list2);

    printf("\nEmpty removal test:\n"); // Desired output: Error: Invalid index.

    adt_remove(list2, 0);

    printf("\nEmpty injection test:\n"); // Desired output: Error: Invalid index.

    adt_insert(list2, 4, 1);

    adt_destroy(list2);

    return 0;
}
