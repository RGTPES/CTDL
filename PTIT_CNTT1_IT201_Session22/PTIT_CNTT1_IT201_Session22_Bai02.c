//PTIT_CNTT1_IT201_Session22_Bai02
#include <stdio.h>
#define SIZE  5

void init(int graph[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            graph[i][j] = 0;
        }
    }
}
void printGraph(int graph[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}
void printConnected(int graph[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        printf("%d: ", i);
        for (int j = 0; j < SIZE; j++) {
            if (graph[i][j] == 1) {
                printf("%d ",j);
            }
        }
        printf("\n");
    }
}
void addEdge(int graph[SIZE][SIZE], int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

int main() {
    int graph[SIZE][SIZE];
    init(graph);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 3, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 3, 4);

    printConnected(graph);
}
