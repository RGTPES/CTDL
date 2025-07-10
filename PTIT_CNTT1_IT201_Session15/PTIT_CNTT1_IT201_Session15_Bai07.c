//PTIT_CNTT1_IT201_Session15_Bai07
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct Node {
    char* data;
    struct Node* next;
}Node;
typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
    int cap;
}Queue;
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

void isEmpty(Queue* q) {
    if (q->size == 0) {
        printf("true\n");
    }else {
        printf("false\n");
    }
}
void printQueue(Queue* q) {
    if (q->front == NULL) {
        printf("NULL\n");
        return;
    }

    Node* temp = q->front;
    while (temp != NULL) {
        printf("%s ", temp->data);
        printf("\n");
        temp = temp->next;
    }

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

int main() {
    Queue* q = createQueue();
    int choice;
    do {
        printf("1.Them khach hang \n");
        printf("2.Phuc vu \n");
        printf("3.Hien thi danh sach\n");
        printf("4.Thoat\n");
        printf("Moi ban chon: \n");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                char name[100];
                printf("Moi ban nhap ten khac hang : \n");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                q = enQueue(q, name);
                break;
            case 2:
                q=deQueue(q);
                break;
            case 3:
                printQueue(q);
                break;
            case 4:
                printf("Thoat\n");
                break;
            default:
                printf("Moi ban nhap lai\n");
        }
    } while (choice != 4);
  return 0;

}
