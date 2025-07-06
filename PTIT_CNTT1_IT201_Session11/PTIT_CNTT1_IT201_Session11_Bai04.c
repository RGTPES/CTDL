
//PTIT_CNTT1_IT201_Session11_Bai04
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
}Node;
Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}
int getLength(Node* node) {
    int length = 0;
    while (node != NULL) {
        node = node->next;
        length++;

    }
    return length;
}
void printList(Node* node) {
    while (node != NULL) {
        printf("%d<-> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}
Node* findNode(Node* node, int key) {
    while (node != NULL) {

        if (node->data == key) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

int main() {
    Node* head = createNode(1);
    Node* node1 = createNode(2);
    Node* node2 = createNode(3);
    Node* node3 = createNode(4);
    Node* node4 = createNode(5);
    head->next = node1;
    head->prev = NULL;
    node1->next = node2;
    node1->prev = head;
    node2->next = node3;
    node2->prev = node1;
    node3->next = node4;
    node3->prev = node2;
    node4->next = NULL;
    node4->prev = node3;
printf("do dai danh sach co %d phan tu ",getLength(head));
}

