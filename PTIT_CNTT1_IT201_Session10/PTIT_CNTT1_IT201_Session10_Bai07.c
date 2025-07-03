//PTIT_CNTT1_IT201_Session10_Bai07

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
void sortList(Node* head) {
    Node* current = head;
    Node* index = NULL;
    int temp;

    if (head == NULL) return;

    while (current != NULL) {
        index = current->next;
        while (index != NULL) {
            if (current->data > index->data) {

                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    }
}




int main() {
    Node* head = createNode(1);
    Node* node1 = createNode(9);
    Node* node2 = createNode(3);
    Node* node3 = createNode(5);
    Node* node4 = createNode(2);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;

 sortList(head);




    printList(head);

}