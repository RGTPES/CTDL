//PTIT_CNTT1_IT201_Session09_Bai08
#include<stdio.h>
#include<stdlib.h>
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
    while(node != NULL) {
        printf("%d -> ", node->data);
       node = node->next;
    }
    printf("\n");

}
Node* deleteNode(Node* head,int pos) {
    if (head==NULL) return NULL;
    if (pos==1) {
        Node* delete = head;
        head = head->next;
        free(delete);
        return head;
    }
    Node* del = head;
    for (int i =0;del!=NULL&&i<pos-2;i++) del = del->next;
    if (del == NULL || del->next == NULL) {
        printf("Vi tri khong hop le.\n");
        return head;
    }
    Node* temp = del->next;
    del->next = temp->next;
    free(temp);
    return head;

}
int main() {
    Node* head = createNode(1);
Node* node1 =createNode(10);
    Node* node2 =createNode(20);
    Node* node3 =createNode(30);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    int  pos;
    printList(head);
    printf("Nhap vi tri muon xoa : ");
    scanf("%d", &pos);
    head = deleteNode(head, pos);
    printList(head);

}

