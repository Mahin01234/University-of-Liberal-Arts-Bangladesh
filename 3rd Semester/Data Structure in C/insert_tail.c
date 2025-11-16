#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int value ; 
    struct Node * next ; 
} ;

void insert_tail (struct Node ** head , struct Node ** tail , int value) 
{
    struct Node * newnode = (struct Node *) malloc (sizeof (struct Node ))  ; 
    newnode->value = value ; 
    newnode->next = NULL ; 
    if (*head == NULL) 
    {
        * head = newnode ; 
        * tail = newnode ; 
        return ; 
    } 
    (*tail)->next = newnode ; 
    *tail = newnode ;
}

void insert_tail_print (struct Node * head) 
{
    struct Node * temp = head ; 
    while (temp != NULL) 
    {
        printf("%d\n" , temp->value) ;
        temp = temp->next ; 
    }
}

int main()
{
    struct Node * tail ; 
    struct Node * head = (struct Node *) malloc (sizeof (struct Node )) ; 
    struct Node * a = (struct Node * ) malloc (sizeof (struct Node ) ) ; 
    head->value = 10 ; 
    a->value = 20 ; 
    

    head->next = a ; 
    a->next = NULL ; 
    tail = a ; 

    insert_tail (&head , &tail , 90) ; 
    insert_tail_print (head) ;   

    return 0 ; 
    
}