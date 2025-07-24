#include <stdio.h>
#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = value;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int isEmpty() {
    return front == -1 || front > rear;
}

void BFS(int start, int n) {
    visited[start] = 1;
    enqueue(start);
    printf("%d ", start);
    while (!isEmpty()) {
        int current = dequeue();
        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                printf("%d ", i);
                enqueue(i);
            }
        }
    }
}

int main() {
    int v, e;
    scanf("%d %d", &v, &e);
    for (int i = 0; i < v; i++) {
        visited[i] = 0;
        for (int j = 0; j < v; j++) {
            graph[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        graph[u][w] = 1;
        graph[w][u] = 1;
    }
    int start;
    scanf("%d", &start);
    BFS(start, v);
    printf("\n");
    return 0;
}
