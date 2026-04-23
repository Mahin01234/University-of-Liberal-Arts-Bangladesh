#include <stdio.h>
#include <string.h>

long long countSubsequence(char *s, char *sub) {
    int n = strlen(s);
    int m = strlen(sub);

    long long dp[m + 1];


    for (int i = 0; i <= m; i++) dp[i] = 0;
    dp[0] = 1;


    for (int i = 0; i < n; i++) {
        for (int j = m - 1; j >= 0; j--) {
            if (s[i] == sub[j]) {
                dp[j + 1] += dp[j];
            }
        }
    }

    return dp[m];
}

int main()
{


    char pi[] = "14159265358979323846264338327950288419716939937510"
                "58209749445923078164062862089986280348253421170679";

    char id[20];

    printf("Enter a 9-digit ID: ");
    scanf("%s", id);

    if (strlen(id) != 9) {
        printf("Invalid input!\n");
        return 1;
    }

    char X[4], Y[4], Z[4];


    strncpy(X, id, 3);
    X[3] = '\0';

    strncpy(Y, id + 3, 3);
    Y[3] = '\0';

    strncpy(Z, id + 6, 3);
    Z[3] = '\0';

    printf("\nResults:\n");
    printf("X = %s -> %lld\n", X, countSubsequence(pi, X));
    printf("Y = %s -> %lld\n", Y, countSubsequence(pi, Y));
    printf("Z = %s -> %lld\n", Z, countSubsequence(pi, Z));

    return 0;
}
