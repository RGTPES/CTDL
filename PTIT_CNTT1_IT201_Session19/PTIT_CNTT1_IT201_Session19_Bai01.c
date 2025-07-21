//PTIT_CNTT1_IT201_Session19_Bai01

#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node* left ;
    struct node* right;
}Node;
typedef struct QNode {
    Node* treeNode;
    struct QNode* next;
} QNode;
typedef struct Queue{
    Node *front;
    Node *rear;
}Queue;
Queue* createQueue() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}
Node* createNode(int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}





int main(){
Node* root = NULL;
    root = createNode(1);
    Node* node1 = createNode(2);
    Node* node2 = createNode(3);
    Node* node3 = createNode(4);
    Node* node4 = createNode(5);
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;

    return 0;
}