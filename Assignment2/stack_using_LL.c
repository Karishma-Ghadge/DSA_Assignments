#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct stack
{
    node *top;
} stack;

stack *init_stack()
{
    stack *stack = (struct stack *)malloc(sizeof(stack));
    stack->top = NULL;
    return stack;
}

void push(stack *stack, int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;
}

int pop(stack *stack)
{
    if (stack->top == NULL)
    {
        printf("stack empty\n");
        return -1;
    }
    node *temp = stack->top;
    int popped = temp->data;
    stack->top = stack->top->next;
    free(temp);
    temp = NULL;
    return popped;
}

int peek(stack *stack)
{
    if (stack->top == NULL)
    {
        printf("Stack empty\n");
        return -1;
    }
    return stack->top->data;
}

int stack_empty(stack *stack)
{
    return stack->top == NULL;
}

int main()
{

    stack *stack = init_stack();
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("top element is %d\n", peek(stack));
    printf("Popped element %d\n", pop(stack));
    printf("top element %d", peek(stack));

    return 0;
}