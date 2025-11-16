#include <stdio.h>




int linear_search(int arr[], int n, int x)
{

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }

       return -1;

}








int main()

{
    int n, x;



    printf("Enter the array size: ");
    scanf("%d", &n);



    int a[n];



    printf("Enter the array values: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the value to search: ");
    scanf("%d", &x);


    int result = linear_search(a, n, x);



    if (result == -1)
    {
        printf("not found\n");
    }

    else
    {
        printf("found\n");
        printf("index: %d\n", result);
    }




    return 0;
}

