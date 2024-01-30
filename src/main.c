#include <stdio.h>
#include "adt_list.h"
#include "hashtable.h"

int main(int argc, char const* argv[])
{
    List* list = adt_new();

    adt_insert(list, 0, 1);
    adt_insert(list, 1, 2);
    adt_insert(list, 2, 3);
    adt_insert(list, 1, 4);

    adt_print(list);

    return 0;
}
