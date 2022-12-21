#include <stdio.h>

struct Data {
    // int num;
    char a;
};

struct Stack {
    int top;
    unsigned capacity;
    struct Data *array;
};

struct Stack *createStack(unsigned capacity) {
    struct Stack *stack = (struct Stack *) malloc(sizeof(struct Stack));
    if(!stack) { return NULL; }
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*) malloc(stack->capacity * sizeof(struct Data));
    return stack;
}

int isEmpty(struct Stack *stack) {
    return stack->top==-1;
}

int isFull(struct Stack *stack) {
    return stack->top+1 == stack->capacity;
}

struct Data peek(struct Stack *stack) {
    return stack->array[stack->top];
}

void push(struct Stack *stack, struct Data data) {
    stack->array[++stack->top] = data;
}

struct Data pop(struct Stack *stack) {
    if(isEmpty(stack)) {
        return;
    }
    return stack->array[stack->top--];
}

int prec(struct Data ch) {
    switch (ch.a) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return -1;
}

int infixToPostfix(struct Data *exp) {
    int i, k;
    struct Stack* stack = createStack(strlen(exp));
    if (!stack) {
        return -1;
    }
    for (i = 0, k = -1; exp[i].a; ++i) {
        if (isOp(exp[i])) {
            exp[++k] = exp[i];
        } else if (exp[i].a == '(') {
            push(stack, exp[i]);
        } else if (exp[i].a == ')') {
            while (!isEmpty(stack) && peek(stack).a != '(') {
                exp[++k] = pop(stack);
            }
            pop(stack);
        } else {
            while (!isEmpty(stack) && prec(exp[i]) <= prec(peek(stack))) {
                exp[++k] = pop(stack);
            }
            push(stack, exp[i]);
        }
    }
    while (!isEmpty(stack)) {
        exp[++k] = pop(stack);
    }
    
    exp[++k].a = '\0';
    printf("%s", exp);
}

int main() {
    printf("Nothing to see here");
}
