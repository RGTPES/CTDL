
//PTIT_CNTT1_IT201_Session12_Bai05
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
    printf("NULL <->");
    while (node != NULL) {
        printf("%d<-> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}
Node* delCorrectNode(Node* head, int data) {
    Node* temp = head;
    int del=0;
    while (temp != NULL) {
        Node* next = temp->next;
        if (temp->data == data) {
            if (temp->prev != NULL)
                temp->prev->next = temp->next;
            else
                head = temp->next;
            if (temp->next != NULL)
                temp->next->prev = temp->prev;
            free(temp);
            del = 1;
        }
        temp = next;
    }
    if (del==0) {
        printf("NULL\n");
        return 0;
    }
    return head;
}

int main() {
    Node* head = createNode(1);
    Node* node1 = createNode(2);
    Node* node2 = createNode(1);
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
    int key;
    printList(head);
    printf("Enter the key: ");
    scanf("%d", &key);

    head =delCorrectNode(head,key);
    if (head) {
        printList(head);
    }


}

