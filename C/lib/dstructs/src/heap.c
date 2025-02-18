#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int items[100];
} MinHeap;

// Helper function to swap two elements
static void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Moves the element at index up to maintain heap property
static void heapifyUp(MinHeap* h, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (h->items[index] < h->items[parent]) {
            swap(&h->items[index], &h->items[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

// Moves the element at index down to maintain heap property
static void heapifyDown(MinHeap* h, int index) {
    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < h->size && h->items[left] < h->items[smallest]) {
            smallest = left;
        }
        if (right < h->size && h->items[right] < h->items[smallest]) {
            smallest = right;
        }
        if (smallest != index) {
            swap(&h->items[index], &h->items[smallest]);
            index = smallest;
        } else {
            break;
        }
    }
}

// Insert a new value into the min-heap
void heapInsert(MinHeap* h, int val) {
    if (h->size == 100) return;
    h->items[h->size] = val;
    heapifyUp(h, h->size);
    h->size++;
}

// Extract the min value from the heap
int extractMin(MinHeap* h) {
    if (h->size == 0) return -1;
    int minVal = h->items[0];
    h->items[0] = h->items[h->size - 1];
    h->size--;
    heapifyDown(h, 0);
    return minVal;
}
