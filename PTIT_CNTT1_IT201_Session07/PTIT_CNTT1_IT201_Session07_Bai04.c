//PTIT_CNTT1_IT201_Session07_Bai03
#include <stdio.h>
#include <string.h>

void sortString(char str[]) {
    int n = strlen(str);
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main() {
    char str[100];

    printf("Nhap chuoi: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    sortString(str);

    printf("Chuoi sau khi sap xep: %s\n", str);

    return 0;
}

