
//PTIT_CNTT1_IT201_Session12_Bai07
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

void printList(Node* node) {
    while (node != NULL) {
        printf("%d<-> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}
Node* sort(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    while (1) {
        int i =0;

    Node* current = head;
    Node* next = head->next;
    while (current->next!=NULL) {
        if (current->data > next->data) {
            int temp = current->data;
            current->data = next->data;
            next->data = temp;
            i=1;

        }
        current =current->next;
        next = next->next;
    }
        if (i==0) {
            break;
        }
    }
    return head;
}

int main() {
    Node* head = createNode(1);
    Node* node1 = createNode(9);
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
head = sort(head);
    printList(head);

}

