#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} node;

node *head = NULL;

void add_first(int data);
void add_last(int data);
void backward_display();
void forward_display();
void add_at_specific_position(int data, int pos);
int count_nodes();
void delete_first();
void delete_last();
void delete_at_specific_position(int pos);
void selection_sort();

int main()
{

    add_first(20);
    add_first(40);
    add_first(60);
    add_first(70);
    add_last(87);
    add_last(67);
    add_at_specific_position(30, 2);
    forward_display();
    backward_display();
    add_last(80);
    add_last(90);
    forward_display();
    delete_first();
    delete_last();
    delete_at_specific_position(3);
    selection_sort();
    forward_display();
    return 0;
}

struct node *create_node()
{
    node *new_node = (node *)malloc(sizeof(new_node));
    if (new_node == NULL)
    {
        printf("Malloc failed\n");
    }
    else
    {
        new_node->data = 0;
        new_node->prev = NULL;
        new_node->next = NULL;
    }
    return new_node;
}
void add_first(int data)
{
    node *new_node = create_node();
    new_node->data = data;

    if (head == NULL)
    {
        head = new_node;
        new_node->prev = head;
        new_node->next = head;
    }
    else
    {
        new_node->next = head;
        new_node->prev = head->prev;
        head->prev->next = new_node;
        head->prev = new_node;
        head = new_node;
    }
}
void forward_display()
{
    if (head == NULL)
    {
        printf("List empty\n");
    }
    else
    {
        node *trav = head;
        do
        {
            printf("->%d", trav->data);
            trav = trav->next;
        } while (trav != head);
    }
    printf("\n");
}

void backward_display()
{
    if (head == NULL)
    {
        printf("List empty\n");
    }
    else
    {
        node *trav = head->prev;
        do
        {
            printf("->%d", trav->data);
            trav = trav->prev;
        } while (trav != head->prev);
    }
    printf("\n");
}
void add_last(int data)
{
    node *new_node = create_node();
    new_node->data = data;
    if (head == NULL)
    {
        head = new_node;
        new_node->prev = head;
        new_node->next = head;
    }
    else
    {
        new_node->prev = head->prev;
        new_node->next = head;
        head->prev->next = new_node;
        head->prev = new_node;
    }
}

void add_at_specific_position(int data, int pos)
{
    node *new_node = create_node();
    if (head == NULL)
    {
        if (pos == 1)
            add_first(data);
        else
            printf("Invalid1\n");
    }
    else if (pos == 1)
        add_first(data);
    else if (pos == count_nodes() + 1)
        add_last(data);
    else if (pos < 1 || pos > count_nodes() + 1)
        printf("Invalid2\n");


    else
    {
        node *new_node = create_node();
        new_node->data = data;

        node *trav = head;
        for (int i = 1; i < pos - 1; i++)
        {
            trav = trav->next;
        }
        new_node->prev = trav;
        new_node->next = trav->next;
        trav->next = new_node;
        new_node->next->prev = new_node;
    }
}
int count_nodes()
{
    int count = 0;
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        node *trav = head;
        do
        {
            count++;
            trav = trav->next;
        } while (trav != head);
    }
    return count;
}
void delete_first()
{
    if (head == NULL)
    {
        printf("list empty\n");
    }
    else if (head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        node *temp = head;
        head->prev->next = head->next;
        head->next->prev = head->prev;
        head = head->next;
        free(temp);
        temp = NULL;
    }
}

void delete_last()
{
    if (head == NULL)
    {
        printf("Empty\n");
    }
    if (head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        head->prev = head->prev->prev;
        free(head->prev->next);
        head->prev->next = head;
    }
}

void delete_at_specific_position(int pos)
{
    if (head == NULL)
    {
        printf("List empty\n");
    }
    else if (pos == 1)
    {
        delete_first();
    }
    else if (pos == count_nodes())
    {
        delete_last();
    }
    else if (pos < 1 || pos > count_nodes())
    {
        printf("Invalid\n");
    }
    else
    {
        node *trav = head;
        for (int i = 1; i < pos; i++)
        {
            trav = trav->next;
        }
        trav->prev->next = trav->next;
        trav->next->prev = trav->prev;
        free(trav);
        trav = NULL;
    }
}

void selection_sort()
{
    node *sel_pos, *pos;
    for (sel_pos = head; sel_pos->next != head; sel_pos = sel_pos->next)
    {
        for (pos = sel_pos->next; pos != head; pos = pos->next)
        {
            if (sel_pos->data > pos->data)
            {
                int temp = sel_pos->data;
                sel_pos->data = pos->data;
                pos->data = temp;
            }
        }
    }
}