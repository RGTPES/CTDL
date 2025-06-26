//PTIT_CNTT1_IT201_Session05_Bai04
#include <stdio.h>
int sumSpace(int first, int second ) {
    if (first<0|| second<0) {
        printf("ko hop le ");
        return 0;
    }
    if (first > second ) {
        return 0;
    }
    return first + sumSpace(first+1, second);

}
int main() {
int a = sumSpace(3, 6);
    if (a==0) return 0;
    printf("%d\n", a);

}
