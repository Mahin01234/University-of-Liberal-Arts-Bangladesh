#include<stdio.h> 
int main()
{ 
    
    int n , value ; 


    printf("Enter the nums : " ) ; 
    scanf("%d" , &n) ; 
    
    

    printf("Enter the %d integer : " , n) ; 




    int arr[n] ; 
    for (int i=0 ; i<n ; i++) 
    {
        scanf("%d" , &arr[i]) ; 
    } 



    printf("enter the %d value find : " , n) ; 
    scanf("%d" , &value) ;  




    int flag = 0 ; 
    int L = 0 ; 
    int R = n - 1 ; 
    int Middle ; 


    while (L <= R)
    {
        Middle = (L + R) / 2 ; 

        if(arr[Middle] == value) 
        {
            flag = 1 ; 
            break; 
        }

        else if (arr[Middle] > value) 
        {
            R = Middle - 1 ; 
        }

        else
        {
            L = Middle + 1 ; 
        }

    }





    if (flag == 1) 
    {
        printf("Found\n") ; 
        printf("The Location : %d\n" , Middle + 1 ) ; 
        printf("Index : %d\n" , Middle ) ; 
    }
    else 
    {
        printf("Not Found\n") ; 
    }



    return 0 ; 
    
}
