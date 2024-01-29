#include <stdio.h>
#include "adt_list.h"

int main(int argc, char const* argv[])
{
    List list = adt_new();

    for (int i = 0; i < 100; i++) {
        if (adt_insert(list, i, i) == 0) {
            printf("Inserted %d\n", i);
        }
        else {
            printf("Failed to insert %d\n", i);
        }
    }

    printf("List size: %d\n", list.size);

    for (Node* node = list.head; node != NULL; node = node->next) {
        printf("%d->", node->data);
    }

    return 0;
}
