#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long comparisons = 0;   // comparison counter

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void generateRandomArray(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++)
        arr[i] = rand();
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        comparisons++;                 // comparison counted here
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    generateRandomArray(arr, n);

    comparisons = 0;   // initialize counter

    quickSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    printArray(arr, n);

    printf("Number of comparisons: %lld\n", comparisons);

    return 0;
}
