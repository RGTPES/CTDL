//PTIT_CNTT1_IT201_Session07_Bai07
#include <stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortColumn(int arr[][1000], int row, int k) {
    for (int i = 0; i < row - 1; i++) {
        for (int j = i + 1; j < row; j++) {
            if (arr[i][k] > arr[j][k]) {
                swap(&arr[i][k], &arr[j][k]);
            }
        }
    }
}


void printMatrix(int arr[][1000], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int row, col;
    int arr[1000][1000];
    int k;
        printf("Nhap so hang : ");
        scanf("%d", &row);
        printf("Nhap so cot : ");
        scanf("%d", &col);

    printf("Nhap cac phan tu cua ma tran:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

        printf("Nhap chi so cot can sap xep : ");
        scanf("%d", &k);



    sortColumn(arr, row, k);

    printMatrix(arr, row, col);

    return 0;
}

