#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long comparisons = 0;

void merge(int arr[], int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[start + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = start;

    while (i < n1 && j < n2) {
        comparisons++;   // comparison counted here
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

void generateRandomArray(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++)
        arr[i] = rand();
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    generateRandomArray(arr, n);

    printf("Original array:\n");
    printArray(arr, n);

    comparisons = 0;
    clock_t start = clock();
    mergeSort(arr, 0, n - 1);
    clock_t end = clock();

    printf("Sorted array:\n");
    printArray(arr, n);

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Number of comparisons: %lld\n", comparisons);
    printf("Time taken to sort: %f seconds\n", time_taken);

    return 0;
}
