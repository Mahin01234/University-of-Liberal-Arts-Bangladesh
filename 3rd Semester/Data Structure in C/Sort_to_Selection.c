#include <stdio.h>
#include <stdlib.h>





struct Node
{
    int val;
    struct Node* next;
};





void insert_tail(struct Node** head, struct Node** tail, int val)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = NULL;

    if (*head == NULL)

    {
        *head = newNode;
        *tail = newNode;
        return;
    }



    (*tail)->next = newNode;
    *tail = newNode;
}





void print_list(struct Node* head)
{
    struct Node* temp = head;
    while (temp != NULL)
        {
            printf("%d ", temp->val);
            temp = temp->next;
    }

    printf("\n");
}






void sort_descending(struct Node* head)
{
    struct Node* i;
    struct Node* j;
    for (i = head; i != NULL; i = i->next)
        {
            for (j = i->next; j != NULL; j = j->next)
            {
                if (i->val < j->val)
                {
                   int temp = i->val;
                   i->val = j->val;
                   j->val = temp;
               }
          }
    }
}








void sort_ascending(struct Node* head)
{
    struct Node* i;
    struct Node* j;
    for (i = head; i != NULL; i = i->next)
        {
            for (j = i->next; j != NULL; j = j->next)
            {
                if (i->val > j->val)
                {
                    int temp = i->val;
                    i->val = j->val;
                    j->val = temp;
              }
         }
    }
}








int main()
{
    struct Node* head = NULL;
    struct Node* tail = NULL;

    printf("Enter values : ");
    while (1)
    {
        int val;
        scanf("%d", &val);
        if (val == -1) break;
        insert_tail(&head, &tail, val);
    }




    sort_descending(head);
    printf("Sorted descending: ");
    print_list(head);




    sort_ascending(head);
    printf("Sorted ascending: ");
    print_list(head);




    return 0 ;



}
