#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

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
 printf("[\n");
 for (int i = 0; i < SIZE; i++) {
  printf(" ");
  Node* temp = adjList[i];
  if (temp == NULL) {
   printf("NULL");
  } else {
   while (temp != NULL) {
    printf("%d->", temp->vertex);
    temp = temp->next;
   }
   printf("NULL");
  }
  printf(",\n");
 }
 printf("]\n");
}

int main() {
 Node* adjList[SIZE] = {NULL};

 printGraph(adjList);

 int startNode = 1, endNode = 2;
 addEdge(adjList, startNode, endNode);
 printGraph(adjList);

 startNode = 0, endNode = 1;
 addEdge(adjList, startNode, endNode);
 printGraph(adjList);

 return 0;
}
