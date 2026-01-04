#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define CAPACITY 100

/* Stack structure */
struct Stack {
    char elements[CAPACITY];
    int top;
};

/* Initialize stack */
void initialize(struct Stack *s) {
    s->top = -1;
}

/* Check if stack is empty */
int isEmpty(struct Stack *s) {
    return s->top == -1;
}

/* Check if stack is full */
int isFull(struct Stack *s) {
    return s->top == CAPACITY - 1;
}

/* Push element onto stack */
void push(struct Stack *s, char character) {
    if (isFull(s)) {
        printf("Stack is full!");
        return;
    }
    s->elements[++(s->top)] = character;
}

/* Pop element from stack */
char pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!");
        return '\0';
    }
    return s->elements[(s->top)--];
}

/* Peek top element of stack */
char peek(struct Stack *s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->elements[s->top];
}

/* Operator precedence */
int precedence(char operator) {
    if (operator == '^')
        return 3;
    else if (operator == '*' || operator == '/')
        return 2;
    else if (operator == '+' || operator == '-')
        return 1;
    else
        return 0;
}

/* Convert infix expression to postfix */
void convertToPostfix(char *infix, char *postfix) {
    struct Stack stack;
    initialize(&stack);
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char character = infix[i];

        if (character == ' ') {
            continue;
        }

        if (isalpha(character) || isdigit(character)) {
            postfix[j++] = character;
        }
        else if (character == '(') {
            push(&stack, character);
        }
        else if (character == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack); // remove '('
        }
        else {
            while (!isEmpty(&stack) &&
                   precedence(peek(&stack)) >= precedence(character)) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, character);
        }
    }

    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
}

int main() {
    char infix[CAPACITY];
    char postfix[CAPACITY];

    printf("Enter infix expression:\n");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = '\0';

    convertToPostfix(infix, postfix);

    printf("\nPostfix expression: %s\n", postfix);

    return 0;
}
