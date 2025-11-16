#include<stdio.h>
int main()
{
    int arr[100] ; 
    int n , temp ; 


    printf("enter the num : " ) ; 
    scanf("%d" , &n) ; 



    printf("enter the %d integer : " , n ) ; 
    


    for (int i=0 ; i<n ; i++) 
    {
        scanf("%d" , &arr[i]) ; 
    }



    for(int i=0 ; i<n-1 ; i++) 
    {
        int min = i ; 




        for(int j=i+1 ; j<n ; j++) 
        {



            // ascending order  '<'  
            // descending order '>'

            
            if ( arr[j] < arr[min] ) 
            {

                min = j ; 
            }


        }




        if (min != i) 
        {
            temp = arr[i] ; 
            arr[i] = arr[min] ; 
            arr[min] = temp ; 
        }


    }




    printf ("enter the assending : " ) ; 



    for(int i=0 ; i<n ; i++) 
    {
        printf("%d " , arr[i]) ; 
    }




    return 0 ; 
}
