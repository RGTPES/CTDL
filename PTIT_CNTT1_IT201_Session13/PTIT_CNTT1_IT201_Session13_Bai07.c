//PTIT_CNTT1_IT201_Session13_Bai07
#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct Stack {
    char element[MAX];
    int top;
    int capacity;
} Stack;

void creat(Stack* st, int cap) {
    st->top = -1;
    st->capacity = cap;
}

void push(Stack* st, char value) {
    if (st->top < st->capacity - 1) {
        st->top++;
        st->element[st->top] = value;
    }
}

char pop(Stack* st) {
    if (st->top >= 0) {
        return st->element[st->top--];
    }
    return '\0';
}

int checkMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}
int isOpening(char ch) {
    return ch == '(' || ch == '[' || ch == '{';
}

int isClosing(char ch) {
    return ch == ')' || ch == ']' || ch == '}';
}

int check(char arr[]) {
    Stack st;
    creat(&st, MAX);
    int len = strlen(arr);

    for (int i = 0; i < len; i++) {
        char ch = arr[i];
        if (ch == '(' || ch == '[' || ch == '{') {
            push(&st, ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            char open = pop(&st);
            if (!checkMatching(open, ch)) {
                return 0;
            }
        }
    }

    return st.top == -1;
}

int main() {
    char arr[MAX];
    fgets(arr, MAX, stdin);
    arr[strcspn(arr, "\n")] = '\0';

    if (check(arr)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
