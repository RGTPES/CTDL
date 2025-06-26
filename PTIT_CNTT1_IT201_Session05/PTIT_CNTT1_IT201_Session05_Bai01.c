// PTIT_CNTT1_IT201_Session05_Bai01
#include <stdio.h>

void print(int n, int i) {
    if (i > n) {
        return;
    }
    printf("%d\n", i);
    print(n, i + 1);
}

int main() {
    int n = 5;
    print(n, 1);
    return 0;
}
