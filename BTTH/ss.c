//PTIT_CNTT1_IT201_Session22_Bai01
#include<stdio.h>
#include<stdlib.h>

#define SIZE 4

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node* adjList[], int u, int v) {
    Node* newNodeV = createNode(v);
    newNodeV->next = adjList[u];
    adjList[u] = newNodeV;

    Node* newNodeU = createNode(u);
    newNodeU->next = adjList[v];
    adjList[v] = newNodeU;
}
void printGraph(Node* adjList[]) {
    for (int i = 0; i < SIZE; i++) {
        printf("Vertex %d -> ", i);
        Node* temp = adjList[i];
        while (temp != NULL) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}
void DFSUtil(Node* adjList[], int src, int* visited) {
    visited[src] = 1;
    printf("%d ", src);

    Node* temp = adjList[src];
    while (temp != NULL) {
        int v = temp->vertex;
        if (!visited[v]) {
            DFSUtil(adjList, v, visited);
        }
        temp = temp->next;
    }
}
void DFS(Node* adjList[], int src) {
    int* visited = (int*)calloc(SIZE, sizeof(int));
    printf("DFS từ đỉnh %d:\n", src);
    DFSUtil(adjList, src, visited);
    free(visited);
}
int main() {
    Node* adjList[SIZE] = {NULL};
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 0, 3);
    addEdge(adjList, 1, 3);
    printGraph(adjList);


    return 0;
}