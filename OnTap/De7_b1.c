#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Oder {
    int id;
    char customer[100];
    int status;
    char total[100];
} Oder;

typedef struct ListOder {
    Oder oder;
    struct ListOder *next;
    struct ListOder *prev;
} LOder;

typedef struct HistoryOder {
    Oder oder;
    struct HistoryOder *next;
} HOder;

LOder *head = NULL;
HOder *historyHead = NULL;

void createOder() {
    LOder *newNode = (LOder *)malloc(sizeof(LOder));
    printf("Moi ban nhap id\n");
    scanf("%d", &newNode->oder.id);
    getchar();
    printf("Moi ban nhap ten khach hang\n");
    fgets(newNode->oder.customer, 100, stdin);
    newNode->oder.customer[strcspn(newNode->oder.customer, "\n")] = '\0';
    printf("Moi ban nhap trang thai\n");
    scanf("%d", &newNode->oder.status);
    getchar();
    printf("Moi ban nhap tong tien\n");
    fgets(newNode->oder.total, 100, stdin);
    newNode->oder.total[strcspn(newNode->oder.total, "\n")] = '\0';

    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        LOder *temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void displayOder() {
    LOder *temp = head;
    while (temp != NULL) {
        printf("ID: %d\n", temp->oder.id);
        printf("Khach hang: %s\n", temp->oder.customer);
        printf("Trang thai: %d\n", temp->oder.status);
        printf("Tong tien: %s\n", temp->oder.total);
        temp = temp->next;
    }
    HOder *his = historyHead;
    while (his != NULL) {
        printf("ID: %d\n", his->oder.id);
        printf("Khach hang: %s\n", his->oder.customer);
        printf("Trang thai: %d\n", his->oder.status);
        printf("Tong tien: %s\n", his->oder.total);
        his = his->next;
    }
}

void deleteOder() {
    int id;
    printf("Moi ban nhap id\n");
    scanf("%d", &id);
    getchar();
    LOder *temp = head;
    while (temp != NULL && temp->oder.id != id) temp = temp->next;
    if (temp == NULL) return;
    if (temp->prev != NULL) temp->prev->next = temp->next;
    else head = temp->next;
    if (temp->next != NULL) temp->next->prev = temp->prev;
    free(temp);
}

void updateOder() {
    int id;
    printf("Moi ban nhap id\n");
    scanf("%d", &id);
    getchar();
    LOder *temp = head;
    while (temp != NULL && temp->oder.id != id) temp = temp->next;
    if (temp == NULL) return;
    printf("Moi ban nhap ten khach hang\n");
    fgets(temp->oder.customer, 100, stdin);
    temp->oder.customer[strcspn(temp->oder.customer, "\n")] = '\0';
    printf("Moi ban nhap tong tien\n");
    fgets(temp->oder.total, 100, stdin);
    temp->oder.total[strcspn(temp->oder.total, "\n")] = '\0';
}

void markAsDone() {
    int id;
    printf("Moi ban nhap id\n");
    scanf("%d", &id);
    getchar();
    LOder *temp = head;
    while (temp != NULL && temp->oder.id != id) temp = temp->next;
    if (temp == NULL) return;

    HOder *newHis = (HOder *)malloc(sizeof(HOder));
    newHis->oder = temp->oder;
    newHis->next = NULL;
    if (historyHead == NULL) historyHead = newHis;
    else {
        HOder *his = historyHead;
        while (his->next != NULL) his = his->next;
        his->next = newHis;
    }
    if (temp->prev != NULL) temp->prev->next = temp->next;
    else head = temp->next;
    if (temp->next != NULL) temp->next->prev = temp->prev;
    free(temp);
}

int toInt(char *s) {
    int t = 0;
    for (int i = 0; s[i]; i++) if (s[i] >= '0' && s[i] <= '9') t = t * 10 + (s[i] - '0');
    return t;
}

void sortOder() {
    LOder *i, *j;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (toInt(i->oder.total) > toInt(j->oder.total)) {
                Oder temp = i->oder;
                i->oder = j->oder;
                j->oder = temp;
            }
        }
    }
}

void searchOder() {
    char name[100];
    printf("Moi ban nhap ten khach hang\n");
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = '\0';
    LOder *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->oder.customer, name) == 0) {
            printf("ID: %d\n", temp->oder.id);
            printf("Khach hang: %s\n", temp->oder.customer);
            printf("Trang thai: %d\n", temp->oder.status);
            printf("Tong tien: %s\n", temp->oder.total);
        }
        temp = temp->next;
    }
    HOder *his = historyHead;
    while (his != NULL) {
        if (strcmp(his->oder.customer, name) == 0) {
            printf("ID: %d\n", his->oder.id);
            printf("Khach hang: %s\n", his->oder.customer);
            printf("Trang thai: %d\n", his->oder.status);
            printf("Tong tien: %s\n", his->oder.total);
        }
        his = his->next;
    }
}

int main() {
    int choice;
    do {
        printf("\n1. Them \n");
        printf("2. Hien thi \n");
        printf("3. Xoa \n");
        printf("4. Cap nhat \n");
        printf("5. Danh dau \n");
        printf("6. Sap xep \n");
        printf("7. Tim kiem \n");
        printf("8. Thoat \n");
        printf("Moi ban nhap lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                createOder();
                break;
            case 2:
                displayOder();
                break;
            case 3:
                deleteOder();
                break;
            case 4:
                updateOder();
                break;
            case 5:
                markAsDone();
                break;
            case 6:
                sortOder();
                break;
            case 7:
                searchOder();
                break;
        }
    } while (choice != 8);
    return 0;
}