#include <stdio.h>
#include <string.h>
int quickSteps = 0 ;
int mergeSteps = 0 ;
void swap(char *a, char *b)
{
    char temp = *a ;
    *a = *b ;
    *b = temp ;
}
int partition(char arr[], int low, int high)
{
    quickSteps++ ;
    char pivot = arr[high] ;
    int i = low - 1 ;
    for (int j = low; j < high; j++)
    {
        quickSteps++ ;
        if ((int)arr[j] > (int)pivot)
        {
            i++ ;
            swap(&arr[i], &arr[j]) ;
            quickSteps++ ;
        }
    }
    swap(&arr[i + 1], &arr[high]) ;
    quickSteps++ ;
    return i + 1 ;
}
void quickSort(char arr[], int low, int high)
{
    quickSteps++ ;
    if (low < high)
    {
        int pi = partition(arr, low, high) ;
        quickSort(arr, low, pi - 1) ;
        quickSort(arr, pi + 1, high) ;
    }
}
void merge(char arr[], int left, int mid, int right)
{
    mergeSteps++ ;
    int n1 = mid - left + 1 ;
    int n2 = right - mid ;
    char L[n1], R[n2] ;
    for (int i = 0; i < n1; i++)
    {
        mergeSteps++ ;
        L[i] = arr[left + i] ;
    }
    for (int j = 0; j < n2; j++)
    {
        mergeSteps++ ;
        R[j] = arr[mid + 1 + j] ;
    }
    int i = 0, j = 0, k = left ;
    while (i < n1 && j < n2)
    {
        mergeSteps++ ;
        if ((int)L[i] > (int)R[j])
        {
            arr[k++] = L[i++] ;
        }
        else
        {
            arr[k++] = R[j++] ;
        }
    }
    while (i < n1)
    {
        mergeSteps++ ;
        arr[k++] = L[i++] ;
    }
    while (j < n2)
    {
        mergeSteps++ ;
        arr[k++] = R[j++] ;
    }
}
void mergeSort(char arr[], int left, int right)
{
    mergeSteps++ ;
    if (left < right)
    {
        int mid = (left + right) / 2 ;
        mergeSort(arr, left, mid) ;
        mergeSort(arr, mid + 1, right) ;
        merge(arr, left, mid, right) ;
    }
}
void printArray(char arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%c ", arr[i]) ;
    }
    printf("\n");
}
void copyArray(char source[], char dest[], int n)
{
    for (int i = 0 ; i < n ; i++)
    {
        dest[i] = source[i] ;
    }
}
void reverseArray(char arr[] , int n)
{
    int l = 0, r = n - 1 ;
    while (l < r)
    {
        swap(&arr[l], &arr[r]) ;
        l++ ;
        r-- ;
    }
}
void testArray(char input[], int n, char title[])
{
    char quickArr[n], mergeArr[n] ;
    copyArray(input, quickArr, n) ;
    copyArray(input, mergeArr, n) ;
    quickSteps = 0 ;
    mergeSteps = 0 ;
    quickSort(quickArr, 0, n - 1) ;
    mergeSort(mergeArr, 0, n - 1) ;
    printf("\n===== %s =====\n", title) ;
    printf("Original Array: ") ;
    printArray(input, n) ;
    printf("Quick Sort Result: ") ;
    printArray(quickArr, n) ;
    printf("Quick Sort Steps: %d\n", quickSteps) ;
    printf("Merge Sort Result: ") ;
    printArray(mergeArr, n) ;
    printf("Merge Sort Steps: %d\n", mergeSteps) ;
    if (quickSteps < mergeSteps)
    {
        printf("Best Performance: Quick Sort\n") ;
    }
    else if (mergeSteps < quickSteps)
    {
        printf("Best Performance: Merge Sort\n") ;
    }
    else
    {
        printf("Both performed equally.\n") ;
    }
}
int main()
{
    char name[100] ;
    printf("Enter my name : ") ;
    scanf("%s", name) ;
    int n = strlen(name) ;
    char array1[n] ;
    char array2[n] ;
    char array3[n] ;
    copyArray(name, array1, n) ;
    copyArray(array1, array2, n) ;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((int)array2[i] > (int)array2[j])
            {
                swap(&array2[i], &array2[j]) ;
            }
        }
    }
    copyArray(array2, array3, n) ;
    reverseArray(array3, n) ;
    testArray(array1, n, "Original Name Array") ;
    testArray(array2, n, "Ascending Order Array") ;
    testArray(array3, n, "Descending Order Array") ;
    return 0 ;
}
