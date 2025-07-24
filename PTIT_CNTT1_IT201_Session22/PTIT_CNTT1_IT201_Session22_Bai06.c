//PTIT_CNTT1_IT201_Session22_Bai06
#include <stdio.h>
#define MAX 100

int graph[MAX][MAX];
int visited[MAX];

void DFS(int v, int n) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && visited[i] == 0) {
            DFS(i, n);
        }
    }
}

int main() {
    int v, e;
    printf("Nhap so dinh  va so canh : ");
    scanf("%d %d", &v, &e);
    for (int i = 0; i < v; i++) {
        visited[i] = 0;
        for (int j = 0; j < v; j++) {
            graph[i][j] = 0;
        }
    }
    printf("Nhap  %d canh :\n", e);
    for (int i = 0; i < e; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        graph[u][w] = 1;
        graph[w][u] = 1;
    }
int start;
    printf("Nhap canh bat dau: ");
    scanf("%d", &start);
    DFS(start, v);
    printf("\n");

    return 0;
}
