//PTIT_CNTT1_IT201_Session08_Bai07
#include <stdio.h>
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[],int left,int right) {
    int pivot = arr[right];
    int i = left-1;
    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }

    }
    swap(&arr[i+1], &arr[right]);
    return i+1;

}
void quickSort(int arr[],int left,int right) {
    if (left < right) {
        int pivot = partition(arr,left,right);
        quickSort(arr,left,pivot-1);
        quickSort(arr,pivot+1,right);
    }

}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;
    int arr[100];
    printf("moi ban nhap so phan tu : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n - 1);


    printArray(arr, n);

    return 0;
}

