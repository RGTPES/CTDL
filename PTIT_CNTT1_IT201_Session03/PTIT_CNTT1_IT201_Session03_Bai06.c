//PTIT_CNTT1_IT201_Session03_Bai06
#include<stdio.h>
#include <stdlib.h>
void combineArr(int n,int *arr,int m,int arr2[]);
int main() {
    int n;
    printf("nhap so phan tu mang ban dau \n ");
    scanf("%d",&n);

    int *arr = (int*)malloc(n*sizeof(int));
    for (int i=0;i<n;i++) {
        printf("nhap phan tu thu %d \n",i);
        scanf("%d",&arr[i]);
    }
    int m;
    printf("nhap so phan tu muon them \n ");
    scanf("%d",&m);
    int *arr2 = (int*)malloc(m*sizeof(int));
    for (int i=0;i<m;i++) {
        printf("nhap phan tu them thu %d \n",i);
        scanf("%d",&arr2[i]);
    }



combineArr(n,arr,m,arr2);

}
void combineArr(int n,int *arr,int m,int arr2[]) {
    for (int i =n;i<n+m;i++) {
        arr[i] = arr2[i-n];
    }
    for (int i =0;i<n+m;i++) {
        printf("%d ",arr[i]);
    }
}