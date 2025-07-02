//PTIT_CNTT1_IT201_Session09_Bai06

#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
}Node ;
Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

}

Node* insertHead( Node* head,int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;

}
Node* insertEnd(Node* head) {
    Node* newNode = createNode(4);
    if(head == NULL) {
        head = newNode;
        return head;
    }
    Node* lastNode = head;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
    return head;

}
Node* deleteFirst(Node* head) {
    if(head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    Node* first = head;
    head= head->next;
    free(first);
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

    head = deleteFirst(head);
    printList(head);

}


