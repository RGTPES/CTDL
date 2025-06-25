//PTIT_CNTT1_IT201_Session04_Bai08
#include <stdio.h>
#include <stdlib.h>

void search(int arr[],int n) {
    int searchNumber=0;
    int number;
    int index=0;
    printf("Nhap so can tim :");
    scanf("%d",&searchNumber);
    for(int i=0;i<n;i++) {
        if (arr[i]==searchNumber) {
            number = arr[i];
            index = i;
            printf(" %d",index);
        }


    }

    if (!number) {
        printf("khong co so trong mang" );
    }



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
    search(arr,n);
    return 0;
}