//PTIT_CNTT1_IT201_Session08_Bai02
#include <stdio.h>
void binarySearch(int arr[], int n, int left , int right,int key) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == key) {
        printf("phan tu o vi tri thu %d", mid+1);
    }if (arr[mid] > key) {
        binarySearch(arr, n, left, mid, key);
    }if (arr[mid] < key) {
        binarySearch(arr, n, mid, right, key);
    }
//do phuc tap tgian o(log n)
}
int main() {
    int arr[100];
    int n,key;
    printf("nhap so phan tu trong mang  : ");
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
printf("nhap phan tu can tim  : ");
    scanf("%d",&key);
    binarySearch(arr, n, 0, n-1, key);


}
