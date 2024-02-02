#include <stdio.h>
#include "adt_list.h"
#include "hashtable.h"

int main(int argc, char const* argv[])
{
    List* list = adt_new();

    // Append elements to the list
    adt_append(list, 10);
    adt_append(list, 20);
    adt_append(list, 30);

    // Insert an element after the second node
    ListNode* node = adt_get(list, 1, 20);
    adt_insert_after(list, node, 25);

    // Print the list
    adt_print(list); // Expected output: 30 25 20 10

    // Remove the second node
    adt_remove(list, 1);

    // Print the list again
    adt_print(list); // Expected output: 30 20 10

    // Destroy the list
    adt_destroy(list);

    return 0;
}
