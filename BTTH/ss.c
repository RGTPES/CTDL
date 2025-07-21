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
typedef struct Queue {
    QNode* front;
    QNode* rear;
}Queue;
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}
void enqueue(Queue* q, Node* treeNode) {
    QNode* temp = (QNode*)malloc(sizeof(QNode));
    temp->treeNode = treeNode;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}
Node* dequeue(Queue* q) {
    if (q->front == NULL) return NULL;
    QNode* temp = q->front;
    Node* treeNode = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return treeNode;
}
int isEmpty(Queue* q) {
    return q->front == NULL;
}
Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
void levelOder(Node* root) {
    if (root == NULL) return;
    Queue* q = createQueue();
    enqueue(q, root);
    while (!isEmpty(q)) {
        Node* current = dequeue(q);
        printf("%d ", current->data);
        if (current->left != NULL) enqueue(q, current->left);
        if (current->right != NULL) enqueue(q, current->right);
    }
    printf("\n");
}
void preOrderDFS(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preOrderDFS(root->left);
    preOrderDFS(root->right);
}
void inoderDFS(Node* root) {
    if (root == NULL) return;
    inoderDFS(root->left);
    printf("%d ", root->data);
    inoderDFS(root->right);
}
void postOrderDFS(Node* root) {
    if (root == NULL) return;
    postOrderDFS(root->left);
    postOrderDFS(root->right);
    printf("%d ", root->data);
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
    levelOder(root);
    return 0;
}
