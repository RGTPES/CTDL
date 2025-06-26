//PTIT_CNTT1_IT201_Session05_Bai06
#include <stdio.h>
int sumArr(int arr[],int n,int i) {
    if (i>=n) {
        return 0;
    }
    return arr[i] + sumArr(arr,n,i+1);
}

int main() {
    int arr[100];
    int n;
    printf("Nhap so luong phan tu cho mang : ");
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        scanf("%d",&arr[i]);

    }
    int sum = sumArr(arr,n,0);
    printf("So luong phan tu cho mang : %d",sum);
}