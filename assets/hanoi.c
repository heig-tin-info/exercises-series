#include <stdio.h>
#include <stdlib.h>
/*
typedef struct Stack {
    int *data;
    size_t capacity;
    size_t count;
} Stack;

void init(Stack *stack) {
    stack->capacity = 1;
    stack->data = malloc(stack->capacity * sizeof(*stack->data));
    stack->count = 0;
}

void push(Stack *stack, int c) {
    if (stack->count + 1 >= stack->capacity) {
        stack->data = realloc(stack->data, stack->capacity *= 2);
    }
    stack->data[stack->count++] = c;
}

int pop(Stack *stack) {
    return stack->data[--stack->count];
}

int display(Stack *a, Stack *b, Stack *c) {
    printf("A(");
    for (int i = 0; i < a->count; i++) {
        printf("%d", a->data[i]);
        if (i < a->count - 1) printf(", ");
    }
    printf(") ");

    printf("B(");
    for (int i = 0; i < b->count; i++) {
        printf("%d", b->data[i]);
        if (i < b->count - 1) printf(", ");
    }
    printf(") ");

    printf("C(");
    for (int i = 0; i < c->count; i++) {
        printf("%d", c->data[i]);
        if (i < c->count - 1) printf(", ");
    }
    printf(") ");

    printf("\n");
}

void hanoi(int n, Stack *a, Stack *b, Stack *c) {
    printf("n = %d\n", n);

    if (n == 0) return;
    hanoi(n - 1, a, c, b);
    push(c, pop(a));
    display(a, b, c);
    hanoi(n - 1, c, b, a);
}*/

void hanoi(int n, char from, char to, char via) {
    if (n == 1) { printf("%c → %c\n", from, to); return; }
    hanoi(n - 1, from, via, to);
    hanoi(1, from, to, via);
    hanoi(n - 1, via, to, from);
}

int main(void) {
    hanoi(4, 'A', 'B', 'C');
}