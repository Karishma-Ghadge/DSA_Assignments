#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct queue
{
    node *front;
    node *rear;
} queue;

queue *create_queue()
{
    queue *queue = (struct queue *)malloc(sizeof(queue));
    queue->front = NULL;
    queue->rear = NULL;
}

void enqueue(queue *queue, int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if (queue->rear == NULL)
    {
        queue->front = new_node;
        queue->rear = new_node;
    }
    else
    {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
}

int dequeue(queue *queue)
{
    if (queue->front == NULL)
    {
        printf("Queue empty\n");
        return -1;
    }
    node *temp = queue->front;
    int deq = temp->data;
    queue->front = queue->front->next;

    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    free(temp);
    temp = NULL;
    return deq;
}

int peek(queue *queue)
{
    if (queue->front == NULL)
    {
        printf("Queue empty\n");
        return -1;
    }
    return queue->front->data;
}

int isEmpty(queue *queue)
{
    return queue->front == NULL;
}

int main()
{

    queue *queue = create_queue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    printf("Front element is %d\n", peek(queue));
    printf("Dequeued element is %d\n", dequeue(queue));
    printf("Front element is now %d\n", peek(queue));

    return 0;
}