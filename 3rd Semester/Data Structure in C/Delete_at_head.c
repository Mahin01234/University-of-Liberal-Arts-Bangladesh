#include<stdio.h>
#include<stdlib.h>





struct Node
{
    int value ;
    struct Node * next ;
};





void Delete_at_head_node (struct Node **head , struct Node **tail , int value)
{
    struct Node *newnode = (struct Node *) malloc (sizeof (struct Node)) ;
    newnode->value = value ;
    newnode->next = NULL ;


    if (*head == NULL)
    {
        *head = newnode ;
        *tail = newnode ;
        return ;
    }


    (*tail)->next = newnode ;
    *tail = newnode ;
}






void Delete_at_head_print (struct Node ** head)
{

    if (head == NULL)
    {
        return ;
    }



    struct Node *temp = head ;


    while (temp != NULL)
    {
        printf ("%d " , temp->value) ;
        temp = temp->next ;
    }

    printf ("\n") ;
}






void Delete_at_head (struct Node ** head)
{

    if (head == NULL)
    {
        return ;
    }



    struct Node * delete_head = * head ;

    * head = (* head)->next ;


    free(delete_head) ;
}





int main()
{
    struct Node * head = NULL ;
    struct Node * tail = NULL ;


    int val ;
    printf("enter the value : " ) ;


    while (1)
    {

        scanf ("%d" , &val) ;

        if (val == -1)
        {
            break ;
        }

        Delete_at_head_node (&head , &tail , val) ;
    }


    Delete_at_head (&head) ;
    Delete_at_head_print (head) ;


    return 0 ;
}
