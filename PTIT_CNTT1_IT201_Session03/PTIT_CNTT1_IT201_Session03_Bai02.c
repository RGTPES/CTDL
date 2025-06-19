//PTIT_CNTT1_IT201_Session03_Bai02
#include<stdio.h>
#include <stdlib.h>
void maxNumber(int arr[],int n) {
    int max=arr[0];
    for(int i=0;i<n;i++) {
        if(arr[i]>max) {
            max=arr[i];

        }
    }
    printf("max trong mang = %d\n",max);
}
int main() {
    int n;
    printf("nhap so luong phan tu trong mang: ");
    scanf("%d",&n);
    int *arr=(int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++) {
        printf("nhap phan tu trong mang: ");
        scanf("%d",&arr[i]);
    }
    maxNumber(arr,n);
    free(arr);
}
