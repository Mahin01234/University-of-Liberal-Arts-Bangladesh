#include <stdio.h>
#include <stdlib.h>

#define V 7

typedef struct {
    int u, v, w;
} Edge;

int parent[V], rankArr[V];

// Find with path compression
int find(int i) {
    if (parent[i] != i)
        parent[i] = find(parent[i]);
    return parent[i];
}

// Union by rank
void unionSet(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);

    if (rootA != rootB) {
        if (rankArr[rootA] < rankArr[rootB])
            parent[rootA] = rootB;
        else if (rankArr[rootA] > rankArr[rootB])
            parent[rootB] = rootA;
        else {
            parent[rootB] = rootA;
            rankArr[rootA]++;
        }
    }
}

int cmp(const void *a, const void *b) {
    return ((Edge*)a)->w - ((Edge*)b)->w;
}

// Kruskal
int kruskal(Edge edges[], int E, Edge mst[]) {
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rankArr[i] = 0;
    }

    qsort(edges, E, sizeof(Edge), cmp);

    int count = 0;

    for (int i = 0; i < E && count < V - 1; i++) {
        if (find(edges[i].u) != find(edges[i].v)) {
            mst[count++] = edges[i];
            unionSet(edges[i].u, edges[i].v);
        }
    }
    return count;
}

char getChar(int x) {
    return 'A' + x;
}

void printMST(Edge mst[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%c - %c (w=%d)\n",
               getChar(mst[i].u),
               getChar(mst[i].v),
               mst[i].w);
    }
}

// Find common edges
void findCommon(Edge mst1[], int n1, Edge mst2[], int n2) {
    printf("\nCommon Edges:\n");

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if ((mst1[i].u == mst2[j].u && mst1[i].v == mst2[j].v) ||
                (mst1[i].u == mst2[j].v && mst1[i].v == mst2[j].u)) {

                printf("%c - %c\n",
                       getChar(mst1[i].u),
                       getChar(mst1[i].v));
                break;
            }
        }
    }
}

int main() {

    // ID digits as weights
    int w[] = {2,4,2,0,1,4,1,6,5};

    // -------- Graph 1 --------
    Edge g1[] = {
        {1,6,w[0]}, // B-G
        {1,2,w[1]}, // B-C
        {5,6,w[2]}, // F-G
        {5,4,w[3]}, // F-E
        {4,2,w[4]}, // E-C
        {4,3,w[5]}, // E-D
        {2,3,w[6]}, // C-D
        {2,0,w[7]}, // C-A
        {3,0,w[8]}  // D-A
    };

    int E1 = sizeof(g1)/sizeof(g1[0]);

    // -------- Graph 2 --------
    Edge g2[] = {
        {1,5,w[0]}, // B-F
        {1,6,w[1]}, // B-G
        {5,4,w[2]}, // F-E
        {4,2,w[3]}, // E-C
        {4,0,w[4]}, // E-A
        {2,3,w[5]}, // C-D
        {3,0,w[6]}, // D-A
        {6,0,w[7]}, // G-A
        {2,6,w[8]}  // C-G
    };

    int E2 = sizeof(g2)/sizeof(g2[0]);

    Edge mst1[V], mst2[V];

    int n1 = kruskal(g1, E1, mst1);
    int n2 = kruskal(g2, E2, mst2);

    printf("MST Graph 1:\n");
    printMST(mst1, n1);

    printf("\nMST Graph 2:\n");
    printMST(mst2, n2);

    findCommon(mst1, n1, mst2, n2);

    return 0;
}
