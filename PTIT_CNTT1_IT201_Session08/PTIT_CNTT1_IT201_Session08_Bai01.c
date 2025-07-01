//PTIT_CNTT1_IT201_Session08_Bai01
#include <stdio.h>

int search(int arr[],int n) {
    int number;
    printf("moi ban nhap so can tim :");
    scanf("%d",&number);
    for (int i =0;i<n;i++) {
        if (arr[i] == number) {
            return i+1;
        }

    }
    return -1;
    // do phuc tap tgian o(n)
}
int main() {
int arr[100];
    int n;
    printf("nhap so phan tu trong mang  : ");
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    int linearSearch=search(arr,n);
    if (linearSearch==-1) {
        printf("ko ton tai phan tu");
        return 0;
    }
    printf("%d",linearSearch);


}
