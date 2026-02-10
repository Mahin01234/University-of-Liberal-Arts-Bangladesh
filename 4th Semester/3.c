#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n;
    char filename[100];

    printf("Enter the number of elements to generate: ");
    scanf("%d", &n);

    printf("Enter output file name (e.g., input100.txt): ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: Could not create file '%s'\n", filename);
        return 1;
    }

    srand(time(NULL)); // random seed

    for (int i = 0; i < n; i++) {
        int num = rand() % 100000; // random number 0 to 99999
        fprintf(fp, "%d\n", num);
    }

    fclose(fp);

    printf("File '%s' created with %d random elements.\n", filename, n);

    return 0;
}
