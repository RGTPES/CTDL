//PTIT_CNTT1_IT201_Session20_Bai01
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
    QNode *front;
    QNode *rear;
}Queue;

Node* createNode(int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
int main() {
    Node* head = createNode(1);
    head->left = NULL;
    head->right = NULL;
    return 0;
}