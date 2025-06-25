//PTIT_CNTT1_IT201_Session04_Bai03
#include<stdio.h>
#include <stdlib.h>
void search(int arr[],int n) {
    int min = arr[0];
    int index = 0;
    for(int i=0;i<n;i++) {
        if (arr[i]<min) {
            min = arr[i];
            index = i;
            break;
        }
    }

    printf(" %d ",index);


}
int main() {
    int n;
    printf("Moi ban nhap o luong phan tu trong mang: ");
    scanf("%d",&n);
    int *arr = (int*)malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu trong mang: ");
        scanf("%d",&arr[i]);
    }
    search(arr,n);
    return 0;
}