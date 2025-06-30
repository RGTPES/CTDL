//PTIT_CNTT1_IT201_Session07_Bai02
#include <stdio.h>
void printArr(int arr[],int n) {
    for(int i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
}
void sortSelection(int arr[],int n) {
int minIndex=0;
    for(int i=0;i<n-1;i++) {
        minIndex = i;
        for(int j=i+1;j<n;j++) {
            if(arr[j]<arr[minIndex]) {
                minIndex=j;

            }
        }
        if (minIndex!=i) {
            int temp=arr[i];
            arr[i]=arr[minIndex];
            arr[minIndex]=temp;
        }
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
    sortSelection(arr,n);
    printArr(arr,n);


}
