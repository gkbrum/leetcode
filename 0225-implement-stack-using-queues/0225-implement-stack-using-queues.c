typedef struct node_t{
    int value;
    struct node_t *next;
} node_t;

typedef struct {
    node_t *first;
    node_t *last;
    int size;
} queue_t;

queue_t *resetQueue(){
    queue_t *q = ( queue_t * )malloc( sizeof( queue_t ) );

    q->first = NULL;
    q->last = NULL;
    q->size = 0;

    return q;
}

void pushQueue( queue_t *queue, int value ){
    if( queue->size == 0 ){
        node_t *node = ( node_t * )malloc( sizeof( node_t ) );
        node->value = value;
        node->next = NULL;

        queue->first = queue->last = node;
        queue->size++;
    }else{
        node_t *node = ( node_t * )malloc( sizeof( node_t ) );
        node->value = value;
        node->next = NULL;

        queue->last->next = node;
        queue->last = node;
        queue->size++;
    }
}

int popQueue( queue_t *q ){
    if( q->size == 0 ){
        return -1;
    }else{
        node_t *popped = q->first;
        q->first = popped->next;
        q->size--;
        int v = popped->value;
        free(popped);
        return v;
    }
    
    return -1;
}

int sizeQueue( queue_t *q ){
    return q->size;
}

bool isEmptyQueue( queue_t *q ){
    if( q->size > 0 ){
        return false;
    }else{
        return true;
    }
}

typedef struct {
    queue_t *q1, *q2;
} MyStack;


MyStack* myStackCreate() {
    MyStack *stack = malloc(sizeof(MyStack));
    stack->q1 = resetQueue();
    stack->q2 = resetQueue();

    return stack;
}

void myStackPush(MyStack* obj, int x) {
    if(obj->q1->size == 0 && obj->q2->size == 0){
        pushQueue(obj->q1, x);
    }else if(obj->q1->size != 0){
        pushQueue(obj->q1, x);
    }else if(obj->q2->size != 0){
        pushQueue(obj->q2, x);
    }
}

int myStackPop(MyStack* obj) {
    if(obj->q1->size != 0){
        int qSize = obj->q1->size;
        for(int i = 0; i < qSize - 1; i++){
            pushQueue(obj->q2, popQueue(obj->q1));
        }
        return popQueue(obj->q1);
    }else if(obj->q2->size != 0){
        int qSize = obj->q2->size;
        for(int i = 0; i < qSize - 1; i++){
            pushQueue(obj->q1, popQueue(obj->q2));
        }
        return popQueue(obj->q2);
    }
    return -1;
}

int myStackTop(MyStack* obj) {
    
    if(obj->q1->size != 0){
        int qSize = obj->q1->size;
        for(int i = 0; i < qSize - 1; i++){
            pushQueue(obj->q2, popQueue(obj->q1));
        }
       
        int answer = popQueue(obj->q1);
        pushQueue(obj->q2, answer);
        return answer;

    }else if(obj->q2->size != 0){
        int qSize = obj->q2->size;
        for(int i = 0; i < qSize - 1; i++){
            pushQueue(obj->q1, popQueue(obj->q2));
        }
        
        int answer = popQueue(obj->q2);
        pushQueue(obj->q1, answer);
        return answer;
    }
    return -1;
}

bool myStackEmpty(MyStack* obj) {
    if(isEmptyQueue(obj->q1) && isEmptyQueue(obj->q2)){
        return true;
    }else{
        return false;
    }
}

void myStackFree(MyStack* obj) {
    free(obj->q1);
    free(obj->q2);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/