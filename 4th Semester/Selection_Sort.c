#include<stdio.h>


void Selection_sort (int arr[] , int n , int decending)  
{

    int max_index , step = 0 ; 


    for (int i = 0 ; i < n-1 ; i++) 
    {
        max_index = i ; 


        for (int j = i+1 ; j<n ; j++) 
        {
            step++ ; 

            if (decending) 
            {
            
                if (arr[j] > arr[max_index] ) 
                { 
                    max_index = j ;   
                } 
            }    
            else
            {
                if (arr[j] < arr[max_index] ) 
                {
                    max_index = j ; 
                }
            }
            
            
        } 


        if (max_index != i)
        {
            int temp = arr[i];
            arr[i] = arr[max_index];
            arr[max_index] = temp;
            step++; 
        }

    }

    for (int i=0 ; i<n ; i++) 
    {
        printf ("%d " , arr[i] ) ; 
    }
         
    printf ("\nThe step is : %d\n" , step ) ;
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
    Selection_sort(array1 , n , 1) ; 
    
    printf ("Ascending order : \n") ; 
    Selection_sort(array2 , n , 0) ; 

    printf ("Descending order : \n") ; 
    Selection_sort(array3 , n , 1) ; 


    return 0 ; 
}
