#include <stdio.h>

#define MAX 100

// Function prototype
int knapsackRec(int W, int val[], int wt[], int n, int memo[MAX][MAX]);

// Max function (since C doesn't have built-in max)
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Recursive function with memoization
int knapsackRec(int W, int val[], int wt[], int n, int memo[MAX][MAX]) {

    // Base Case
    if (n == 0 || W == 0)
        return 0;

    // Check memo table
    if (memo[n][W] != -1)
        return memo[n][W];

    int pick = 0;

    // Pick item if possible
    if (wt[n - 1] <= W) {
        pick = val[n - 1] + knapsackRec(W - wt[n - 1], val, wt, n - 1, memo);
    }

    // Don't pick item
    int notPick = knapsackRec(W, val, wt, n - 1, memo);

    // Store result
    memo[n][W] = max(pick, notPick);

    return memo[n][W];
}

// Main knapsack function
int knapsack(int W, int val[], int wt[], int n) {

    int memo[MAX][MAX];

    // Initialize memo table with -1
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            memo[i][j] = -1;
        }
    }

    return knapsackRec(W, val, wt, n, memo);
}

// Main function
int main() {

    int val[] = {1, 2, 3};
    int wt[] = {4, 5, 1};
    int W = 4;
    int n = 3;

    int result = knapsack(W, val, wt, n);

    printf("Maximum Value: %d\n", result);

    return 0;
}
