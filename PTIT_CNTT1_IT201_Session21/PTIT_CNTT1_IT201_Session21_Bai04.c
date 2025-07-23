//PTIT_CNTT1_IT201_Session21_Bai04
#include <stdio.h>
#define SIZE  3

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
void addEdge(int graph[SIZE][SIZE], int u, int v) {
    graph[u][v] = 1;
}

int main() {
    int graph[SIZE][SIZE];
    init(graph);
    addEdge(graph, 1, 0);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);


    printGraph(graph);
}
