#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    int value ; 
    struct Node * next ; 
} ; 

void insert_any_position (struct Node ** head , int index , int value) 
{
    struct Node * newnode = (struct Node *) malloc (sizeof (struct Node ) ) ; 
    newnode->value = value ; 
    newnode->next = NULL ; 

    if (index == 0) 
    {
        newnode->next = * head ; 
        * head = newnode ; 
        return ; 
    }
    struct Node * temp = * head ; 

    for(int i=0 ; i<index-1 ; i++) 
    {
        temp = temp->next ; 
    }

    if (temp == NULL) 
    {
        printf("invalid") ; 
        free (newnode) ; 
        return ; 
    }
    newnode->next = temp->next ; 
    temp->next = newnode ; 
}

void insert_any_position_print (struct Node * head) 
{
    struct Node * temp = head ; 
    while (temp != NULL)
    {
        printf("%d " , temp->value) ; 
        temp = temp->next ; 
    }
    printf("\n") ; 
}


int main()
{
    struct Node * head = (struct Node *) malloc (sizeof (struct Node ) ) ;
    struct Node * a = (struct Node *) malloc (sizeof (struct Node ) ) ;
    struct Node * b = (struct Node *) malloc (sizeof (struct Node ) ) ; 

    head->value = 10 ;
    a->value = 20 ;
    b->value = 30 ;

    head->next = a ; 
    a->next = b ;
    b->next = NULL ; 

    insert_any_position_print (head) ;
    insert_any_position (&head, 2, 100) ;
    insert_any_position_print (head);

    return 0;
}