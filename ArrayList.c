#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"

const size_t DEFAULT_CAPACITY = 16;

/**
 * Allocates and initializes a new ArrayList with an initial capacity.
 * @param elementSize The size (in bytes) of each element type.
 * @return Pointer to the newly allocated ArrayList.
 */
ArrayList* aLCreate() {
    ArrayList* aL = (ArrayList*)malloc(sizeof(ArrayList));
    if (aL == NULL) {
        printf("Error: ArrayList malloc failed!\n");
        return NULL;
    }

    aL->size = 0;
    aL->capacity = DEFAULT_CAPACITY;

    // Allocate space for 'capacity' elements
    aL->data = (void**)malloc(sizeof(void*) * aL->capacity);
    if (aL->data == NULL) {
        printf("Error: aL->data malloc failed!\n");
        return NULL;
    }

    return aL;
}

/**
 * Returns a pointer to the element at the specified index.
 * @param aL Pointer to the ArrayList.
 * @param index Zero-based index of the element to retrieve.
 * @return Pointer to the requested element, or (void*)-1 on error.
 */
void* aLGet(ArrayList* aL, size_t index) {
    if (aL == NULL) {
        printf("Error: input array is null!\n");
        return (void*)-1;
    }

    if (index >= aL->size) {
        printf("Error: accessing illegal index!\n");
        return (void*)-1;
    }

    // Calculate the byte offset to the desired element
    return aL->data[index];
}

/**
 * Sets a certain index of the ArrayList to a given value.
 * @param aL Pointer to the ArrayList.
 * @param index Zero-based index of the element to retrieve.
 * @param data Data given to set the index of the ArrayList to.
 * @return Pointer to the requested element, or (void*)-1 on error.
 */
void aLSet(ArrayList* aL, size_t index, void* data) {
    if (aL == NULL) {
        printf("Error: input array is null!\n");
        return;
    }

    if (index >= aL->size) {
        printf("Error: accessing illegal index!\n");
        return;
    }

    // Example: if data was stored directly (not pointers), we'd need memcpy
    memcpy((char *)aL->data + (index * sizeof(void*)), data, sizeof(void*));
}

/**
 * Appends a new element to the end of the ArrayList, reallocating if necessary.
 * @param aL Pointer to the ArrayList.
 * @param data Pointer to the element to be appended.
 */
void aLAppend(ArrayList* aL, void* data) {
    if (aL == NULL || data == NULL) {
        printf("Error: accessing illegal parameters!\n");
        return; // changed to 'return;' to match void function
    }
    
    // Check if we need to expand capacity
    if (aL->capacity == aL->size) {
        int newCapacity = aL->capacity * 2;
        void* newAL = realloc(aL->data, newCapacity * sizeof(void*));
        if (newAL == NULL) {
            printf("Error: new array is null!\n");
            return; // changed to 'return;' to match void function
        }
        aL->data = newAL;
        aL->capacity = newCapacity;
    }

    // Copy the new element into the next free slot
    aL->data[aL->size] = data;
    aL->size++;
}

/**
 * Returns the current number of elements in the ArrayList.
 * @param aL Pointer to the ArrayList.
 * @return The number of elements, or (size_t)-1 on error.
 */
size_t aLGetSize(ArrayList* aL) {
    if (aL == NULL) {
        printf("Error: input array is null!\n");
        return (size_t)-1;
    }
    return aL->size;
}

/**
 * Frees the memory allocated for the ArrayList, including its data.
 * @param aL Pointer to the ArrayList to be destroyed.
 */
void aLDestroy(ArrayList* aL) {
    if (aL == NULL) {
        printf("Error: attempting to destroy null ArrayList!\n");
        return;
    }

    // Free the internal data array
    free(aL->data);

    // Free the ArrayList struct itself
    free(aL);
}