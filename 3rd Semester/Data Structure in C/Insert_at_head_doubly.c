#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *next;
    struct Node *prev;
};

// Print linked list forward
void print_forward(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

// Insert at head
void insert_head(struct Node **head, int value)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->value = value;
    newnode->next = *head;
    newnode->prev = NULL;

    if (*head != NULL)
    {
        (*head)->prev = newnode;
    }

    *head = newnode;
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *a = (struct Node *)malloc(sizeof(struct Node));
    struct Node *b = (struct Node *)malloc(sizeof(struct Node));

    head->value = 10;
    a->value = 20;
    b->value = 30;

    head->next = a;
    a->prev = head;

    a->next = b;
    b->prev = a;

    b->next = NULL;

    insert_head(&head, 1220);
    print_forward(head);

    return 0;
}

