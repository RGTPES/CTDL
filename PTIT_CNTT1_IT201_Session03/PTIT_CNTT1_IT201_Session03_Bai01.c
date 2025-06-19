//PTIT_CNTT1_IT201_Session03_Bai01
#include<stdio.h>
#include <stdlib.h>
int main() {
    int n;
    printf("nhap so luong phan tu trong mang: ");
    scanf("%d",&n);
    int *arr=(int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++) {
        printf("nhap phan tu trong mang: ");
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
    free(arr);

}

