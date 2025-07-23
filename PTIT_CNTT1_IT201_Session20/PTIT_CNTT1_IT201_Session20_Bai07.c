//PTIT_CNTT1_IT201_Session20_Bai07
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
Node* createNode(int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
Queue* createQueue() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
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
int findMax(Node* root) {
    if (root == NULL) return -1;

    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);
    int max = root->data;

    if (leftMax > max) max = leftMax;
    if (rightMax > max) max = rightMax;

    return max;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}
Node* deleteNode(Node* root, int value) {
    if (root == NULL) {
        printf("Cay rong.\n");
        return NULL;
    }

    if (root->left == NULL && root->right == NULL) {
        if (root->data == value) {
            free(root);
            return NULL;
        } else {
            printf("Khong tim thay gia tri %d trong cay.\n", value);
            return root;
        }
    }

    Queue* q = createQueue();
    enqueue(q, root);

    Node* target = NULL;
    Node* current = NULL;
    Node* last = NULL;
    Node* parentOfLast = NULL;

    while (!isEmpty(q)) {
        current = dequeue(q);

        if (current->data == value) {
            target = current;
        }

        if (current->left != NULL) {
            enqueue(q, current->left);
            if (current->left->left == NULL && current->left->right == NULL)
                parentOfLast = current;
        }

        if (current->right != NULL) {
            enqueue(q, current->right);
            if (current->right->left == NULL && current->right->right == NULL)
                parentOfLast = current;
        }

        last = current;
    }

    if (target != NULL) {
        target->data = last->data;
        if (parentOfLast != NULL) {
            if (parentOfLast->left == last) {
                free(parentOfLast->left);
                parentOfLast->left = NULL;
            } else if (parentOfLast->right == last) {
                free(parentOfLast->right);
                parentOfLast->right = NULL;
            }
        } else {
            free(root);
            root = NULL;
        }

        printf("Da xoa thanh cong\n");
    } else {
        printf("Khong tim thay gia tri %d trong cay.\n", value);
    }

    free(q);
    return root;
}


void insertNode(Node* root, int value) {
    if (root == NULL) return;

    Queue* q = createQueue();
    enqueue(q, root);

    while (!isEmpty(q)) {
        Node* current = dequeue(q);

        if (current->left == NULL) {
            current->left = createNode(value);
            break;
        } else {
            enqueue(q, current->left);
        }

        if (current->right == NULL) {
            current->right = createNode(value);
            break;
        } else {
            enqueue(q, current->right);
        }
    }

    free(q);
}
int countLeaf(Node* root) {
    if (root == NULL) return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeaf(root->left) + countLeaf(root->right);
}



void preOrderDFS(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preOrderDFS(root->left);
    preOrderDFS(root->right);
}
int findLevel(Node* root, int value) {
    if (root == NULL) return -1;

    Queue* q = createQueue();
    enqueue(q, root);
    enqueue(q, NULL);
    int level = 1;

    while (!isEmpty(q)) {
        Node* current = dequeue(q);

        if (current == NULL) {
            // Kết thúc 1 tầng
            if (!isEmpty(q)) {
                level++;
                enqueue(q, NULL);
            }
        } else {
            if (current->data == value) {
                free(q);
                return level;
            }
            if (current->left != NULL)
                enqueue(q, current->left);
            if (current->right != NULL)
                enqueue(q, current->right);
        }
    }

    return -1;
}

int main() {
    Node* root = NULL;
    root = createNode(2);
    Node* node1 = createNode(3);
    Node* node2 = createNode(9);
    Node* node3 = createNode(4);
    Node* node4 = createNode(5);
    root->left = node1;
    root->right = node3;
    node1->left = node2;
    node1->right = node4;
    root = deleteNode(root, 3);
    preOrderDFS(root);
    return 0;
}