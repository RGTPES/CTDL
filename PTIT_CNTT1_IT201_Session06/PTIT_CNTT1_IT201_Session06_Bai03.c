//PTIT_CNTT1_IT201_Session06_Bai03

#include <stdio.h>

int sumNum(int number) {
    if (number==0) {
        return 0;
    }
    return number %10 + sumNum(number /10);

}
int main() {
 int number;
 printf("Moi ban nhap so");
 scanf("%d",&number);
    if (number = 0) {
        printf("ko hop le");
    }
 int sum = sumNum(number);
    printf("%d",sum);
}