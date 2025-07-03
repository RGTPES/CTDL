//PTIT_CNTT1_IT201_Session10_Bai03
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
Node* insertNode(Node* head) {
    if (head==NULL) {
        return NULL;
    }
    Node* newNode = createNode(5);
    Node* temp = head;
    while (temp->next!=NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;

}
void printList(Node* head) {
    Node* node = head;
    while(node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("\n");

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
    head = insertNode(head);
    printList(head);

}