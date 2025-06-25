//PTIT_CNTT1_IT201_Session04_Bai05
#include<stdio.h>
#include <stdlib.h>


    void binarySearch(int arr[],int n) {
        for (int i=0;i<n-1;i++) {
            for (int j=i+1;j<n;j++) {
                if (arr[i]>arr[j]) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        int left = 0,right = n-1,mid;
        int searchNumber ;
        printf("Nhap so can tim trong mang : ");
        scanf("%d",&searchNumber);
        while (left<=right) {
             mid = (left+right)/2;
            if (arr[mid]==searchNumber) {
                printf("co so trong mang");
                return;
            }else if (arr[mid]<searchNumber) {
                left = mid+1;
            }else {
                right = mid-1;

            }


        }
        printf("ko co so can tim  ");


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

    binarySearch(arr,n);

    return 0;
}