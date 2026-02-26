#include <stdio.h>
#define MAX 100


int memo_steps = 0;
int tab_steps = 0;

int fib_memo(int n, int memo[])
{
    memo_steps++;

    if (n == 0 || n == 1)
        return n;

    if (memo[n] != -1)
        return memo[n];

    memo[n] = fib_memo(n - 1, memo) + fib_memo(n - 2, memo);
    return memo[n];
}


int fib_tab(int n)
{
    int dp[MAX];

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        tab_steps++;
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}


int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int memo[MAX];
    for (int i = 0; i <= n; i++)
        memo[i] = -1;
    int memo_result = fib_memo(n, memo);
    int tab_result = fib_tab(n);
    printf("Memoization Result: %d\n", memo_result);
    printf("Memoization Steps: %d\n\n", memo_steps);
    printf("Tabulation Result: %d\n", tab_result);
    printf("Tabulation Steps: %d\n", tab_steps);

    return 0;
}
