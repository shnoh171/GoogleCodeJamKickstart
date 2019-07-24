#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_SIZE 100000

typedef struct stack_t {
    int array[MAX_SIZE];
    int index;
} stack;

void push(stack *st, int value) {
    st->array[(st->index)++] = value;
}

void pop(stack *st) {
    --(st->index);
}

bool is_empty(stack *st) {
    return st->index == 0;
}

int get_size(stack *st) {
    return st->index;
}

int top(stack *st) {
    return st->array[st->index - 1];
}


int get_number_of_sticks(char *arrangement) {
    int ret = 0;
    int size = strlen(arrangement);
    int i;
    stack st = { .array = {}, .index = 0 };

    for (i = 0; i < size; ++i) {
        if (arrangement[i] == '(') {
            ++ret;
            push(&st, i);
        } else if (arrangement[i] == ')') {
            if (top(&st) + 1 == i) {
                --ret;
                pop(&st);
                ret += get_size(&st);
            } else {
                pop(&st);
            }
        }
    }

    return ret;
}

int main() {
    char str[MAX_SIZE];

    scanf("%s", str);
    printf("%d\n", get_number_of_sticks(str));

    return 0;
}