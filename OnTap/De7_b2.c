#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Operation {
    char url[100];
    char timeStapped[100];
} Op;

typedef struct Stack {
    Op *opr;
    int top;
    int capacity;
} Stack;

int isEmpty(Stack *s) {
    return s->top < 0;
}

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->opr = (Op*)malloc(sizeof(Op) * capacity);
    return stack;
}

void push(Stack *s, Op opr) {
    if (s->top == s->capacity - 1) {
        printf("Stack full\n");
        return;
    }
    s->top++;
    s->opr[s->top] = opr;
}

void displayStack(Stack *s) {
    if (isEmpty(s)) {
        printf("Empty stack\n");
        return;
    }
    for (int i = 0; i <= s->top; i++) {
        printf("%s ", s->opr[i].url);
    }
    printf("\n");
}

Op pop(Stack *s) {
    Op empty = {"", ""};
    if (isEmpty(s)) {
        printf("Empty stack\n");
        return empty;
    }
    return s->opr[s->top--];
}

void setCurrent(Stack *current, Op opr) {
    current->top = -1;
    push(current, opr);
}

int main() {
    int choice;
    Stack* BACK = createStack(100);
    Stack* FORWARD = createStack(100);
    Stack* CURRENT = createStack(100);
    do {
        printf("1. VISIT URL\n");
        printf("2. BACKWARD\n");
        printf("3. FORWARD\n");
        printf("4. CURRENT\n");
        printf("5. THOAT\n");
        printf("Moi ban nhap lua hon cua ban \n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                getchar();
                char url[100], timeStapped[100];
                printf("Moi ban nhap url \n");
                fgets(url, 100, stdin);
                url[strcspn(url, "\n")] = '\0';
                printf("Moi ban nhap thoi gian \n");
                fgets(timeStapped, 100, stdin);
                timeStapped[strcspn(timeStapped, "\n")] = '\0';
                Op opr;
                strcpy(opr.url, url);
                strcpy(opr.timeStapped, timeStapped);
                push(BACK, opr);
                push(CURRENT, opr);
                break;
            }
            case 2: {
                if (!isEmpty(BACK)) {
                    Op last = pop(BACK);
                    setCurrent(CURRENT, last);
                    push(FORWARD, last);
                    if (CURRENT->top >= 0) {
                        pop(CURRENT);
                        push(CURRENT, last);
                    }
                }
                break;
            }
            case 3: {
                if (!isEmpty(FORWARD)) {
                    Op last2 = pop(FORWARD);
                    setCurrent(CURRENT, last2);
                    push(BACK, last2);
                    if (CURRENT->top >= 0) {
                        pop(CURRENT);
                        push(CURRENT, last2);
                    }
                }
                break;
            }
            case 4:
                displayStack(CURRENT);
                break;
        }
    } while (choice != 5);
}
