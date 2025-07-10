//PTIT_CNTT1_IT201_Session15_Bai01
#include<stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;
typedef struct Queue {
    Node* front;
    Node* rear;
}Queue;
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}
Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
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
void printQueue(Queue* q) {
    if (q->front == NULL) {
        printf("NULL\n");
        return;
    }

    Node* temp = q->front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue* q = createQueue();
    enQueue(q, 1);
    enQueue(q, 2);
    enQueue(q, 3);
    printQueue(q);

}