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
    Dequeue() ; 


    Enqueue (10) ; 
    Enqueue (20) ; 
    Enqueue (30) ; 
    Enqueue (40) ; 
    Enqueue (50) ; 


    display() ; 

    Dequeue() ; 
    display() ; 


    return 0 ; 

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

