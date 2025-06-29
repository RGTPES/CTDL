//PTIT_CNTT1_IT201_Session06_Bai04
#include <stdio.h>

void thapHN(int n, char a, char b, char c) {
    if (n==1) {
        printf("Dia %d di chuyen tu %c sang %c \n", n , a , c);
        return;
    }
    thapHN(n-1,a,c,b);
    printf("Dia %d di chuyen tu %c sang %c \n", n , a , c);
    thapHN(n-1,b,a,c);
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n<=0) {
        printf("Input invalid");
        return 0;
    }else {
        thapHN(n, 'A', 'B', 'C');
    }
    return 0;
}