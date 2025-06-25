//PTIT_CNTT1_IT201_Session04_Bai06
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct newStudent {
    char id[100];
    char name[100];
    int age;
};

int main() {
    char id[100];
    int flag = 0;

    struct newStudent students[5] = {
        {"1", "Alice", 20},
        {"2", "Bob", 21},
        {"3", "Charlie", 22},
        {"4", "David", 20},
        {"5", "Eva", 23}
    };

    printf("Nhap id can tim: ");
    scanf("%s", id);

    for (int i = 0; i < 5; i++) {
        if (strcmp(id, students[i].id) == 0) {
            printf("ID: %s, Name: %s, Age: %d\n", students[i].id, students[i].name, students[i].age);
            flag = 1;
            break;
        }
    }

    if (!flag) {
        printf("Khong co hoc sinh co ID = %s\n", id);
    }

    return 0;
}
