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
void printList(Node* head) {
    Node* node = head;
    while(node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("\n");

}
Node* delAtEnd(Node* head) {
    Node* node = head;
    if(node == NULL) {
        return NULL;
    }
    while(node->next->next != NULL) {
        node = node->next;
    }
    free(node->next);
    node->next = NULL;
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

head = delAtEnd(head);
    printList(head);

}