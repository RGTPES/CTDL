
//PTIT_CNTT1_IT201_Session11_Bai07
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
Node* insertAtFirst(Node* head,int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->next = head;
    node->data = data;
    node->prev = NULL;
    head->prev = node;
    return node;
}
Node* delAtFirst(Node* head) {
    if (head == NULL) return NULL;

    Node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);

    return head;
}
Node* insert(Node* head, int data, int pos) {
    Node* node = createNode(data);

    if (head == NULL || pos == 0) {
        head = insertAtFirst(head, data);
        return head;
    }

    Node* prev = head;
    for (int i = 0; i < pos - 1 && prev->next != NULL; i++) {
        prev = prev->next;
    }

    node->next = prev->next;
    node->prev = prev;

    if (prev->next != NULL) {
        prev->next->prev = node;
    }

    prev->next = node;

    return head;
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
    int data,pos;
    printf("moi ban nhapgia tri: ");
    scanf("%d", &data);
    printf("moi ban nhap vi tri: ");
    scanf("%d", &pos);

    Node* node = insert(head,data,pos);
    printList(node);

}

