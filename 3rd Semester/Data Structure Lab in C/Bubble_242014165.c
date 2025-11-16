#include<stdio.h>


void bubble_sort (int a[] , int n)
{
    int i , j ;
    for (int i=0 ; i<n-1 ; i++)
    {
       for (int j=0 ; j<n-i-1 ; j++ )
        {
           if (a[j] > a[j + 1] )
           {
               int swap = a[j] ;
               a[j] = a[j + 1] ;
               a[j+1] = swap ;
           }
       }
    }
}




int main()
{
    int n , m ;
    printf("enter the arr size : ") ;
    scanf("%d" , &n) ;




    int a[n] ;
    printf("enter the arr num : ") ;

    for (int k=0 ; k<n ; k++)
    {
        scanf("%d" , &a[k] ) ;
    }


     bubble_sort (a , n) ;
     printf("element the bubble : ") ;


     for (int k=0 ; k<n ; k++)
     {
         printf("%d " , a[k]) ;
     }


     return 0 ;
}
