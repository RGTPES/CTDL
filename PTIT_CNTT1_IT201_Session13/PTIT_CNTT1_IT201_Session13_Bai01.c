//PTIT_CNTT1_IT201_Session13_Bai01
#include <stdio.h>
#define MAX 100
int Stack[MAX];
int top = -1;
int isEmpty() {
    if (top == -1) {
        return 1;
    }
    return 0;
}
int isFull() {
    if (top ==MAX - 1) {
        return 1;
    }
    return 0;
}
void push(int x) {
    if (isFull()) {
        return;
    }
    Stack[++top] = x;
}
int pop() {
    if (isEmpty()) {
        return -1;
    }
    int temp = Stack[top--];
    return temp;
}
int main() {
int n ;
    printf("moi ban nha so phan tu :");
    scanf("%d",&n);
    while(n--) {
        int t;
        scanf("%d",&t);
        push(t);
    }

}
