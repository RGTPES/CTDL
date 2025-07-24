#include <stdio.h>

#define MAX 100

int matrix[MAX][MAX];
int adjList[MAX][MAX];
int degree[MAX];
int v;

void inputMatrix() {
    scanf("%d", &v);
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void convertToAdjList() {
    for (int i = 0; i < v; i++) {
        degree[i] = 0;
        for (int j = 0; j < v; j++) {
            if (matrix[i][j] == 1) {
                adjList[i][degree[i]++] = j;
            }
        }
    }
}

void printAdjList() {
    for (int i = 0; i < v; i++) {
        printf("%d: ", i);
        for (int j = 0; j < degree[i]; j++) {
            printf("%d -> ", adjList[i][j]);
        }
        printf("NULL\n");
    }
}

int main() {
    inputMatrix();
    convertToAdjList();
    printAdjList();
    return 0;
}
