#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adjMatrix[MAX][MAX], visited[MAX];
int n; // Number of nodes
int path[MAX]; // To store the path followed
int pathIndex = 0; // Index for the path array
int found = 0; // Flag to indicate if the node is found

void dfs(int vertex, int target) {
    visited[vertex] = 1;
    path[pathIndex++] = vertex; // Add current vertex to the path

    // Check if the current vertex is the target node
    if (vertex == target) {
        found = 1; // Set flag if the target is found
        return;
    }

    for (int i = 0; i < n; i++) {
        if (adjMatrix[vertex][i] == 1 && !visited[i]) {
            dfs(i, target);
            if (found) return; // Stop further searching if found
        }
    }

    // If not found, backtrack by removing the vertex from the path
    pathIndex--;
}

int main() {
    int i, j, edges, startVertex, targetNode;
    int u, v;

	printf("\n Depth First Search Algorithm \n \n");
    printf("Enter the number of nodes in the graph (max %d): ", MAX);
    scanf("%d", &n);
    if (n <= 0 || n > MAX) {
        printf("Invalid number of nodes.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            adjMatrix[i][j] = 0;
        }
        visited[i] = 0;
    }

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &edges);

    printf("Enter the edges (u v) for an undirected graph (0 to %d):\n", n-1);
    for (i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        if (u < 0 || u >= n || v < 0 || v >= n) {
            printf("Invalid edge (%d, %d).\n", u, v);
            return 1;
        }
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // Since the graph is undirected
    }

    printf("Enter the starting vertex for DFS (0 to %d): ", n-1);
    scanf("%d", &startVertex);
    if (startVertex < 0 || startVertex >= n) {
        printf("Invalid starting vertex.\n");
        return 1;
    }

    printf("Enter the node to search for (0 to %d): ", n-1);
    scanf("%d", &targetNode);
    if (targetNode < 0 || targetNode >= n) {
        printf("Invalid target node.\n");
        return 1;
    }

    // Reset visited array before DFS
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }
    pathIndex = 0; // Reset path index

    // Perform DFS
    dfs(startVertex, targetNode);

    if (found) {
        printf("Node %d is reachable from vertex %d. Path: ", targetNode, startVertex);
        for (int i = 0; i < pathIndex; i++) {
            printf("%d ", path[i]);
        }
        printf("\n");
    } else {
        printf("Node %d is NOT reachable from vertex %d.\n", targetNode, startVertex);
    }

    return 0;
}

