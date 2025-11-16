#include<stdio.h>




int binary_Search(int a[], int x, int low, int high)
{
   while (low <= high)
   {
       int mid = low + (high - low) / 2 ;

       if (a[mid] == x)
       {
           return mid ;
       }

       else if (a[mid] < x)
       {
           low = mid + 1 ;
       }

       else
       {
           high = mid - 1 ;
       }
   }
       return -1 ;

}




int main()
{
   int n , x, i ;



   printf("Enter size of array: ") ;
   scanf("%d", &n);


   int arr[n];
   printf("Enter Array Elements: ") ;



   for(i=0;i<n;i++)
    {
        scanf("%d", &arr[i]) ;
    }


    printf("Enter Item to search for: ") ;
    scanf("%d", &x);



    int result = binary_Search(arr, x, 0, n-1) ;



    if (result == -1)
    {
        printf("not found");
    }
    else
    {

        printf("found\n");
        printf("index  : %d", result);
    }

    return 0 ;
}

