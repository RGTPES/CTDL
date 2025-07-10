#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char* data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
    int cap;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    q->cap = 100;
    return q;
}

Node* createNode(char* data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = strdup(data);
    node->next = NULL;
    return node;
}

Queue* enQueue(Queue* q, char* data) {
    if (q->size >= q->cap) {
        printf("full\n");
        return q;
    }
    Node* newNode = createNode(data);
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
    return q;
}

Queue* deQueue(Queue* q) {
    if (q->front == NULL) {
        printf("Hang doi rong\n");
        return q;
    }
    Node* temp = q->front;
    printf("Dang phuc vu khach hang: %s\n", temp->data);
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp->data);
    free(temp);
    q->size--;
    return q;
}

void printQueue(Queue* q) {
    if (q->front == NULL) {
        printf("Danh sach rong\n");
        return;
    }
    Node* temp = q->front;
    while (temp != NULL) {
        printf("%s\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    Queue* queueOld = createQueue();
    Queue* queueNormal = createQueue();
    int choice;

    do {
        printf("1. Them khach hang\n");
        printf("2. Phuc vu\n");
        printf("3. Hien thi danh sach\n");
        printf("4. Thoat\n");
        printf("Moi ban chon: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: {
                char name[100];
                int age;
                printf("Nhap ten khach hang: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                printf("Nhap tuoi khach hang: ");
                scanf("%d", &age);
                getchar();
                if (age >= 60) {
                    queueOld = enQueue(queueOld, name);
                } else {
                    queueNormal = enQueue(queueNormal, name);
                }
                break;
            }
            case 2: {
                if (queueOld->front != NULL) {
                    queueOld = deQueue(queueOld);
                } else if (queueNormal->front != NULL) {
                    queueNormal = deQueue(queueNormal);
                } else {
                    printf("Khong co khach\n");
                }
                break;
            }
            case 3:
                printQueue(queueOld);
                printQueue(queueNormal);
                break;
            case 4:
                printf("Thoat\n");
                break;
            default:
                printf("Nhap lai\n");
        }
    } while (choice != 4);

    return 0;
}
