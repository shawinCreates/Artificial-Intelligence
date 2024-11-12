#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;
int adjMatrix[MAX][MAX], visited[MAX];
int n; // Number of nodes

void enqueue(int vertex) {
    if (rear == MAX - 1)
        printf("Queue Overflow\n");
    else {
        if (front == -1)
            front = 0;
        queue[++rear] = vertex;
    }
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return -1;
    } else {
        int vertex = queue[front++];
        if (front > rear)
            front = rear = -1;
        return vertex;
    }
}

int isQueueEmpty() {
    return front == -1;
}

void bfs(int startVertex, int targetVertex) {
    int i, currentVertex;
    
    visited[startVertex] = 1;
    enqueue(startVertex);

    printf("Breadth-First Search starting from vertex %d:\n", startVertex);

    while (!isQueueEmpty()) {
        currentVertex = dequeue();
        printf("%d ", currentVertex);

        // Check if we've found the target vertex
        if (currentVertex == targetVertex) {
            printf("\nTarget vertex %d found!\n", targetVertex);
            return;
        }

        for (i = 0; i < n; i++) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    printf("\nTarget vertex %d not found in the graph.\n", targetVertex);
}

int main() {
    int i, j, edges, startVertex, targetVertex;
    int u, v;

	printf("\n BFS Algorithm \n \n");
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid number of nodes. Must be between 1 and %d.\n", MAX);
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

    printf("Enter the edges (u v) for an undirected graph:\n");
    for (i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        if (u < 0 || u >= n || v < 0 || v >= n) {
            printf("Invalid edge (%d, %d). Vertices must be between 0 and %d.\n", u, v, n - 1);
            i--; // Decrement i to re-enter the edge
            continue;
        }
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // Undirected graph
    }

    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    if (startVertex < 0 || startVertex >= n) {
        printf("Invalid starting vertex. Must be between 0 and %d.\n", n - 1);
        return 1;
    }

    printf("Enter the target vertex to search for: ");
    scanf("%d", &targetVertex);

    if (targetVertex < 0 || targetVertex >= n) {
        printf("Invalid target vertex. Must be between 0 and %d.\n", n - 1);
        return 1;
    }

    bfs(startVertex, targetVertex);

    return 0;
}

