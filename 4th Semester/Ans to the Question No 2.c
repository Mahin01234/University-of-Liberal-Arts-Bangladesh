#include <stdio.h>
#include <stdlib.h>

#define N 9
#define CAPACITY 10

typedef struct {
    int weight;
    int value;
    float ratio;
} Item;

int greedySteps = 0;
int dpSteps = 0;


int compare(const void *a, const void *b) {
    greedySteps++;
    Item *i1 = (Item *)a;
    Item *i2 = (Item *)b;
    if (i2->ratio > i1->ratio) return 1;
    else if (i2->ratio < i1->ratio) return -1;
    return 0;
}

void greedyKnapsack(Item items[]) {
    qsort(items, N, sizeof(Item), compare);

    int totalWeight = 0;
    int totalValue = 0;

    printf("Greedy Selection:\n");

    for (int i = 0; i < N; i++) {
        greedySteps++;

        if (totalWeight + items[i].weight <= CAPACITY) {
            greedySteps++;

            totalWeight += items[i].weight;
            totalValue += items[i].value;

            printf("Item (w=%d, v=%d)\n", items[i].weight, items[i].value);
        }
    }

    printf("Greedy Total Weight = %d\n", totalWeight);
    printf("Greedy Total Value = %d\n", totalValue);
    printf("Greedy Step Count = %d\n\n", greedySteps);
}


void dpKnapsack(int weights[], int values[]) {
    int dp[N + 1][CAPACITY + 1];

    for (int i = 0; i <= N; i++) {
        for (int w = 0; w <= CAPACITY; w++) {
            dpSteps++;
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w) {
                dpSteps++;

                int include = values[i - 1] + dp[i - 1][w - weights[i - 1]];
                int exclude = dp[i - 1][w];

                dp[i][w] = (include > exclude) ? include : exclude;
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    printf("DP Optimal Value = %d\n", dp[N][CAPACITY]);
    printf("DP Step Count = %d\n", dpSteps);
}


int main() {

    int weights[N] = {2, 4, 2, 0, 1, 4, 1, 6, 5};
    int values[N]  = {5, 5, 5, 3, 3, 3, 10, 10, 10};

    Item items[N];

    for (int i = 0; i < N; i++) {
        items[i].weight = weights[i];
        items[i].value = values[i];

        if (weights[i] == 0)
            items[i].ratio = 1000000;
        else
            items[i].ratio = (float)values[i] / weights[i];
    }

    greedyKnapsack(items);
    dpKnapsack(weights, values);

    printf("\nConclusion:\n");
    printf("Greedy uses fewer steps but may not always be optimal.\n");
    printf("Dynamic Programming uses more steps but guarantees optimal solution.\n");
    printf("DP best step size.")  ;

    return 0;
}
