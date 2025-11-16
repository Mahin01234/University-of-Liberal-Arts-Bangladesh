#include<stdio.h> 


void swap (int *a , int *b) 
{

    int temp = *a ; 
    *a = *b ; 
    *b = temp ; 
}



void MaxHeapify (int arr[], int n , int i) 
{
    int Largest = i ; 
    int l = (2 * i) + 1 ; 
    int r = (2 * i) + 2 ; 




    if (l < n && arr[l] > arr[Largest] ) 
    {
        Largest = l ; 
    }




    if (r < n && arr[r] > arr[Largest] )
    {
        Largest = r ; 
    }
        



    if (Largest != i) 
    {
         
        swap ( &arr[i] , &arr[Largest] ) ; 
        MaxHeapify (arr , n , Largest) ; 
    }
    

}




void HeapSort (int arr[] , int n )
{


    for(int i = n / 2 - 1 ; i >= 0 ; i--) 
    {
        MaxHeapify (arr , n , i) ; 
    }



    for(int i = n - 1 ; i > 0 ; i--) 
    {
        // Descending 
        swap (&arr[i] , &arr[0] ) ;
        MaxHeapify(arr, i, 0) ;
    }
    


}




   
int main() 
{
    int n ; 
    int arr[100] ; 



    printf("enter the element : " ) ; 
    scanf("%d" , &n) ; 



    printf("enter the %d integer : " , n ) ; 


    for(int i=0 ; i<n ; i++) 
    {
        scanf("%d" , &arr[i] ) ;   
    }




    HeapSort (arr , n ) ; 




    // printf("The sorted array in accending : " ) ; 
    // for(int i=0 ; i<n ; i++) 
    // {
    //     printf ("%d " , arr[i] ) ; 
    // }





    printf("The sorted array in decending : " ) ; 
    for(int i = n - 1  ; i >= 0 ; i--) 
    {
        printf ("%d " , arr[i] ) ; 
    }


    
    return 0 ; 
}