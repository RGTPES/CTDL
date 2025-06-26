//PTIT_CNTT1_IT201_Session05_Bai03
#include <stdio.h>

int multiply(int n ,int i) {
    if (i>n) {
        return 1;
    }
    return i*multiply(n,i+1);
}
 int main() {
int a = multiply(5,1);
    printf("%d",a);
 }
