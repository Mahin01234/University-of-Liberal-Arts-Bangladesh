#include<stdio.h>


int step = 0 ; 

void swap (int *a , int *b)  
{
    int temp = *a ; 
    *a = *b ; 
    *b = temp ; 
    step++ ; 
} 


int partition (int arr[] , int low , int high) 
{
    int pivot = arr[high] ; 
    step++ ; 
    int i = low - 1 ; 


    for(int j = low ; j < high ; j++) 
    {
        step++ ; 
        if (arr[j] > pivot) 
        {
            i++ ; 
            swap( &arr[i] , &arr[j] ) ;
        }
    }

 
    swap ( &arr[i + 1] , &arr[high] ) ; 
    return i + 1 ; 
}



void Quick_sort (int arr[] , int low , int high) 
{
    if (low < high) 
    {
        int pi = partition (arr , low , high) ; 
        Quick_sort (arr , low , pi - 1) ; 
        Quick_sort (arr , pi+1 , high) ; 
    }
}



void Quic_Sort (int arr[] , int n) 
{
    step = 0 ; 
    Quick_sort (arr , 0 , n - 1) ; 


    for (int i=0 ; i<n ; i++) 
    {
        printf("%d " , arr[i] ) ;

    }

    printf("\nThe step is : %d\n" , step) ; 
}







int main() 
{
    int n = 9 , array1[9] , array2[9] , array3[9] ;  

    printf("Enter the 9 digit of my id number : ") ; 
    for (int i=0 ; i<n ; i++) 
    {
        scanf("%d" , &array1[i] ) ; 
    }


    for (int i=0 ; i<n ; i++) 
    {
        array2[i] = array1[i] ; 
        array3[i] = array1[i] ; 
    } 


    for (int i=0 ; i < n-1 ; i++) 
    {
        for (int j=i+1 ; j<n ; j++) 
        {
            if (array2[i] > array2[j] ) 
            {
                int temp = array2[i] ; 
                array2[i] = array2[j] ; 
                array2[j] = temp ; 
            }
        }
    } 


    for (int i=0 ; i<n-1 ; i++) 
    {
        for (int j = i+1 ; j<n ; j++) 
        {
            if ( array3[i] < array3[j] ) 
            {
                int temp = array3[i] ; 
                array3[i] = array3[j] ; 
                array3[j] = temp ;  
            }
        }
    } 



    printf ("My id is : ") ; 
    Quic_Sort(array1 , n) ; 
    
    printf ("Ascending order : ") ; 
    Quic_Sort(array2 , n) ; 

    printf ("Descending order : ") ; 
    Quic_Sort(array3 , n) ; 


    return 0 ; 
}
