#include <stdio.h>

// Function to find nth fibonacci number
int fib(int n) {
    if (n <= 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n = 5;
    printf("%d", fib(n));
    return 0;
}
