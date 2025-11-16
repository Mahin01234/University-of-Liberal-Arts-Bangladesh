// *************


#include<stdio.h>
int main()
{
    int n ; 
    int arr[n] ; 
    int data ; 
    int position = -1 ; 
    int found = 0 ; 




    printf ("enter the num : " ) ; 
    scanf ("%d" , &n) ; 




    printf("enter the %d inteager : " , n) ; 




    for (int i=0 ; i<n ; i++) 
    {
        scanf("%d" , &arr[i] ) ; 
    }




    printf ("enter the value : " ) ; 
    scanf ("%d" , &data) ; 



    for(int i=0 ; i<n ; i++) 
    {
        if (arr[i] == data) 
        {
            found = 1 ; 
            position = i ; 
            break; 
        }
    }





    if (found == 1) 
    {
        printf ("Found\n") ;
        printf ("Location : %d\n" , position + 1) ; 
        printf ("Index : %d\n" , position) ; 
    }

    else 
    {
        printf("Not found") ; 
    }


    return 0 ; 
}