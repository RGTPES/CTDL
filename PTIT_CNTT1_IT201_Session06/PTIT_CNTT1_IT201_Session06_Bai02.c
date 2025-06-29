//PTIT_CNTT1_IT201_Session06_Bai02
#include <stdio.h>

void fibonaci(int arr[], int n, int first, int second, int i) {
    if (i >= n) {
        return;
    }
    arr[i] = first;
    fibonaci(arr, n, second, first + second, i + 1);
    printf("%d ", first);
}

int main() {
    int arr[100];
    int n;
    printf("Nhap so luong phan tu cho mang: ");
    scanf("%d", &n);

    fibonaci(arr, n, 1, 1, 0);

    return 0;
}
