#include <stdio.h>
#define MAX 100

long long memoization[MAX];
int memoizationSteps = 0;  // Step counter memoization
int tabulationSteps = 0;           // Step counter tabulation

// Memoization Function (Top-Down)
long long fibMemo(int n)
{
    memoizationSteps++;
    if (n <= 1)
    {
        return n;
    }
    if (memoization[n] != -1)
    {
        return memoization[n];
    }
    memoization[n] = fibMemo(n - 1) + fibMemo(n - 2);
    return memoization[n];
}

// Tabulation Function (Bottom-Up)
long long fibTab(int n)
{
    long long dp[MAX];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        tabulationSteps++;
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    // Initialize memoization array
    for (int i = 0; i < MAX; i++)
        memoization[i] = -1;

    long long memoResult = fibMemo(n);
    long long tabResult = fibTab(n);

    printf("\nMemoization Result : %lld\n", memoResult);
    printf("Memoization Steps : %d\n", memoizationSteps);
    printf("\nTabulation Result : %lld\n", tabResult);
    printf("Tabulation Steps : %d\n", tabulationSteps);
    return 0;
}
