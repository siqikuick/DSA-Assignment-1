#include <stdio.h>
#include "adt_list.h"
#include "hashtable.h"

int main(int argc, char const* argv[])
{
    List* list = adt_new();

    printf("=== Original list ===\n");

    adt_append(list, 10);
    adt_append(list, 20);
    adt_append(list, 30);

    adt_print(list);

    printf("### Tests ###\n\n");

    ListNode* node = adt_get(list, 1, 20);
    adt_insert_after(list, node, 25);

    printf("=== List after inserting 25 after 20 ===\n");
    adt_print(list);

    adt_remove(list, 1);

    printf("=== List after removing element 1 (25) ===\n");
    adt_print(list);

    adt_remove(list, 0);
    adt_remove(list, 0);

    printf("=== List after removing element 2x 0 ===\n");
    adt_print(list);

    adt_destroy(list);
    printf("Test complete...\n");

    printf("### Edge case tests ###\n\n");

    List* edge_list = adt_new();

    printf("=== Empty list print ===\n");
    adt_print(edge_list);

    printf("=== List after removing element from empty list ===\n");
    adt_remove(edge_list, 0);

    adt_destroy(edge_list);

    return 0;
}
