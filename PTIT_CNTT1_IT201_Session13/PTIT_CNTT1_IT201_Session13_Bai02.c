//PTIT_CNTT1_IT201_Session13_Bai02
#include<stdio.h>
#define MAX 100
typedef struct Stack{
    int element[MAX];
    int top;
    int capacity;
}Stack;
void creat(Stack* st,int cap) {
    st->top=-1;
    st->capacity=cap;
}
void push(Stack* st,int value) {
if(st->top<st->capacity-1) {
    st->top++;
    st->element[st->top] = value;
}
}
void printStack(Stack s) {
    printf("\nstack={\n");
    printf("    elements: [");
    for (int i = 0; i <= s.top; i++) {
        printf("%d", s.element[i]);
        if (i != s.top) printf(", ");
    }
    printf("],\n");
    printf("    top: %d,\n", s.top);
    printf("    cap: %d\n", s.capacity);
    printf("}\n");
}

int main() {
    Stack st;
    creat(&st, 5);

    int value;
    printf("moi ban nhap phan tu :\n");
    for (int i = 0; i < st.capacity; i++) {
        scanf("%d", &value);
        push(&st, value);
    }

    printStack(st);

    return 0;
}