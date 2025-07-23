//PTIT_CNTT1_IT201_Session21_Bai01
#include <stdio.h>

void init(int graph[3][3]) {
for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        graph[i][j] = 0;
    }
}
}
void printGraph(int graph[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}
void addEdge(int graph[3][3], int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

int main() {
int graph[3][3];
    init(graph);
    addEdge(graph, 1, 2);

    printGraph(graph);
}
