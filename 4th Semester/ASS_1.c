#include <stdio.h>
#include <stdlib.h>
int steps = 0;
struct Item {
    char name[50];
    int weight;
    int value;
    float ratio;
};
int compareItem(const void *a, const void *b)
 {
    steps++;
    struct Item *i1 = (struct Item *)a;
    struct Item *i2 = (struct Item *)b;

    if(i2->ratio > i1->ratio) return 1;
    else if(i2->ratio < i1->ratio) return -1;
    else return 0;
}
void fractionalKnapsack()
{
    steps = 0;
    int n, capacity;
    printf("\nEnter knapsack capacity (bag size): ");
    scanf("%d", &capacity);
    printf("Enter number of items: ");
    scanf("%d", &n);
    struct Item items[n];
    for(int i = 0; i < n; i++)
    {
        steps++;
        printf("\nItem %d name: ", i+1);
        scanf(" %49[^\n]", items[i].name);
        printf("Value: ");
        scanf("%d", &items[i].value);
        printf("Weight: ");
        scanf("%d", &items[i].weight);
        items[i].ratio = (float)items[i].value / items[i].weight;
        printf("Unit Value (Value/Weight) = %.2f\n", items[i].ratio);
    }
    qsort(items, n, sizeof(struct Item), compareItem);
    float totalValue = 0.0;
    printf("\nFRACTIONAL KNAPSACK RESULT\n");
    for(int i = 0; i < n; i++) {
        steps++;
        if(capacity == 0)
            break;
        if(items[i].weight <= capacity)
        {
            printf("Take full item: %s\n", items[i].name);
            capacity -= items[i].weight;
            totalValue += items[i].value;
            steps++;
        }
        else
        {
            float fraction = (float)capacity / items[i].weight;
            printf("Take %.2f fraction of item: %s\n", fraction, items[i].name);
            totalValue += items[i].value * fraction;
            capacity = 0;
            steps++;
        }
    }
    printf("Maximum value = %.2f\n", totalValue);
    printf("Total Steps = %d\n", steps);
}
struct Task
 {
    char name[50];
    int start;
    int finish;
    int duration;
};
int compareFinish(const void *a, const void *b) {
    steps++;
    struct Task *t1 = (struct Task *)a;
    struct Task *t2 = (struct Task *)b;
    return t1->finish - t2->finish;
}
void activitySelection()
{
    steps = 0;
    int n, totalDeadline;
    printf("\nEnter TOTAL available deadline time: ");
    scanf("%d", &totalDeadline);
    printf("Enter number of tasks: ");
    scanf("%d", &n);
    struct Task tasks[n];
    for(int i = 0; i < n; i++)
    {
        steps++;
        printf("\nTask %d name: ", i+1);
        scanf(" %49[^\n]", tasks[i].name);
        printf("Start time: ");
        scanf("%d", &tasks[i].start);
        printf("Deadline time (Finish time): ");
        scanf("%d", &tasks[i].finish);
        tasks[i].duration = tasks[i].finish - tasks[i].start;
        printf("Time Required = %d\n", tasks[i].duration);
    }
    qsort(tasks, n, sizeof(struct Task), compareFinish);
    printf("\n===== SELECTED TASKS =====\n");
    int count = 0;
    int lastFinish = -1;
    int totalUsedTime = 0;
    for(int i = 0; i < n; i++)
    {
        steps++;
        if(tasks[i].start >= lastFinish &&
           totalUsedTime + tasks[i].duration <= totalDeadline)
        {
            printf("Task: %s [%d, %d]\n",
                   tasks[i].name,
                   tasks[i].start,
                   tasks[i].finish);
            lastFinish = tasks[i].finish;
            totalUsedTime += tasks[i].duration;
            count++;
            steps++;
        }
    }
    printf("Maximum number of non-conflicting tasks = %d\n", count);
    printf("Total time used = %d\n", totalUsedTime);
    printf("Total Steps = %d\n", steps);
}
int main()
{
    int choice;
    printf("      GREEDY ALGORITHMS\n");
    printf("=================================\n");
    printf("1. Fractional Knapsack\n");
    printf("2. Activity Selection\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            fractionalKnapsack();
            break;
        case 2:
            activitySelection();
            break;
        default:
            printf("Invalid choice!\n");
    }
    return 0;
}
