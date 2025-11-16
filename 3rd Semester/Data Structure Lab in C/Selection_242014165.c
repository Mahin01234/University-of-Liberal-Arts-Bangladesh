#include<stdio.h>



void Selection_sort (int a[] , int n)
{
    int  min_index , min_value ;
    for (int i=0 ; i<n-1 ; i++)
    {
        min_index = i ;


        for (int j=i+1 ; i<n ; i++)
        {
            if (a[j] < a[min_index] )
            {
                min_index = j ;
            }
        }

        int temp ;

        temp = a[min_index] ;
        a[min_index] = a[i] ;
        a[i]  = temp ;

    }
}





int main()
{

    int n , m ;
    printf("enter the arr size : ") ;
    scanf("%d" , &n) ;



    int a[n] ;
    printf("enter the element : ") ;
    for (int k=0 ; k<n ; i++)
    {
        scanf("%d" , &a[k]) ;
    }



    Selection_sort (a , n) ;
    printf("element : ") ;
    for(int k=0 ; k<n ; k++)
    {
        printf("%d"  , a[i]) ;
    }


    return 0 ;
}
