// PTIT_CNTT1_IT201_Session05_Bai01

#include <stdio.h>

int summ (int n, int i) {

    if (i > n) {
        return 0;
    }
return i + summ(n, i+1);

}
int main() {

    int res=summ(5,1);
    printf("%d",res);
}