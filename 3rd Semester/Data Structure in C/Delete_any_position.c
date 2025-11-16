#include <stdio.h>
#include <stdlib.h>






struct Node
{
    int value ;
    struct Node *next ;
} ;








void Delete_at_head_node (struct Node ** head, struct Node ** tail, int value)
{
    struct Node * newnode = (struct Node *) malloc (sizeof(struct Node) ) ;
    newnode->value = value ;
    newnode->next = NULL ;


    if (* head == NULL)
    {
        * head = newnode ;
        * tail = newnode ;
        return ;
    }



    (* tail)->next = newnode ;
    * tail = newnode ;
}










void Delete_at_head_print (struct Node * head)
{

    if (head == NULL)
    {
        return ;
    }


    struct Node * temp = head ;
    while (temp != NULL)
    {
        printf("%d ", temp->value) ;
        temp = temp->next  ;
    }

    printf("\n") ;
}









void Delete_any_position (struct Node ** head, int index)
{
    if (* head == NULL)
    {
        return ;
    }


    if (index == 1)
    {
        struct Node * delete_node = * head ;
        * head = (*head)->next ;
        free(delete_node) ;
        return ;
    }




    struct Node *temp = *head ;


    for (int i = 1 ; i < index ; i++)
    {
        if (temp == NULL || temp->next == NULL)
        {
            return;
        }
        temp = temp->next;
    }



    struct Node * delete_node = temp->next ;
    if (delete_node == NULL)
    {
        return ;
    }



    temp->next = delete_node->next ;
    free(delete_node) ;
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

        Delete_at_head_node (&head, &tail, val) ;
    }




    printf("Before deletion : ") ;
    Delete_at_head_print (head) ;

    int position ;
    printf("Enter position to delete : ") ;
    scanf("%d", &position);



    Delete_any_position(&head, position) ;




    printf("After deletion : ") ;
    Delete_at_head_print (head) ;



    return 0;
}
