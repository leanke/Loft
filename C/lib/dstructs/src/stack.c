typedef struct {
    int top;
    int items[100];
} Stack;

// Push an item onto the stack
void push(Stack* s, int val) {
    if (s->top < 99) {
        s->items[++s->top] = val;
    }
}

// Pop an item from the stack
int pop(Stack* s) {
    if (s->top >= 0) {
        return s->items[s->top--];
    }
    return -1;
}
