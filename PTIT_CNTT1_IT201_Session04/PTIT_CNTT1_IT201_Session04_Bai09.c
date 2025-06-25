//PTIT_CNTT1_IT201_Session04_Bai09
#include <stdio.h>
#include <stdlib.h>


void bubbleSort(int arr[], int n) {
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


int binarySearch(int arr[], int left, int right, int searchNumber) {
    if (left > right) return -1;

    int mid = (left + right) / 2;

    if (arr[mid] == searchNumber)
        return mid;
    else if (arr[mid] < searchNumber)
        return binarySearch(arr, mid + 1, right, searchNumber);
    else
        return binarySearch(arr, left, mid - 1, searchNumber);
}

int main() {
    int n;
    printf("Moi ban nhap so luong phan tu trong mang: ");
    scanf("%d", &n);

    int *arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu : ");
        scanf("%d", &arr[i]);
    }

    int searchNumber;
    printf("Nhap so can tim trong mang: ");
    scanf("%d", &searchNumber);

    bubbleSort(arr, n);

    int result = binarySearch(arr, 0, n - 1, searchNumber);

    if (result != -1)
        printf("co phan tu trong mang");
    else
        printf("Khong co phan tu trong mang");

    free(arr);
    return 0;
}


