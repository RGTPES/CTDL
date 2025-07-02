//PTIT_CNTT1_IT201_Session09_Bai03
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
int search(Node* head, int value) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == value)
            return 1;
        temp = temp->next;
    }
    return 0;
}

int main() {
    int number;
printf("nhap so : ");
    scanf("%d", &number);
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
    if (search(head, number)) {
        printf(" tim thay %d\n", number);
    }else {
        printf("ko tim thay%d\n", number);
    }
}