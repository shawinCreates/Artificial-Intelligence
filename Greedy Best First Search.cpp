#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

typedef struct {
    int node;
    int h;  // heuristic value
    int g;  // actual cost from the start node to the current node
} Node;

int adjMatrix[MAX][MAX];
int heuristic[MAX];
int visited[MAX];
int parent[MAX];
int n;  // Number of nodes

void initialize() {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        parent[i] = -1;  // No parent initially
    }
}

int minH(Node openList[], int openSize) {
    int minIndex = -1;
    int minHValue = INT_MAX;

    for (int i = 0; i < openSize; i++) {
        if (openList[i].h < minHValue) {
            minHValue = openList[i].h;
            minIndex = i;
        }
    }

    return minIndex;
}

void printPath(int goal) {
    if (parent[goal] == -1) {
        printf("%d ", goal);
        return;
    }
    printPath(parent[goal]);
    printf("-> %d ", goal);
}

void greedyBestFirstSearch(int start, int goal) {
    Node openList[MAX];
    int openSize = 0;
    int closedList[MAX];
    int closedSize = 0;

    Node startNode = {start, heuristic[start], 0};  // g = 0 for start node
    openList[openSize++] = startNode;

    while (openSize > 0) {
        int currentIndex = minH(openList, openSize);
        Node currentNode = openList[currentIndex];

        if (currentNode.node == goal) {
            printf("Goal node %d found with total path cost %d\n", goal, currentNode.g);
            printf("Path followed: ");
            printPath(goal);
            printf("\n");
            return;
        }

        // Move the current node to the closed list
        closedList[closedSize++] = currentNode.node;
        visited[currentNode.node] = 1;

        // Remove the current node from the open list
        for (int i = currentIndex; i < openSize - 1; i++) {
            openList[i] = openList[i + 1];
        }
        openSize--;

        // Explore neighbors
        for (int i = 0; i < n; i++) {
            if (adjMatrix[currentNode.node][i] != 0 && !visited[i]) {
                int g = currentNode.g + adjMatrix[currentNode.node][i];  // Calculate new g value

                // Check if the node is already in the open list
                int inOpenList = 0;
                for (int j = 0; j < openSize; j++) {
                    if (openList[j].node == i && openList[j].h > heuristic[i]) {
                        openList[j].h = heuristic[i];
                        openList[j].g = g;
                        parent[i] = currentNode.node;  // Set the parent of this node
                        inOpenList = 1;
                        break;
                    }
                }

                if (!inOpenList) {
                    Node neighborNode = {i, heuristic[i], g};
                    openList[openSize++] = neighborNode;
                    parent[i] = currentNode.node;  // Set the parent of this node
                }
            }
        }
    }

    printf("Goal node %d not reachable from node %d\n", goal, start);
}

int main() {
    int edges, start, goal;
    int u, v, cost;

	printf("\n Greedy Best First Search Algorithm \n \n");
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &n);

    initialize();

    // Initialize the adjacency matrix and heuristic
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adjMatrix[i][j] = 0;
        }
        heuristic[i] = 0;
    }

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &edges);

    printf("Enter the edges (u v cost) for a directed graph:\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &u, &v, &cost);
        adjMatrix[u][v] = cost;
    }

    printf("Enter the heuristic values for each node:\n");
    for (int i = 0; i < n; i++) {
        printf("Heuristic value for node %d: ", i);
        scanf("%d", &heuristic[i]);
    }

    printf("Enter the start node: ");
    scanf("%d", &start);

    printf("Enter the goal node: ");
    scanf("%d", &goal);

    // Perform Greedy Best-First Search
    greedyBestFirstSearch(start, goal);

    return 0;
}

