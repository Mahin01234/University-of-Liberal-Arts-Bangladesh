#include<stdio.h>
int main()
{
    int arr[100] ; 
    int n ; 



    printf("enter the num : ") ; 
    scanf("%d" , &n) ; 



    printf ("enter the %d integer : " , n ) ; 



    for (int i=0 ; i<n ; i++) 
    {
        scanf("%d" , &arr[i] ) ; 
    }




    for(int i=0 ; i<n ; i++) 
    {
        int temp = arr[i] ; 
        int j = i - 1 ; 



        while (j >= 0 && arr[j] > temp) 
        {
            arr[j + 1] = arr[j] ; 
            j-- ; 
        }
        


        arr[j + 1] = temp ;  

    }


    printf("enter the accending : " ) ; 

    for(int i=0 ; i<n ; i++) 
    {
        printf("%d " , arr[i] ) ; 
    }



    return 0 ; 
}