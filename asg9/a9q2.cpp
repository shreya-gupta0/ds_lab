#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define INF 99999

int graph[MAX][MAX];
int adj[MAX][MAX];
int V, E;
int visited[MAX];

// ===== 1. BFS =====
void bfs(int start) {
    int queue[MAX], front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = 1;
    
    printf("BFS: ");
    while(front < rear) {
        int u = queue[front++];
        printf("%d ", u);
        for(int v = 0; v < V; v++) {
            if(graph[u][v] && !visited[v]) {
                queue[rear++] = v;
                visited[v] = 1;
            }
        }
    }
    printf("\n");
}

// ===== 2. DFS =====
void dfs(int u) {
    visited[u] = 1;
    printf("%d ", u);
    for(int v = 0; v < V; v++) {
        if(graph[u][v] && !visited[v]) dfs(v);
    }
}

void dfsAll(int start) {
    printf("DFS: ");
    for(int i = 0; i < V; i++) visited[i] = 0;
    dfs(start);
    printf("\n");
}

// ===== 3. Kruskal MST =====
int parent[MAX];
int find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void kruskal() {
    int edges[MAX][3], e = 0;
    for(int i = 0; i < V; i++) parent[i] = i;
    
    // Collect edges
    for(int i = 0; i < V; i++)
        for(int j = i+1; j < V; j++)
            if(adj[i][j] != INF) edges[e][0] = i, edges[e][1] = j, edges[e++][2] = adj[i][j];
    
    // Sort edges (simple bubble)
    for(int i = 0; i < e-1; i++)
        for(int j = 0; j < e-i-1; j++)
            if(edges[j][2] > edges[j+1][2]) {
                int t[3]; for(int k=0;k<3;k++) t[k]=edges[j][k],edges[j][k]=edges[j+1][k],edges[j+1][k]=t[k];
            }
    
    printf("Kruskal MST: ");
    int mst_cost = 0;
    for(int i = 0; i < e; i++) {
        int u = find(edges[i][0]), v = find(edges[i][1]);
        if(u != v) {
            parent[u] = v;
            printf("(%d-%d:%d) ", edges[i][0], edges[i][1], edges[i][2]);
            mst_cost += edges[i][2];
        }
    }
    printf("(Cost: %d)\n", mst_cost);
}

// ===== 4. Prim MST =====
void prim() {
    int key[MAX], mst[MAX], inMST[MAX] = {0};
    for(int i = 0; i < V; i++) key[i] = INF, mst[i] = -1;
    key[0] = 0;
    
    printf("Prim MST: ");
    int cost = 0;
    for(int count = 0; count < V; count++) {
        int u = -1, min = INF;
        for(int i = 0; i < V; i++)
            if(!inMST[i] && key[i] < min) min = key[i], u = i;
        
        inMST[u] = 1; cost += key[u];
        printf("(%d) ", u);
        
        for(int v = 0; v < V; v++)
            if(graph[u][v] && !inMST[v] && graph[u][v] < key[v])
                key[v] = graph[u][v];
    }
    printf("(Cost: %d)\n", cost);
}

// ===== 5. Dijkstra =====
void dijkstra(int start) {
    int dist[MAX], visited[MAX] = {0};
    for(int i = 0; i < V; i++) dist[i] = INF;
    dist[start] = 0;
    
    printf("Dijkstra from %d: ", start);
    for(int count = 0; count < V; count++) {
        int u = -1, min = INF;
        for(int i = 0; i < V; i++)
            if(!visited[i] && dist[i] < min) min = dist[i], u = i;
        
        visited[u] = 1;
        printf("%d(%d) ", u, dist[u]);
        
        for(int v = 0; v < V; v++)
            if(graph[u][v] && !visited[v] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    printf("\n");
}

int main() {
    printf("Enter V E: ");
    scanf("%d %d", &V, &E);
    
    // Initialize
    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++) graph[i][j] = adj[i][j] = 0;
    
    // Read weighted edges
    for(int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = graph[v][u] = w;  // Undirected
        adj[u][v] = adj[v][u] = w;
    }
    
    // Run all algorithms
    printf("\n--- RESULTS ---\n");
    bfs(0); dfsAll(0);
    kruskal(); prim(); dijkstra(0);
    
    return 0;
}
