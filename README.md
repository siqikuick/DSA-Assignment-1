# DSA-Assignment-1

## Question 2

Write a singly linked list ADT implementation that achieves `O(1)` time for insertion and removals at
any location of the linked list. Your implementation should also provide for a `O(1)` time `get(i)` method
where i is the position of the item in the list. The source data must be stored as a singly linked list,
but you can make use of any additional data structure to facilitate the operations. Explain and justify
why your implementation has achieved the stated time complexity requirements.

## Question breakdown

## Building and running

### The simple way

Just run the `build.sh` (Linux) or `build.ps1` (Windows, **untested**) script in the root directory of the project. Ensure that the script has execute permissions.

```bash
    chmod u+x ./build #if the script does not have execute permissions
    ./build.sh
```

### The manual way

Ensure you have `cmake` installed and run the following commands, should be the same for all platforms:

**Linux:**

```bash
    mkdir build
    cd build
    cmake ..
    make
```

The executable will be generated in the `build` directory.
