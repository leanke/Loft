#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int size;
    int capacity;
} DynamicArray;

// Insert a value into the dynamic array
void arrayInsert(DynamicArray* arr, int val) {
    if (arr->size >= arr->capacity) {
        int newCap = arr->capacity * 2;
        int* newData = (int*)realloc(arr->data, newCap * sizeof(int));
        if (!newData) return;
        arr->data = newData;
        arr->capacity = newCap;
    }
    arr->data[arr->size++] = val;
}
