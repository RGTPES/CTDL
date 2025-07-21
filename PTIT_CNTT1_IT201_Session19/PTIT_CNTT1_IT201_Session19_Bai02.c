//PTIT_CNTT1_IT201_Session19_Bai02

#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node* left ;
    struct node* right;
}Node;
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

// Duyet preOder
void preOrderDFS(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preOrderDFS(root->left);
    preOrderDFS(root->right);

}
int main(){
    Node* root = NULL;
    root = createNode(2);
    Node* node1 = createNode(3);
    Node* node2 = createNode(5);
    Node* node3 = createNode(4);

    root->left = node1;
    root->right = node3;
    node1->left = node2;

    preOrderDFS(root);
    return 0;
}