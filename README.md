# DSA-Assignment-1

This one is a confusing one. I'm not sure if I've done it properly, because I can't exactly achieve `O(1)` time for the `insert` and `remove` operations. I'm gonna try to explain why here.
From what I understand, a singly-linked list cannot achieve `O(1)` time for `insert` and `remove` operations, because inserting or removing an element at a specific position requires traversing the list to find the node at that position.

However, inserting at the head or tail of the list is O(1) time complexity, because we can directly access the head or tail node and insert the new node there.

E.g:
If I want to insert an element at position `i`<br>

```
linkedList = [1, 2, 3, 4, 5]
element = 42

# I want to insert 42 at position 3
# I have to traverse the list to find the node at position 2
# Then I can insert the new node at position 3

[1, 2, 42, 3, 4, 5] Like this

I can split the list at position 2, however this requires traversing the list to find the node at position 2, which is O(n) time complexity

[1, 2] -> [42] -> [3, 4, 5]
    ^
    Splitting at this point requires traversing the list to find the node at position 2

```

## Question 2

Write a singly linked list ADT implementation that achieves `O(1)` time for insertion and removals at
any location of the linked list. Your implementation should also provide for a `O(1)` time `get(i)` method
where i is the position of the item in the list. The source data must be stored as a singly linked list,
but you can make use of any additional data structure to facilitate the operations. Explain and justify
why your implementation has achieved the stated time complexity requirements.

## Question breakdown

### Data Structure

Singly linked list (store actual data within the nodes)

### Operations

    get(i): Retrieve element at position i (O(1) time)
    insert(i, element): Insert element at position i (O(1) time)
    remove(i): Remove element at position i (O(1) time)

### Additional data structures

Indexed Lookup Table

    Maintain a separate hash table mapping positions to node addresses.
    Update the linked list and hash table simultaneously during insert/remove.
    Access nodes directly through hash table keys (positions) for O(1) get(i).

## Building and running

### The simple way

Just run the `build.sh` (Linux) or `build.ps1` (Windows, **untested**) script in the root directory of the project. Ensure that the script has execute permissions.

```bash
    chmod u+x ./build #if the script does not have execute permissions
    ./build.sh
    # or
    ./build.sh --debug #for debug build

    ./build/testing #run the file
```

### The manual way

Ensure you have `cmake` installed and run the following commands, should be the same for all platforms:

**Linux:**

```bash
    mkdir build
    cd build
    cmake ..
    make

    ./testing
```

The executable will be generated in the `build` directory.
