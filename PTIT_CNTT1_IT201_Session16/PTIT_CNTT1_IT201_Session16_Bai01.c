//PTIT_CNTT1_IT201_Session16_Bai01
#include<stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}Node;
typedef struct Queue {
    Node *front;
    Node *rear;

}Queue;
Queue *createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
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
        return q;
    }
    q->rear->next = newNode;
    q->rear = newNode;
    return q;
}
Queue* deQueue(Queue* q) {
    if (q->front == NULL) {
        printf("Hang doi rong\n");
        return q;
    }
    Node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp->data);
    free(temp);
    q->size--;
    return q;
}
int main() {

}
