#include <stdio.h>
#include <stdlib.h>






struct Node
{
    int value ;
    struct Node *next ;
} ;







void tail_deleted_Node(struct Node **head, struct Node **tail, int value)
{

    struct Node * newnode = (struct Node *) malloc (sizeof(struct Node) ) ;
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











void tail_deleted_node_Print (struct Node * head)
{

    struct Node * temp = head ;
    while (temp != NULL)
    {
        printf("%d ", temp->value) ;
        temp = temp->next ;
    }

    printf("\n") ;


}








void delete_At_Head (struct Node **head)
{
    if (*head == NULL)
    {
        return ;
    }


    struct Node * delete_node = *head ;
    * head = (*head)->next ;
    free(delete_node) ;


}






void delete_At_Tail (struct Node ** head)
{
    if (*head == NULL)
    {
        return ;
    }


    if ((*head)->next == NULL)
    {
        free(*head) ;
        *head = NULL ;
        return ;
    }



    struct Node * temp = * head ;

    while (temp->next->next != NULL)
    {
        temp = temp->next ;
    }


    free(temp->next) ;
    temp->next = NULL ;




}








int main()
{
    struct Node *head = NULL ;
    struct Node *tail = NULL ;
    int val ;


    printf("Enter values : ") ;


    while (1)
    {
        scanf("%d", &val) ;
        if (val == -1)
        {
            break ;
        }


        tail_deleted_Node (&head, &tail, val) ;
    }



    printf("Before deletion : ") ;
    tail_deleted_node_Print (head) ;



    delete_At_Tail (&head) ;

    printf("After deleting tail : ") ;


    tail_deleted_node_Print (head) ;



    return 0 ;


}
