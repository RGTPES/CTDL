//PTIT_CNTT1_IT201_Session06_Bai01

#include <stdio.h>

void binaryNumber(int number) {
    if (number == 0) {
        return;
    }

    int rem = number % 2;
    int numberAfter = number / 2;
    binaryNumber(numberAfter);
    printf("%d", rem);

}

int main() {
    int number ;
    printf("Enter a number : ");
    scanf("%d", &number);
    binaryNumber(number);
}


