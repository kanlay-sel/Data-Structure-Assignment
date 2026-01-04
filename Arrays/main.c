#include <stdio.h>
#include <stdlib.h>

void printArray(int* array, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

void reverseArray(int* array, int size) {
    int start = 0;
    int end = size - 1;
    while (start < end) {
        int temp = array[start];
        array[start] = array[end];
        array[end] = temp;
        start++;
        end--;
    }
}

int* addElement(int* oldArray, int size, int newElement) {
    int* newArray = (int*)malloc((size + 1) * sizeof(int));
    for (int i = 0; i < size; i++) {
        newArray[i] = oldArray[i];
    }
    newArray[size] = newElement;
    return newArray;
}

int* removeElement(int* oldArray, int size, int indexToRemove) {
    if (indexToRemove < 0 || indexToRemove >= size) return NULL;

    int* newArray = (int*)malloc((size - 1) * sizeof(int));
    int j = 0;

    for (int i = 0; i < size; i++) {
        if (i == indexToRemove) continue;
        newArray[j++] = oldArray[i];
    }
    return newArray;
}

int main() {
    int array1[] = {1, 2, 3, 4, 5};
    int size1 = 5;

    printf("Original Array 1: ");
    printArray(array1, size1);

    reverseArray(array1, size1);
    printf("Reversed Array: ");
    printArray(array1, size1);

    printf("-------------------------\n");

    int array2[] = {10, 20, 30};
    int size2 = 3;

    printf("Original Array 2: ");
    printArray(array2, size2);

    int* extendedArray = addElement(array2, size2, 40);
    int newSize = size2 + 1;

    printf("After Adding 40: ");
    printArray(extendedArray, newSize);
    
    return 0;
}
