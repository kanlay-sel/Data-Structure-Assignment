#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void buildMinHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(arr, n, i);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%3d ", arr[i]);
        if ((i + 1) % 10 == 0) printf("\n");
    }
    printf("\n");
}

int main() {
    int maxHeapArray[SIZE];
    int minHeapArray[SIZE];

    srand(time(NULL));

    // Fill arrays with random numbers
    for (int i = 0; i < SIZE; i++) {
        int r = rand() % 1000;
        maxHeapArray[i] = r;
        minHeapArray[i] = r;
    }

    // Build and display Max Heap
    buildMaxHeap(maxHeapArray, SIZE);
    printf("MAX HEAP:\n");
    printArray(maxHeapArray, SIZE);

    printf("\n----------------------------------\n\n");

    // Build and display Min Heap
    buildMinHeap(minHeapArray, SIZE);
    printf("MIN HEAP:\n");
    printArray(minHeapArray, SIZE);

    return 0;
}
