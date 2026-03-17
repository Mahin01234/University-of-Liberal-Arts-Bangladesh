#include <stdio.h>
#include <string.h>

#define MAX 100

int main()
{
    char A[MAX], B[] = "abcdefghijklmnopqrstuvwxyz";

    printf("Enter your full name : ");
    scanf("%s", A);

    int m = strlen(A);
    int n = strlen(B);

    int dp[MAX][MAX];


    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
         {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }


    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (A[i - 1] == B[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                if (dp[i - 1][j] > dp[i][j - 1])
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
    }


    printf("\nString A: %s\n", A);
    printf("String B: %s\n", B);


    printf("\nLength of LCS: %d\n", dp[m][n]);


    int i = m, j = n;
    char lcs[MAX];
    int index = dp[m][n];

    lcs[index] = '\0';

    while (i > 0 && j > 0)
    {
        if (A[i - 1] == B[j - 1])
        {
            lcs[index - 1] = A[i - 1];
            i--;
            j--;
            index--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
               j--;
        }
    }


    printf("LCS: %s\n", lcs);


    printf("\nPartial DP Table:\n");

    for (int i = 0; i <= m && i < 6; i++)
    {
        for (int j = 0; j <= n && j < 10; j++)
        {
            printf("%d ", dp[i][j]);
        }

        printf("\n");
    }


    return 0;
}
