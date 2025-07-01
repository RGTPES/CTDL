#include <stdio.h>

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
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

int search(int arr[], int n) {
    int number;

    printf("moi ban nhap so can tim :");
    scanf("%d", &number);
    for (int i = 0; i < n; i++) {
        if (arr[i] == number) {
            return i + 1;
        }
    }
    return -1;
}

int binarySearch(int arr[], int left, int right, int key) {
    if (left > right) {
        return -1;
    }
    int mid = left + (right - left) / 2;
    if (arr[mid] == key) {
        return mid + 1;
    } else if (arr[mid] > key) {
        return binarySearch(arr, left, mid - 1, key);
    } else {
        return binarySearch(arr, mid + 1, right, key);
    }
}

int main() {
    int n;
    int arr[100];
    printf("moi ban nhap so phan tu : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, n);
    printArr(arr, n);

    int searchKey = search(arr, n);
    if (searchKey == -1) {
        printf("khong thay phan tu trong mang\n");
    } else {
        printf("%d\n", searchKey);
    }

    int key;
    printf("moi ban nhap so can tim (binarySearch): ");
    scanf("%d", &key);
    int result = binarySearch(arr, 0, n - 1, key);
    if (result == -1) {
        printf("khong  thay phan tu trong mang\n");
    } else {
        printf("phan tu o vi tri thu %d\n", result);
    }

    return 0;
}
