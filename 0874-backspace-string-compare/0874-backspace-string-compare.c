#define MAX 200

typedef struct {
    int limit;
    int top;
    int base;
    char value[MAX];
} stack_t;

stack_t *resetStack(){
    stack_t *stack = ( stack_t * )malloc( sizeof( stack_t ) );
    if (!stack) return NULL;

    stack->limit = MAX - 1;
    stack->top = -1;
    stack->base = 0;

    return stack;
}

void pushStack( stack_t *s, char value ){
    if( s->top != s->limit ){
        s->value[ s->top + 1 ] = value;
        s->top++;
    }
}

char popStack( stack_t *s ){
    if( s->top > - 1 ){
        return s->value[ s->top-- ];
    }

    return '\0';
}

char topStack( stack_t *s ){
    if( s->top > -1 ){
        return s->value[ s->top ];
    }

    return s->value[ s->top ];
}

bool isEmptyStack( stack_t *s ){
    if( s->top >= s->base ){
        return false;
    }else{
        return true;
    }

    return true;
}

bool isFullStack( stack_t *s ){
    if( s->top == s->limit ){
        return true;
    }else{
        return false;
    }

    return false;
}

bool backspaceCompare(char* s, char* t) {
    int len = strlen(s);
    stack_t *sStack = resetStack();
    stack_t *tStack = resetStack();

    for(int i = 0; i < len; i++){
        if(s[i] == '#'){
            char trash = popStack(sStack);
        }else{
            pushStack(sStack, s[i]);
        }
    }
    
    len = strlen(t);
    for(int i = 0; i < len; i++){
        if(t[i] == '#'){
            char trash = popStack(tStack);
        }else{
            pushStack(tStack, t[i]);
        }
    }   

    while( !isEmptyStack(sStack) && !isEmptyStack(tStack) ){
        if(popStack(sStack) != popStack(tStack)){
            return false;
        }
    }

    return isEmptyStack(sStack) && isEmptyStack(tStack);
}