#include <stdio.h>
#include <stdbool.h>

#define MAX_NODE 100

int adj[MAX_NODE][MAX_NODE];
int visited[MAX_NODE];
int nodeCount;

void createGraph(int n) {
    nodeCount = n;
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }
}

void addEdge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}

void DFS(int u, int clusterID) {
    visited[u] = 1;
    printf("%d ", u);

    for (int v = 0; v < nodeCount; v++) {
        if (adj[u][v] == 1 && visited[v] == 0) {
            DFS(v, clusterID);
        }
    }
}

void cluster() {
    int clusterCounter = 1;

    for (int i = 0; i < nodeCount; i++) {
        if (visited[i] == 0) {
            printf("Cluster %d: { ", clusterCounter);
            DFS(i, clusterCounter);
            printf("}\n");
            clusterCounter++;
        }
    }
}

int main() {
    createGraph(9);

    addEdge(0, 1);
    addEdge(1, 2);

    addEdge(3, 4);
    addEdge(4, 5);
    addEdge(3, 5);

    addEdge(6, 7);
    addEdge(7, 8);

    printf("Clusters in the Graph:\n----------------------------\n");
    cluster();

    return 0;
}
