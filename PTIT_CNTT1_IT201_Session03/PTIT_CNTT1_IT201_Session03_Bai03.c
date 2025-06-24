//PTIT_CNTT1_IT201_Session03_Bai03
#include<stdio.h>
#include <stdlib.h>
void evenAverage(int arr[],int n,int arr2[]);



int main() {

    int n;
    printf("nhap so luong phan tu trong mang: ");
    scanf("%d",&n);
    int *arr=(int *)malloc(sizeof(int)*n);
    int arr2[1000];
    for(int i=0;i<n;i++) {
        printf("nhap phan tu trong mang: ");
        scanf("%d",&arr[i]);
    }
    evenAverage(arr,n,arr2);
    free(arr);
}

void evenAverage(int arr[],int n, int arr2[]) {
    int j =0;
    int average = 0;
    for(int i=0;i<n;i++) {
        if(arr[i]%2==0) {
            arr2[j]=arr[i];
            j++;
        }
    }
    for(int i=0;i<j;i++) {
         average += arr2[i];
        if (i==j-1) {
            average = average/j;
            printf("%d ",average);
        }
    }


}
