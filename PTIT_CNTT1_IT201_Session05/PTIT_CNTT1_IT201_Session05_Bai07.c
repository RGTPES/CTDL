//PTIT_CNTT1_IT201_Session05_Bai07
#include <stdio.h>

void fibonaci(int arr[], int n, int first, int second, int i) {
    if (i >= n) {
        return;
    }
    arr[i] = first;
    printf("%d ", first);
    fibonaci(arr, n, second, first + second, i + 1);
}

int main() {
    int arr[100];
    int n;
    printf("Nhap so luong phan tu cho mang: ");
    scanf("%d", &n);

    fibonaci(arr, n, 0, 1, 0);

    return 0;
}
