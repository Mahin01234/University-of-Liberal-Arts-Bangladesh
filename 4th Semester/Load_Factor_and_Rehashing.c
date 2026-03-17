#include <stdio.h>
#include <stdlib.h>

#define NUM_BUCKETS 5
#define LOAD_FACTOR 0.75

// Node structure
struct Node {
    int key;
    int value;
    struct Node* next;
};

// Hash table
struct Node* buckets[NUM_BUCKETS];
int size = 0;

// Hash function
int getIndex(int key, int bucketSize) {
    return key % bucketSize;
}

// Create new node
struct Node* createNode(int key, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Insert function
void insert(int key, int value, int bucketSize) {
    int index = getIndex(key, bucketSize);

    struct Node* head = buckets[index];

    // Check if key exists
    while (head != NULL) {
        if (head->key == key) {
            head->value = value;
            return;
        }
        head = head->next;
    }

    // Insert at beginning (Separate Chaining)
    struct Node* newNode = createNode(key, value);
    newNode->next = buckets[index];
    buckets[index] = newNode;

    size++;

    printf("Inserted (%d, %d)\n", key, value);

    float load = (float)size / bucketSize;
    printf("Load Factor: %.2f\n", load);
}

// Display function
void display(int bucketSize) {
    printf("\nHash Table:\n");
    for (int i = 0; i < bucketSize; i++) {
        struct Node* temp = buckets[i];
        printf("[%d]: ", i);
        while (temp != NULL) {
            printf("(%d,%d) -> ", temp->key, temp->value);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Main
int main() {

    int bucketSize = NUM_BUCKETS;

    // Initialize buckets
    for (int i = 0; i < bucketSize; i++) {
        buckets[i] = NULL;
    }

    // Insert values
    insert(1, 1, bucketSize);
    insert(2, 2, bucketSize);
    insert(3, 3, bucketSize);
    insert(4, 4, bucketSize);
    insert(5, 5, bucketSize);
    insert(6, 6, bucketSize);
    insert(7, 7, bucketSize);

    display(bucketSize);

    return 0;
}
