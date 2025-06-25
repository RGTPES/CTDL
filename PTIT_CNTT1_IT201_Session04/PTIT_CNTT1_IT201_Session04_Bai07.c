//PTIT_CNTT1_IT201_Session04_Bai07
#include <stdio.h>
#include <stdlib.h>


void search(int arr[],int n) {
    for (int i = 0;i<n/2;i++) {
        if (arr[i]==arr[n-i-1]) {
            printf("(%d,%d) ", arr[i],arr[n-i-1]);
        }
        printf("\n");
    }

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