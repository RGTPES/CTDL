//PTIT_CNTT1_IT201_Session06_Bai05


#include <stdio.h>

int maxNum(int arr[],int n ,int i,int *max,int *min) {
    if (i>=n) {
        return 0;
    }
    if (arr[i]>*max) {
        *max = arr[i];
    }
    if (arr[i]<*min) {
        *min = arr[i];
    }
    maxNum(arr,n,i+1,max,min);



}


int  main() {
    int arr[100];
    int number;
    printf("Nhap so luong phan tu trong mang : ");
    scanf("%d", &number);
    for (int i = 0; i < number; i++) {
        scanf("%d", &arr[i]);
    }
    int max = arr[0];
    int min = arr[0];
    maxNum(arr,number,0,&max,&min);
    printf("max : %d \n" ,max);
    printf("min : %d \n",min);
}
