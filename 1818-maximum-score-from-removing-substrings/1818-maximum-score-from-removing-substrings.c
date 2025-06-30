typedef struct {
    int top;
    int base;
    int limit;
    char ch[100000];
} stack_t;

stack_t *resetStack() {
    stack_t *stack = (stack_t *)malloc(sizeof(stack_t));
    stack->top = 0;
    stack->limit = 100000;
    stack->base = 0;
    return stack;
}

void push(stack_t *stack, char ch) {
    if (stack->top != stack->limit) {
        stack->ch[stack->top] = ch;
        stack->top++;
    }
}

char pop(stack_t *stack) {
    if (stack->top > 0) {
        stack->top--;
        return stack->ch[stack->top];
    }
    return '\0';
}

int case1(char *s, int x, int y) {
    int points = 0;
    int len = strlen(s);
    stack_t *stack1 = resetStack();
    stack_t *stack2 = resetStack();

    for (int i = 0; i < len; i++) {                     //remove ab
        if (stack1->top > 0 && stack1->ch[stack1->top - 1] == 'a' && s[i] == 'b') {
            pop(stack1);
            points += x;
        } else {
            push(stack1, s[i]);
        }
    }

    while (stack1->top > 0) {                           //remove ba
        char ch = pop(stack1);
        if (stack2->top > 0 && ch == 'b' && stack2->ch[stack2->top - 1] == 'a') {
            pop(stack2);
            points += y;
        } else {
            push(stack2, ch);
        }
    }

    free(stack1);
    free(stack2);

    return points;
}

int case2(char *s, int x, int y) {
    int points = 0;
    int len = strlen(s);
    stack_t *stack1 = resetStack();
    stack_t *stack2 = resetStack();
    char last = '\0';


    for (int i = 0; i < len; i++) {             //remove ba
        if (stack1->top > 0 && stack1->ch[stack1->top - 1] == 'b' && s[i] == 'a') {
            pop(stack1);
            points += y;
        } else {
            push(stack1, s[i]);
        }
    }

    while (stack1->top > 0) {                   //remove ab
        char ch = pop(stack1);
        if (stack2->top > 0 && ch == 'a' && stack2->ch[stack2->top - 1] == 'b') {
            pop(stack2);
            points += x;
        } else {
            push(stack2, ch);
        }
    }

    free(stack1);
    free(stack2);

    return points;
}

int maximumGain(char *s, int x, int y) {
    int points;
    if (x > y) {
        points = case1(s, x, y);
    } else {
        points = case2(s, x, y);
    }
    return points;
}
