#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *next;
    struct Node *prev;
};

// 🔹 Print linked list forward
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

// 🔹 Insert at tail
void insert_tail(struct Node **head, struct Node **tail, int value)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->value = value;
    newnode->next = NULL;
    newnode->prev = *tail;

    // যদি লিস্ট ফাঁকা থাকে
    if (*head == NULL)
    {
        *head = newnode;
        *tail = newnode;
        return;
    }

    // অন্যথায় শেষে নতুন নোড যুক্ত হবে
    (*tail)->next = newnode;
    *tail = newnode;
}

int main()
{
    struct Node *head = NULL;
    struct Node *tail = NULL;

    // প্রাথমিকভাবে কিছু ভ্যালু ইনসার্ট করছি
    insert_tail(&head, &tail, 10);
    insert_tail(&head, &tail, 20);
    insert_tail(&head, &tail, 30);

    printf("Initial list: ");
    print_forward(head);

    int value;
    printf("Enter the tail: ");
    scanf("%d", &value);

    insert_tail(&head, &tail, value);

    printf("After tail: ");
    print_forward(head);

    return 0;
}
