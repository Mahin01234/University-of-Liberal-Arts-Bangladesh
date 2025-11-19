#include<stdio.h>
#include<stdlib.h> 




#define n 5 




int queue [n] ; 
int f = -1 ; 
int r = -1 ; 






void enqueue (int value) 
{

    if ( (r + 1) % n == f)  
    {
        printf("full") ; 
    }

    else 
    {

        if (f == -1) 
        {
            f = 0 ; 
        }


        r = (r + 1) % n ;
        
        
        queue [r] = value ; 
        printf ("insert the %d value \n" , value) ; 
    }
}







void dequeue () 
{
    if (f == -1) 
    {
        printf("empty\n") ; 
    }

    else 
    {
        printf("Deleted the value : %d" , queue[f] ) ;  



        if (f == r ) 
        {
            f = -1 ; 
            r = -1 ; 
        }

        else 
        {
            f = (f + 1 ) % n ; 
        }
    }
}







void display () 
{
    if (f == -1) 
    {
        printf("empty") ; 
    }

    else 
    {

        printf("queue element is : " ) ; 

        int i = f ; 

        while (1)
        {
            printf ("%d " , queue[i] ) ; 

            if (i == r ) 
            {
                break; 
            }


            i = (i + 1) % n ;  
        }
       

        printf ("\n") ; 
    }
}







int main() 
{
    int choice , value ; 


    while (1)
    {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);



        switch (choice) 
        
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);


                enqueue(value);
                break;



            case 2:
                dequeue();
                break;



            case 3:
                display();
                break;




            case 4:
                exit(0);


                
            default:
                printf("Invalid\n");


        }
    }




    return 0;
}
