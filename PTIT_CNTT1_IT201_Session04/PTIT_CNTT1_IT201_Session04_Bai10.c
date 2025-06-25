//PTIT_CNTT1_IT201_Session04_Bai09
#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<string.h>
#include<stdbool.h>
struct student{
    char id[100];
    char name[100];
    int age;
};

bool upperCase(char str1[],char str2[]) {
    char arr1[1000];
    char arr2[1000];
    strcpy(arr1,str1);
    strcpy(arr2,str2);
    for (int i =0 ;i < strlen(str1);i++) {
        arr1[i] = toupper(arr1[i]);
    }
    for (int i =0 ;i < strlen(str2);i++) {
        arr2[i] = toupper(arr2[i]);
    }
    return (strstr(arr1,arr2)) ;




}

int main() {
    char search[100];
    bool check;
    int n;
    printf("Nhap so hoc sinh : ");
    scanf("%d",&n);
struct student newStudent[100];
    for (int i =0; i < n; i++) {
        printf("nhap id hoc sinh thu %d \n", i+1);
        scanf("%s", &newStudent[i].id);
        printf("nhap ten hoc sinh thu %d \n", i+1);
        scanf("%s", &newStudent[i].name);
        printf("nhap tuoi hoc sinh thu %d \n", i+1);
        scanf("%d", &newStudent[i].age);
    }
    printf("nhap ki tu \n");
    scanf("%s",search);
    for (int i =0; i < n; i++) {
        if (upperCase(newStudent[i].name,search) ) {
        printf("ID:%s,Name:%s,Age:%d, \n",newStudent[i].id,newStudent[i].name,newStudent[i].age);
            check = true;        }
    }
    if (!check) {
        printf("ko tim thay");
    }


}

