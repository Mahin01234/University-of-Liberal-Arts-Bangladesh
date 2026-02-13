#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int mergeSteps , insertionSteps ;
void merge (char arr[], int left, int mid, int right)
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
void insertionSort(char arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        insertionSteps++ ;
        char key = arr[i] ;
        int j = i - 1 ;
        while (j >= 0 && (int)arr[j] < (int)key)
        {
            insertionSteps++ ;
            arr[j + 1] = arr[j] ;
            j-- ;
        }
        arr[j + 1] = key ;
    }
}
void printArray(char arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%c ", arr[i]) ;
    }
    printf("\n") ;
}
void copyArray(char source[], char dest[], int n)
{
    for (int i = 0; i < n; i++)
    {
        dest[i] = source[i] ;
    }
}
void reverseArray(char arr[], int n)
{
    int left = 0, right = n - 1 ;
    while (left < right)
    {
        char temp = arr[left] ;
        arr[left] = arr[right] ;
        arr[right] = temp ;
        left++ ;
        right-- ;
    }
}
void testArray(char input[] , int n , char title[])
{
    char arrMerge[n] , arrInsertion[n] ;
    copyArray(input , arrMerge, n) ;
    copyArray(input , arrInsertion, n) ;
    mergeSteps = 0 ;
    insertionSteps = 0 ;
    mergeSort(arrMerge, 0, n - 1) ;
    insertionSort(arrInsertion, n) ;
    printf("\n===== %s =====\n", title) ;
    printf("Original Array: ") ;
    printArray(input, n) ;
    printf ("Merge Sort Result: ") ;
    printArray(arrMerge, n) ;
    printf("Merge Sort Steps: %d\n", mergeSteps) ;
    printf("Insertion Sort Result: ") ;
    printArray(arrInsertion, n) ;
    printf("Insertion Sort Steps: %d\n", insertionSteps) ;
    if (mergeSteps < insertionSteps)
    {
        printf("Best Performance: Merge Sort\n");
    }
    else if (insertionSteps < mergeSteps)
    {
        printf("Best Performance: Insertion Sort\n");
    }
    else
    {
        printf("Both performed equally.\n");
    }
}
int main()
 {
    char name[100] ;
    printf("Enter my name: ") ;
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
                char temp = array2[i] ;
                array2[i] = array2[j] ;
                array2[j] = temp ;
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
