#define MAX 10000

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
    if( s->top > -1 ){
        return s->value[ s->top-- ];
    }
    return '\0';
}

char topStack( stack_t *s ){
    if( s->top > -1 ){
        return s->value[ s->top ];
    }
    return '\0';
}

bool isEmptyStack( stack_t *s ){
    if( s->top >= s->base ){
        return false;
    }else{
        return true;
    }
}


bool isValid(char* s) {
    stack_t *stack = resetStack();
    int len = strlen(s);
    char ch;

    for(int i = 0; i < len; i++){
        
        if( s[i] == '('){
            pushStack( stack, s[i] ); 
        }else if( s[i] == ')' ){
            if( topStack(stack) == '(' ){
                ch = popStack(stack);
            }else{
                return false;
            }
        }

        if( s[i] == '{'){
            pushStack( stack, s[i] ); 
        }else if( s[i] == '}' ){
            if( topStack(stack) == '{' ){
                ch = popStack(stack);
            }else{
                return false;
            }
        }

        if( s[i] == '['){
            pushStack( stack, s[i] ); 
        }else if( s[i] == ']' ){
            if( topStack(stack) == '[' ){
                ch = popStack(stack);
            }else{
                return false;
            }
        }
    }   

    if (isEmptyStack(stack)) return true;

    return false;
}