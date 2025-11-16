#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

// Push function
void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
    } else {
        top++;
        stack[top] = x;
    }
}

// Display function (LIFO order)
void display() {
    if (top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack push :\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int n, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        push(x);
    }

    display();

    return 0;
}
