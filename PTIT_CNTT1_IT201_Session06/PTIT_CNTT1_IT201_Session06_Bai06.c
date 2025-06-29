//PTIT_CNTT1_IT201_Session06_Bai06

#include <stdio.h>

int soBuoc(int a) {
if (a==0) return 1;
    if (a<0) return 0;
    return soBuoc(a-1)+soBuoc(a-2);

}

int main() {
    int a;
    printf("nhap so buoc: ");
    scanf("%d",&a);
    soBuoc(a);
}

