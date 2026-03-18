#include <stdio.h>
#include <string.h>

// Define a maximum size for the strings
#define MAX 1000

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Returns length of LCS for s1[0..m-1], s2[0..n-1]
int lcsRec(const char *s1, const char *s2, int m, int n, int memo[MAX][MAX]) {

    // Base Case
    if (m == 0 || n == 0) {
        return 0;
    }

    // Already exists in the memo table
    if (memo[m][n] != -1) {
        return memo[m][n];
    }

    // Match
    if (s1[m - 1] == s2[n - 1]) {
        return memo[m][n] = 1 + lcsRec(s1, s2, m - 1, n - 1, memo);
    }

    // Do not match
    return memo[m][n] = max(lcsRec(s1, s2, m, n - 1, memo), lcsRec(s1, s2, m - 1, n, memo));
}

int lcs(char s1[],char s2[]){
      int m = strlen(s1);
    int n = strlen(s2);

    // Create memo table with fixed size
    int memo[MAX][MAX];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            // Initialize memo table with -1
            memo[i][j] = -1;
        }
    }

    return lcsRec(s1, s2, m, n, memo);
}

int main() {
    const char *s1 = "AGGTAB";
    const char *s2 = "GXTXAYB";


    printf("%d\n", lcs(s1, s2));

    return 0;
}
