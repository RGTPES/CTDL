//PTIT_CNTT1_IT201_Session20_Bai02
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
void preOrderDFS(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preOrderDFS(root->left);
    preOrderDFS(root->right);

}
int main() {
    Node* root = NULL;
    root = createNode(2);
    Node* node1 = createNode(3);
    Node* node2 = createNode(5);
    Node* node3 = createNode(4);
    Node* node4 = createNode(5);
    root->left = node1;
    root->right = node3;
    node1->left = node2;
    node1->right = node4;
    preOrderDFS(root);
}