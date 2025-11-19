#include<stdio.h>
#define MAX 10




int stack [MAX]  ;
int top = -1 ;




void push (int x)
{

    if (top == MAX - 1)
    {
        printf ("overflow\n")  ;
     }

     else
     {

         top = top + 1 ;
         stack [top] = x ;
     }
}







void pop ()
{
    if ( top == -1)
    {

        printf("underflow") ;
    }

    else
    {

        int value = stack [top] ;

        top = top - 1 ;


        printf ("the pop : %d\n " , value) ;
    }

}





void display ()
{

    if (top == -1)
    {

        printf ("empty") ;
    }

    else
    {

        printf ("Stack the element : \n") ;

        for (int i = top ; i >= 0 ; i-- )
        {

            printf ("%d\n" , stack[i] )  ;
        }
    }
}






int main ()
{

    int n , x ;


    printf ("enter the element : ") ;
    scanf("%d" , &n) ;


    printf ("enter the %d value\n " , n ) ;


    for (int i = 0 ; i < n ; i++)
    {

        scanf ("%d" , &x) ;

        push (x) ;
    }



    pop() ;
    pop() ;




    display () ;





    return 0 ;
}
