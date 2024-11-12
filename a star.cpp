#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

typedef struct {
    int node;
    int f, g, h; // f = g + h
} Node;

int adjMatrix[MAX][MAX];
int heuristic[MAX];
int visited[MAX];
int parent[MAX];
int n; // Number of nodes

void initialize() {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        parent[i] = -1; // No parent initially
    }
}

int minF(Node openList[], int openSize) {
    int minIndex = -1;
    int minFValue = INT_MAX;

    for (int i = 0; i < openSize; i++) {
        if (openList[i].f < minFValue) {
            minFValue = openList[i].f;
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

void aStar(int start, int goal) {
    Node openList[MAX];
    int openSize = 0;
    int closedList[MAX];
    int closedSize = 0;

    Node startNode = {start, heuristic[start], 0, heuristic[start]};
    openList[openSize++] = startNode;

    while (openSize > 0) {
        int currentIndex = minF(openList, openSize);
        Node currentNode = openList[currentIndex];

        if (currentNode.node == goal) {
            printf("Goal node %d found with total cost %d\n", goal, currentNode.f);
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
                int g = currentNode.g + adjMatrix[currentNode.node][i];
                int h = heuristic[i];
                int f = g + h;

                // Check if the node is already in the open list
                int inOpenList = 0;
                for (int j = 0; j < openSize; j++) {
                    if (openList[j].node == i && openList[j].f > f) {
                        openList[j].f = f;
                        openList[j].g = g;
                        openList[j].h = h;
                        parent[i] = currentNode.node; // Set the parent of this node
                        inOpenList = 1;
                        break;
                    }
                }

                if (!inOpenList) {
                    Node neighborNode = {i, f, g, h};
                    openList[openSize++] = neighborNode;
                    parent[i] = currentNode.node; // Set the parent of this node
                }
            }
        }
    }

    printf("Goal node %d not reachable from node %d\n", goal, start);
}

int main() {
    int edges, start, goal;
    int u, v, cost;

	printf("\n A* Searching Algorithm \n \n");
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

    // Perform A* search
    aStar(start, goal);

    return 0;
}

