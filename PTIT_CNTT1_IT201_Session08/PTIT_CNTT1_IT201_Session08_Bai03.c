//PTIT_CNTT1_IT201_Session08_Bai03
#include <stdio.h>
void printArr(int arr[],int n) {
    for(int i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
}
void sort(int arr[],int n) {
    if (n==1) return;
    for (int i = 0; i < n-1; i++) {
        if (arr[i] > arr[i+1]) {
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
    sort(arr,n-1);
    // do phuc tap thoi gian o(n^2)
}
int main() {
    int n;
    int arr[100];
    printf("moi ban nhap so luong phantu trong mang : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr,n);
    printArr(arr,n);
}
