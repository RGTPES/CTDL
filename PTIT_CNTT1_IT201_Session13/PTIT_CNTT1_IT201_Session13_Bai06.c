//PTIT_CNTT1_IT201_Session13_Bai06
#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct Stack {
    char element[MAX];
    int top;
    int capacity;
} Stack;

Stack creat(int cap) {
    Stack st;
    st.top = -1;
    st.capacity = cap;
    return st;
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

int Palindrome(char str[]) {
    int len = strlen(str);
    Stack st = creat(len);

    for (int i = 0; i < len; i++) {
        push(&st, str[i]);
    }

    for (int i = 0; i < len; i++) {
        if (str[i] != pop(&st)) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char str[MAX];
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = '\0';

    if (Palindrome(str)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
