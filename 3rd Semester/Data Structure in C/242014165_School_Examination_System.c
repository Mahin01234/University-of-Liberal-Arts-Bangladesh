#include<stdio.h>
#include<stdlib.h>




#define Stack_Size 5
#define Queue_Size 5





int queue [Queue_Size] ;
int stack [Stack_Size] ;




int top = -1 ;
int front = -1 ;
int rear = -1 ;






void Enqueue ()
{
    int ID ;



    if (rear == Queue_Size - 1)
    {
        printf("Queue is overflow \n" ) ;
    }

    else
    {
        printf ("Enter the student id is : ") ;



        scanf("%d" , &ID) ;




        if (front == -1)
        {
            front = 0 ;
        }




        rear = rear + 1 ;

        queue [rear] = ID ;





        printf ("Enqueue student %d\n" , ID)  ;



    }
}







void Dequeue ()
{


    if (front == -1 || front > rear)
    {
        printf("Queue is underflow \n" ) ;
    }

    else
    {
        printf ("Dequeue student %d\n" , queue[front] )   ;


        front = front + 1 ;




        if (front > rear)
        {
            front = rear = - 1 ;
        }



    }
}







void queue_peek ()
{
    if (front == -1)
    {
        printf("Queue is empty \n") ;
    }
    else
    {
        printf ("The front student id is : %d\n" , queue [front] ) ;
    }
}







void queue_display ()
{

    if (front == -1)
    {
        printf ("Queue is empty" ) ;
    }
    else
    {
        printf ("The student is queue : ") ;




        for ( int i = front ; i <= rear ; i++)
        {

            printf ("%d " , queue[i] )  ;
        }




        printf ("\n") ;


    }
}







void push ()
{

    int id ;


    if (top == Stack_Size - 1)
    {
        printf ("stack overflow" ) ;
    }

    else
    {
        printf ("enter the stuent id is for answer sheet : ") ;

        scanf ("%d" , &id) ;



        top = top + 1 ;
        stack[top] = id ;


        printf ("Answer sheet for student %d\n " , id) ;


    }
}







void pop ()
{

    if (top == -1)
    {
        printf ("No answer sheet") ;
    }

    else
    {
        printf ("checking answer sheet for student %d\n" , stack[top] )  ;

        top-- ;
    }
}







void peek_stack ()
{

    if (top == -1)
    {
        printf ("No answer sheet\n ") ;
    }

    else
    {

        printf("Top answer %d\n" , stack[top] ) ;
    }
}






void display ()
{
    if (top == -1)
    {
        printf ("No answer\n ") ;
    }

    else

    {
        printf ("Answer sheet is : ") ;


        for (int i = top ; i >= 0 ; i-- )

        {

            printf ("%d " , stack[i] ) ;
        }


        printf("\n") ;
    }
}







int main()
{
    int choice ;


    while (1)
    {

        printf("\n\n\n--------SCHOOL EXAMINATION SYSTEM--------\n\n\n")  ;


        printf("1. The Enqueue student \n" ) ;
        printf("2. The Dequeue student \n") ;
        printf("3. Peek student \n") ;
        printf ("4. Display Suudent is queue \n") ;




        printf("5. Push Answer sheet\n") ;
        printf("6. Pop Answer sheet\n") ;
        printf("7. Peek Answer sheet \n") ;
        printf("8. Display Answer sheet\n") ;


        printf("9. Exit\n") ;





        printf("Enter The Choice : " ) ;
        scanf("%d" , &choice) ;





        switch (choice)

        {
            case 1 :
            Enqueue ()  ;
            {
                break;
            }



            case 2 :
            Dequeue ()  ;
            {
                break;
            }




            case 3 :
            queue_peek () ;
            {
                break;
            }




            case 4 :
            queue_display () ;
            {
                break;
            }




            case 5 :
            push () ;
            {
                break;
            }



            case 6 :
            pop () ;
            {
                break;
            }



            case 7 :
            peek_stack () ;
            {
                break;
            }




            case 8 :
            display () ;
            {
                break;
            }




            case 9 :
            printf ("Invalid\n") ;
            exit (0) ;
        }
    }



    return 0 ;

}
