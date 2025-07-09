//PTIT_CNTT1_IT201_Session14_Bai02
#include <stdio.h>
#include <stdlib.h>

typedef struct st {
    int data;
    struct Node* next;
} st;

st* create(int data) {
    st* node = (st*)malloc(sizeof(st));
    node->data = data;
    node->next = NULL;
    return node;
}
st* push(st* head,int data) {
    st* node = create(data);
    st* temp = head;
    while (temp->next!=NULL) {
        temp= temp->next;

    }
    temp->next = node;


    return head;
}
void printList(st* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
int main() {
    st* head = create(10);
    st* node = create(20);
    st* temp = create(30);
    st* temp2 = create(40);
    head->next = node;
    node->next = temp;
    temp->next = temp2;
    printList(head);
 head = push(head,50);
    printList(head);


}

