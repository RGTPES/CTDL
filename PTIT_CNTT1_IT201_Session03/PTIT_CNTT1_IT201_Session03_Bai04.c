//PTIT_CNTT1_IT201_Session03_Bai04
#include<stdio.h>
#include <stdlib.h>

void max(int **arr,int row,int cols);
void min(int **arr,int row,int cols);
int main() {
    int row;
    int cols;
    printf("Nhap so hang : ");
    scanf("%d", &row);
    printf("Nhap so cot : ");
    scanf("%d", &cols);
    int n = row;
    int **arr = (int**)malloc(row*sizeof(int*));
    for (int i = 0; i < row; i++) {
        arr[i] = (int*)malloc(cols*sizeof(int));
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < cols; j++) {
            printf("moi ban nhap gia tri arr[%d][%d]: ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }

    max(arr,row,cols);
    min(arr,row,cols);


    for (int i = 0; i < row; i++) {
        free(arr[i]);
    }
    free(arr);
}
void max(int **arr,int row,int cols) {
    int max = arr[0][0];
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < cols; j++) {
            if(arr[i][j] > max) {
                max = arr[i][j];
            }
        }
    }
    printf("so lon nhat trong mang la %d \n ",max);
}
void min(int **arr,int row,int cols) {
    int min = arr[0][0];
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < cols; j++) {
            if(arr[i][j] < min) {
                min = arr[i][j];
            }
        }
    }
    printf("so nho nhat trong mang la %d \n ",min);
}