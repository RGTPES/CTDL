//PTIT_CNTT1_IT201_Session10_Bai05

#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
}Node;
Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}
void printList(Node* head) {
    Node* node = head;
    while(node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("\n");

}

Node* delData(Node* head, int data) {
    while (head != NULL && head->data == data) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
    Node* node = head;
    Node* prev = NULL;
    while (node != NULL) {
        if(node->data == data) {
            prev->next = node->next;
            free(node);
            node = prev->next;
    }else {
        prev = node;
        node = node->next;
    }
    }
    return head;

}

int main() {
    Node* head = createNode(1);
    Node* node1 = createNode(2);
    Node* node2 = createNode(3);
    Node* node3 = createNode(4);
    Node* node4 = createNode(5);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;
int n;

    printList(head);
    printf("nhap so can xoa : ");
    scanf("%d", &n);
head = delData(head, n);
    printList(head);

}