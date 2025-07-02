//PTIT_CNTT1_IT201_Session09_Bai07
#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;


Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}


void printList(Node* head) {
    Node* node = head;
    while (node != NULL) {
        printf("%d -> ", node->data);
      node = node->next;
    }
    printf("NULL\n");
}

Node* insertAtPosition(Node* head, int data, int pos) {
    Node* newNode = createNode(data);
    Node* node = head;
    int i = 0;
    if (pos == 0) {
        newNode->next = head;
        return newNode;
    }

    while (node != NULL && i < pos - 1) {
        node = node->next;
        i++;
    }
    if (node == NULL) {
        printf("ko the them\n");
        free(newNode);
        return head;
    }
    newNode->next = node->next;
    node->next = newNode;
    return head;
}

int main() {

    Node* head = createNode(10);
    Node* node1 = createNode(20);
    Node* node2 = createNode(30);
    Node* node3 = createNode(40);
    Node* node4 = createNode(50);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    printf("Danh sach ban dau:\n");
    printList(head);

    int data, pos;
    printf("Nhap gia tri muon them: ");
    scanf("%d", &data);
    printf("Nhap vi tri muon them : ");
    scanf("%d", &pos);

    head = insertAtPosition(head, data, pos);

    printf("Danh sach sau khi chen:\n");
    printList(head);

    return 0;
}
