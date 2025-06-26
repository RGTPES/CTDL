//PTIT_CNTT1_IT201_Session05_Bai08

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int  convertToNum(char arr[],int n ) {
    if (n==0) {

        return 0;
    }
    return arr[n-1] - '0' +10 * convertToNum(arr,n-1);
}

int main() {
    int flag = 0;
    char arr[100];
        fgets(arr,100,stdin);
    arr[strcspn(arr,"\n")] = "\0";
    for (int i =0;i<strlen(arr);i++) {
        if (isalpha(arr[i])) {
            flag = 1;
        }
    }
    if (!flag) {
        printf("%d",convertToNum(arr,strlen(arr)));
    }else {
        printf("ko hop le ");
    }






}
