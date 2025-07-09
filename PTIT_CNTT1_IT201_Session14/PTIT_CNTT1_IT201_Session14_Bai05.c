//PTIT_CNTT1_IT201_Session14_Bai05
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* head;
} stack;

stack* create() {
    stack* s = (stack*)malloc(sizeof(stack));
    s->head = NULL;
    return s;
}

void push(stack* s, int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = s->head;
    s->head = node;
}

void pop(stack* s) {
    if (s->head == NULL) {
        printf("ngan xep trong \n");
        return;
    }
    Node* temp = s->head;
    s->head = s->head->next;
    free(temp);
}

void printStack(stack* s) {
    Node* temp = s->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int top(stack* s) {
    if (s->head == NULL) {
        printf("ngan xep trong \n");
        return -1;
    }
    return s->head->data;
}
int main() {
    stack* s = create();

    push(s, 10);
    push(s, 20);
    push(s, 30);
    printStack(s);
printf("%d\n", top(s));


    return 0;
}
