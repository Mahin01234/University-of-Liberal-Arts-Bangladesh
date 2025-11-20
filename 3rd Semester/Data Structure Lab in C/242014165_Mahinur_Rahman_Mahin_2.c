#include<stdio.h>



void bubble_sort ( int arr[] , int n , int temp)
{

    for (int i=0 ; i<n-1 ; i++)
    {
        for (int j = 0 ; j< n - i -1 ; j++)
        if (arr[i] > arr[j + 1] )
        {
            temp = arr[i] ;
            arr[i] = arr[j] ;
            arr[j] = temp ;
        }
    }

}



int main()
{

    int arr[10] , n , i, j , search ;


    printf("enter the array : ") ;
    scanf("%d" , &n) ;


    printf ("The element is : ") ;

    for (int i = 0 ; i <= n ; i++ )
    {
       scanf("%d" , &arr[i]) ;
    }


    printf("the value is : ") ;
    scanf("%d" , &search) ;




void bubble_sort ( int arr[] , int n)
{
    int low = 0 , hight = n -1 , mid  ;

    while (low <= hight )

    hight = (low + hight) / 2  ;
    {
         if (arr[mid] == search)
        {

            printf ("found" ,search , mid + 1 ) ;
            break ;

        }
        else if (arr[mid] < search)
        {
           low = mid + 1 ;
           printf ("found" ,search , mid - 1 ) ;
        }
        else
        {
            hight = mid - 1 ;
        }
    }



    printf  ("Arrray is : ") ;
    {
        for (int i=0 ; i < n ; i++)
        {
            printf ("%d" , &arr[i]) ;
        }
    }

}

return 0 ;
}
