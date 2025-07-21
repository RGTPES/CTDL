#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int chosse;
typedef struct Course {
    int id;
    char title[100];
    int credits;
}Course;
typedef struct nodeForStudy {
    Course data;
    struct nodeForStudy* next;
}Study;
typedef struct nodeForStudyDone {
    Course data;
    struct nodeForStudyDone* next;
    struct nodeForStudyDone* prev;
}StudyDone;
int id;

void printMenu() {
    printf("1. them khoa hoc \n");
    printf("2. hien thi khoa hoc \n");
    printf("3. xoa khoa hoc \n");
    printf("4. cap nhat thong tin khoa hoc \n");
    printf("5. danh dau khoa hoc da hoan thanh \n");
    printf("6. sap xep khoa hoc theo tin chi \n");
    printf("7. tim kiem khoa hoc theo ten \n");
    printf("8. thoat chuong trinh \n");
    printf("lua chon cua ban: ");
}

void printListCourse(Study* head) {
    if (head == NULL) {
        printf("empty list\n");
        return;
    }
    Study* temp = head;
    while (temp != NULL) {
        printf("Id: %d|| title: %s || Credit: %d \n", temp->data.id, temp->data.title, temp->data.credits);
        temp = temp->next;
    }
}

Study* createCourse(Study* head) {
    Course c;
    printf("Nhap ID: ");
    scanf("%d", &c.id);
    getchar();
    printf("Nhap ten khoa hoc: ");
    fgets(c.title, 100, stdin);
    c.title[strcspn(c.title, "\n")] = '\0';
    printf("Nhap so tin chi: ");
    scanf("%d", &c.credits);
    getchar();

    Study* newNode = (Study*)malloc(sizeof(Study));
    newNode->data = c;
    newNode->next = NULL;

    if (head == NULL) {
        printf("Them khoa hoc thanh cong\n");
        return newNode;
    }

    Study* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;

    printf("Them khoa hoc thanh cong\n");
    return head;
}

Study* deleteCourse(Study* head, int id) {
    if (head == NULL) {
        printf("empty list\n");
        return head;
    }
    if (head->data.id == id) {
        Study* toDelete = head;
        head = head->next;
        free(toDelete);
        printf("Da xoa khoa hoc co ID = %d\n", id);
        return head;
    }
    Study* temp = head;
    while (temp->next != NULL && temp->next->data.id != id) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("ko co id khoa hoc can xoa ");
        return head;
    }
    Study* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
    printf("Da xoa khoa hoc co ID = %d\n", id);
    return head;
}

Study* fix(Study* head, int id) {
    if (head == NULL) {
        printf("empty list\n");
        return head;
    }
    Study* temp = head;
    while (temp != NULL && temp->data.id != id) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("ko co id khoa hoc can sua\n");
        return head;
    }

    getchar();
    printf("moi  ban nhap lai tilte: ");
    fgets(temp->data.title, 100, stdin);
    temp->data.title[strcspn(temp->data.title, "\n")] = '\0';
    printf("Moi ban nhap so tin chi: ");
    scanf("%d", &temp->data.credits);
    getchar();
    printf("Da sua thanh cong\n");
    return head;
}
Study* tickCourse(Study* head,int id) {
    if (head == NULL) {
        printf("empty list\n");
        return head;
    }
    Study* temp = head;
    while (temp != NULL && temp->data.id != id) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("ko co  khoa hoc co ID = %d\n", id);
    }



}

int main() {
    Study* head = NULL;
    do {
        printMenu();
        scanf("%d", &chosse);
        getchar();
        switch (chosse) {
            case 1:
                head = createCourse(head);
                break;
            case 2:
                printListCourse(head);
                break;
            case 3:
                printf("Nhap id can xoa ");
                scanf("%d", &id);
                getchar();
                head = deleteCourse(head, id);
                break;
            case 4:
                printf("Nhap id can sua ");
                scanf("%d", &id);
                getchar();
                head = fix(head, id);
                break;
            case 5:
                printListCourse(head);
                printf("\n");
                printf("Moi ban nhap id de danh dau da hoan thanh ");
                scanf("%d", &id);
                getchar();


                break;
        }
    } while (chosse != 8);
}
