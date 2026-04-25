#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <time.h>

#define N 9   // A..I

typedef struct {
    int u, v, w;
} Edge;

typedef struct Node {
    int to, w;
    struct Node *next;
} Node;

Edge edges[] = {
    {0,1,1}, // A-B
    {1,2,2}, // B-C
    {2,3,3}, // C-D
    {3,4,1}, // D-E
    {4,5,2}, // E-F
    {5,6,3}, // F-G
    {6,7,1}, // G-H
    {7,8,1}, // H-I
    {8,0,2}  // I-A
};
int m = sizeof(edges)/sizeof(edges[0]);

// ---------- DSU ----------
int parent[N], rnk[N];
void dsu_init() { for(int i=0;i<N;i++) { parent[i]=i; rnk[i]=0; } }
int dsu_find(int x) {
    if(parent[x] != x) parent[x] = dsu_find(parent[x]);
    return parent[x];
}
int dsu_union(int a, int b) {
    a = dsu_find(a); b = dsu_find(b);
    if(a == b) return 0;
    if(rnk[a] < rnk[b]) parent[a] = b;
    else if(rnk[b] < rnk[a]) parent[b] = a;
    else { parent[b] = a; rnk[a]++; }
    return 1;
}

int cmp_edge(const void *a, const void *b) {
    const Edge *ea = a, *eb = b;
    return (ea->w > eb->w) - (ea->w < eb->w);
}
int kruskal(Edge *in, int in_cnt, Edge *out, int *out_cnt) {
    Edge *tmp = malloc(in_cnt * sizeof(Edge));
    if(!tmp) { fprintf(stderr,"Memory error\n"); exit(1); }
    memcpy(tmp, in, in_cnt * sizeof(Edge));
    qsort(tmp, in_cnt, sizeof(Edge), cmp_edge);
    dsu_init();
    int cnt = 0, total = 0;
    for(int i=0; i<in_cnt && cnt < N-1; i++) {
        if(dsu_union(tmp[i].u, tmp[i].v)) {
            out[cnt++] = tmp[i];
            total += tmp[i].w;
        }
    }
    free(tmp);
    *out_cnt = cnt;
    return total;
}

int prim(Edge *in, int in_cnt, Edge *out, int *out_cnt) {
    int adj[N][N] = {{0}};
    for(int i=0; i<in_cnt; i++) {
        adj[in[i].u][in[i].v] = in[i].w;
        adj[in[i].v][in[i].u] = in[i].w;
    }
    int inMST[N] = {0};
    int key[N], parentPrim[N];
    for(int i=0;i<N;i++) key[i]=INT_MAX, parentPrim[i]=-1;
    key[0]=0;
    for(int count=0; count<N; count++) {
        int u=-1, min=INT_MAX;
        for(int v=0;v<N;v++) if(!inMST[v] && key[v]<min) { min=key[v]; u=v; }
        if(u==-1) break;
        inMST[u]=1;
        for(int v=0;v<N;v++) if(adj[u][v] && !inMST[v] && adj[u][v]<key[v]) {
            key[v]=adj[u][v];
            parentPrim[v]=u;
        }
    }
    int cnt=0, total=0;
    for(int v=1;v<N;v++) {
        if(parentPrim[v]!=-1) {
            out[cnt].u = parentPrim[v];
            out[cnt].v = v;
            out[cnt].w = adj[parentPrim[v]][v];
            total += out[cnt].w;
            cnt++;
        }
    }
    *out_cnt = cnt;
    return total;
}

void add_edge_adj(Node *adj[], int u, int v, int w) {
    Node *p = malloc(sizeof(Node)); p->to=v; p->w=w; p->next=adj[u]; adj[u]=p;
    p = malloc(sizeof(Node)); p->to=u; p->w=w; p->next=adj[v]; adj[v]=p;
}
int dfs_traversal_cost(Edge *mst, int mst_cnt) {
    Node *adj[N] = {NULL};
    for(int i=0; i<mst_cnt; i++)
        add_edge_adj(adj, mst[i].u, mst[i].v, mst[i].w);

    int visited[N] = {0};
    int total_cost = 0;
    typedef struct { int node; Node *it; } State;
    State stack[2*N];
    int top=0;
    visited[0]=1;
    stack[top].node = 0;
    stack[top].it = adj[0];
    top++;

    while(top>0) {
        State *cur = &stack[top-1];
        Node *p = cur->it;
        if(p == NULL) {
            int cur_node = cur->node;
            top--;
            if(top>0) {
                int par = stack[top-1].node;
                Node *q = adj[par];
                while(q) { if(q->to == cur_node) { total_cost += q->w; break; } q=q->next; }
            }
            continue;
        }
        cur->it = p->next;
        if(!visited[p->to]) {
            total_cost += p->w;
            visited[p->to] = 1;
            stack[top].node = p->to;
            stack[top].it = adj[p->to];
            top++;
        }
    }
    // cleanup
    for(int i=0;i<N;i++) {
        Node *q = adj[i];
        while(q) { Node *t = q; q = q->next; free(t); }
    }
    return total_cost;
}

int main() {
    char id[20];
    printf("Enter your 9-digit ID: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';
    if(strlen(id) != 9) { printf("ID must be exactly 9 digits.\n"); return 1; }
    for(int i=0;i<9;i++) if(!isdigit(id[i])) { printf("Only digits allowed.\n"); return 1; }

    int sales[N], total_sales = 0;
    for(int i=0;i<N;i++) { sales[i] = id[i]-'0'; total_sales += sales[i]; }

    Edge mstK[N-1], mstP[N-1];
    int kcnt, pcnt;

    clock_t t1 = clock();
    int totalK = kruskal(edges, m, mstK, &kcnt);
    clock_t t2 = clock();
    double timeK = (double)(t2-t1)/CLOCKS_PER_SEC;

    clock_t t3 = clock();
    int totalP = prim(edges, m, mstP, &pcnt);
    clock_t t4 = clock();
    double timeP = (double)(t4-t3)/CLOCKS_PER_SEC;

    if(kcnt != N-1 || pcnt != N-1) {
        printf("ERROR: Graph not fully connected! kcnt=%d, pcnt=%d (need %d)\n", kcnt, pcnt, N-1);
        return 1;
    }

    printf("\nKruskal MST-\n");
    for(int i=0; i<kcnt; i++) printf("%c-%c : %d\n", 'A'+mstK[i].u, 'A'+mstK[i].v, mstK[i].w);
    printf("Total weight : %d\n", totalK);
    printf("Time: %.6f sec\n", timeK);

    printf("\nPrim MST-\n");
    for(int i=0; i<pcnt; i++) printf("%c-%c : %d\n", 'A'+mstP[i].u, 'A'+mstP[i].v, mstP[i].w);
    printf("Total Weight : %d\n", totalP);
    printf("Time: %.6f sec\n", timeP);

    int dfs_cost = dfs_traversal_cost(mstK, kcnt);
    printf("\nDFS traversal cost: %d\n", dfs_cost);
    printf("2 * MST weight = %d\n", 2*totalK);
    // if(dfs_cost == 2*totalK) printf("Verification: (cost matches 2*MST).\n");

    int profit = total_sales - dfs_cost;

    printf("\nSales: ");
    for(int i=0; i<N; i++) {
    printf("%d", sales[i]);
    if(i < N-1) printf("+");
    }
   printf("\nTotal sales: %d\n", total_sales);
   printf("Travel cost: %d\n", dfs_cost);
   printf("Profit = %d - %d = %d\n", total_sales, dfs_cost, profit);;

    return 0;
}
