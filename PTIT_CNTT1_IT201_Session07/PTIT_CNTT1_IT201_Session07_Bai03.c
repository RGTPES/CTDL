//PTIT_CNTT1_IT201_Session07_Bai03
#include <stdio.h>
void printArr(int arr[],int n) {
    for(int i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
}
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main() {
    int n;
    int arr[100];
    printf("moi ban nhap so luong phantu trong mang : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    insertionSort(arr,n);
    printArr(arr,n);
}
