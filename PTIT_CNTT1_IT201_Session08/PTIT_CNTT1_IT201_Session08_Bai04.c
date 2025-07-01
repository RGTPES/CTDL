//PTIT_CNTT1_IT201_Session08_Bai04
#include<stdio.h>
void printArr(int arr[],int n) {
    for(int i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
}
void selectionSort(int arr[],int n) {
    int minindex = 0;
    for(int i=0;i<n-1;i++) {
        minindex = i;
        for(int j=i+1;j<n;j++) {
            if (arr[j] < arr[minindex]) {
                minindex = j;
            }
        }
        if (minindex != i) {
            int temp = arr[i];
            arr[i] = arr[minindex];
            arr[minindex] = temp;
        }
    }
    //do phuc tap tgian o(n^2)
}
int main() {
    int n;
    int arr[100];
    printf("moi ban nhap so luong phantu trong mang : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    selectionSort(arr,n);
    printArr(arr,n);
}


