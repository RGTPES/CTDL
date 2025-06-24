//PTIT_CNTT1_IT201_Session03_Bai05
#include<stdio.h>
#include <stdlib.h>

void diagonal(int **arr,int row,int cols);
void antiDiagonal(int **arr,int row,int cols);


int main() {
    int row,cols;
    printf("nhap so hang :  ");
    scanf("%d",&row);
    printf("nhap so hang :  ");
    scanf("%d",&cols);
    if (row<=0||cols<=0) {
        if (row<=0&&cols<=0) printf("so hang va so cot ko hop le");
        else if (row<=0)printf("so hang ko hop le ");
        else   printf("so cot ko hop le ");
        return 0;

    }
    int **arr = (int**)malloc(row*sizeof(int*));
    for(int i = 0; i < row; i++) {
        arr[i] = (int*)malloc(cols*sizeof(int));
    }
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < cols; j++) {
            printf("moi ban nhap gia tri arr[%d][%d]: ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
    diagonal(arr,row,cols);
    antiDiagonal(arr,row,cols);
}
void diagonal(int **arr,int row,int cols) {
    if (row!=cols) {
        printf("ma tran khong co duong cheo chinh \n ");
        return;
    }
    int sum = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < cols; j++) {
            if (i==j) {
                sum += arr[i][j];
            }
        }
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("diagonal = %d\n",sum);
}
void antiDiagonal(int **arr,int row,int cols) {
    if (row!=cols) {
        printf("ma tran khong co duong cheo phu \n ");
        return;
    }
    int sum = 0;
    for (int i = 0; i < row; i++) {
        sum += arr[i][cols-1-i];
    }
}