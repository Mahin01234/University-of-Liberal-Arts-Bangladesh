#include<stdio.h>
#define Size 5 



void Enqueue (int) ; 
void Dequeue () ; 
void display () ; 



int item[Size] ; 
int front = -1 ; 
int rear = -1  ; 



int main()
{
    int choice , value ; 

    while (1)
    {
        printf("1. EnQueue\n") ; 
        printf("2. DnQueue\n") ; 
        printf("3. Display\n") ; 
        printf("4. Exit\n") ;  


        printf("enter the choice : ") ; 
        scanf("%d" , &choice) ; 


        switch (choice)
        {
        case 1:
            printf("Enter the value insert : ") ; 
            scanf("%d" , &value) ; 
            Enqueue(value) ; 
            break;
        

        case 2: 
            Dequeue() ; 
            break;
            
            
        case 3: 
            display() ; 
            break;
         
            
        case 4: 
            printf("Exiting\n") ; 
            return 0 ; 
          
            

        default:
            printf("Please try again.\n") ; 
            
        }
    }
    
}



void Enqueue (int value) 
{
    if (rear == Size - 1) 
    {
        printf("Queue is full") ; 
    }
    else 
    {
        if (front == -1) 
        {
            front = 0 ; 
        }
        rear++ ; 
        item[rear] = value ; 
        printf("Insert : %d\n" , value) ; 
    }
}



void Dequeue () 
{
    if (front == -1 || front > rear) 
    {
        printf("Empty\n") ; 
    }
    else 
    {
        printf("Deleted : %d\n" , item[front] ) ; 
        front++ ; 

        if (front > rear) 
        {
            front = rear = -1 ; 

        }
    }
}





void display()
{
    if (rear == -1 || front > rear) 
    {
        printf("Emptyn\n")  ; 
    }
    else
    {
        printf("Queue element is : ") ; 

        for (int i = front ; i <= rear ; i++) 
        {
            printf("%d " , item[i] ) ; 
        }
        printf("\n" ) ; 
    }
} 

