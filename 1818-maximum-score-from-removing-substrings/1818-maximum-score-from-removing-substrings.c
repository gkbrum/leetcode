typedef struct {
    int top;
    int base;
    int limit;
    char ch[100001];
} stack_t;

stack_t *reset() {
    stack_t *stack = (stack_t *)malloc(sizeof(stack_t));
    
    stack->top = 0;
    stack->limit = 100001;
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
    if (stack->top != 0) {
        stack->top--;
        return stack->ch[stack->top + 1];
    }
    return '\0';
}

int removePairs(char *s, char c1, char c2, int value, char *s2) {
    stack_t *stack =  reset();
    int points = 0;
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        if (stack->top != 0 && stack->ch[stack->top - 1] == c1 && s[i] == c2) {
            pop(stack); // remove o par
            points += value;
        } else {
            push(stack, s[i]); // empilha
        }
    }
    push(stack, '\0');

    // Copia o resultado para output
    strcpy(s2, stack->ch);

    free(stack);
    return points;
}

int maximumGain(char *s, int x, int y) {
    int total = 0;
    int len = strlen(s);
    char *s2 = (char *)malloc(sizeof(char) * len + 1);
    
    if (x > y) {
        // Remove "ab" primeiro, depois "ba"
        total += removePairs(s, 'a', 'b', x, s2);
        total += removePairs(s2, 'b', 'a', y, s);
    } else {
        // Remove "ba" primeiro, depois "ab"
        total += removePairs(s, 'b', 'a', y, s2);
        total += removePairs(s2, 'a', 'b', x, s);
    }

    free(s2);
    return total;
}