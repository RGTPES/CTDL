//PTIT_CNTT1_IT201_Session13_Bai04
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
void printStack(Stack st) {
    for (int i = st.top; i >= 0; i--) {
        printf("%d ", st.element[i]);
    }
    printf("\n");
}

int main() {
    Stack st;
    creat(&st, 5);
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    push(&st, 50);


    printStack(st);

    return 0;
}
