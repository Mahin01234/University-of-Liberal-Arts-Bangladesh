#include<stdio.h>


void  Insertion_sort (int arr[] , int n) 
{
    int step = 0 , index; 


    for (int i=0 ; i<n ; i++) 
    {
        index = arr[i] ; 
        int j = i - 1 ; 
        step++ ; 
        
        
        while (j >= 0 && arr[j] < index) 
        {
            step++ ; 
            arr[j+1] = arr[j] ; 
            step++ ; 
            j-- ; 
        } 


        arr[j + 1] = index ; 
        step++ ; 
    }

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
    Insertion_sort (array1 , n) ; 
    
    printf ("Ascending order : \n") ; 
    Insertion_sort (array2 , n) ; 

    printf ("Descending order : \n") ; 
    Insertion_sort (array3 , n) ; 


    return 0 ; 
}