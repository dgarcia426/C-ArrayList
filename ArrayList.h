#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

/**
 * A generic dynamically resizing array structure.
 */
typedef struct ArrayList {
    size_t size;       // Current number of elements
    size_t capacity;   // Allocated capacity (in terms of how many elements fit)
    void** data;       // Pointer to the underlying data block
} ArrayList;

/**
 * Creates a new ArrayList to hold elements of a specified size.
 * @return Pointer to the newly created ArrayList.
 */
extern ArrayList* aLCreate();

/**
 * Retrieves the element at the specified index.
 * @param aL Pointer to the ArrayList.
 * @param index Zero-based index of the element to retrieve.
 * @return Pointer to the requested element.
 */
extern void* aLGet(ArrayList* aL, size_t index);

/** 
 * Sets the element at the specified index to the given data.
 * (Commented out to show it's not used in the current project.)
 */
extern void aLSet(ArrayList* aL, size_t index, void* data);

/**
 * Appends a new element to the end of the ArrayList.
 * @param aL Pointer to the ArrayList.
 * @param data Pointer to the element to be appended.
 */
extern void aLAppend(ArrayList* aL, void* data);

/**
 * Returns the current number of elements in the ArrayList.
 * @param aL Pointer to the ArrayList.
 * @return The number of elements in the ArrayList.
 */
extern size_t aLGetSize(ArrayList* aL);

/**
 * Frees the memory used by the ArrayList, including its data.
 * @param aL Pointer to the ArrayList to destroy.
 */
extern void aLDestroy(ArrayList* aL);

#endif /* ARRAYLIST_H */ 