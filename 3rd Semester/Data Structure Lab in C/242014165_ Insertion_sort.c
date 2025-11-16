#include<stdio.h>

void  Insertion_Sort (int a[] , int n)
{
    int i , j , key ;

    for (j=1 ; j<n ; j++)
    {
        key = a[j] ;
        i = j - 1 ;


        while (i >= 0 && a[i] > key )
        {
            a[i + 1] = a[i] ;
            i = i - 1 ;
        }
        a[i + 1] = key ;
    }

}





int main()
{

    int n , m ;
    printf("element size : ") ;
    scanf("%d" , &n) ;

    int a[n] ;

    printf("enter the array : ") ;

    for (int i=0 ; i<n ; i++)
    {
        scanf("%d" , &a[i]) ;
    }




    Insertion_Sort (a , n) ;
    printf("Insertion_Sort element : ") ;
    for(int i=0 ; i<n ; i++)
    {
        printf("%d " , a[i]) ;
    }

    return 0;

}
