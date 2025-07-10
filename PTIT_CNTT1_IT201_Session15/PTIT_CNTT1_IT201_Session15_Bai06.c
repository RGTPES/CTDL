//PTIT_CNTT1_IT201_Session15_Bai06
#include<stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;
typedef struct Queue {
    Node* front;
   Node* rear;

}Queue;
Queue* createQueue() {
    Queue* queue =(Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}
Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}
Queue* enQueue(Queue* q, int data) {
    Node* newNode = createNode(data);
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    return q;
}
void check(Queue* q) {
    Node* temp = q->front;
    while (temp->next != NULL) {

        if (temp->next->data - temp->data !=1) {
            printf("false");
            return;
        }
        temp = temp->next;
    }
    printf("true");
}
int main() {
    Queue* queue = createQueue();
    int n;
    int a;
    printf("Nhap so :  ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Moi ban nhap phan tu thu %d :\n",i+1);
        scanf("%d",&a);
        Node* node = createNode(a);
        enQueue(queue,a);

    }
    check(queue);

}