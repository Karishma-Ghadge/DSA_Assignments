#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;

} node;
node *head = NULL;
node *tail = NULL;

void add_first(int data);
void add_last(int data);
void forward_display();
void backward_display();
void add_at_specific_position(int data, int pos);
int count_nodes();
void delete_first();
void delete_last();
void delete_at_specific_position(int pos);
void selection_sort();
node *find_mid();

int main()
{

    add_first(20);
    add_last(30);
    add_first(35);
    add_first(45);
    add_first(55);
    add_last(60);
    add_at_specific_position(40, 3);
    backward_display();
    delete_first();
    delete_last();
    delete_at_specific_position(3);
    forward_display();
    selection_sort();
    forward_display();

    node *mid = find_mid();
    printf("Mid: %d", mid->data);

    return 0;
}

node *create_node()
{
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL)
    {
        printf("Malloc failed\n");
    }
    else
    {
        new_node->prev = NULL;
        new_node->data = 0;
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
        tail = new_node;
    }
    else
    {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
}

void add_last(int data)
{
    node *new_node = create_node();
    new_node->data = data;

    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
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
        while (trav != NULL)
        {
            printf("->%d", trav->data);
            trav = trav->next;
        }
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
        node *trav = tail;
        while (trav != NULL)
        {
            printf("->%d", trav->data);
            trav = trav->prev;
        }
    }
    printf("\n");
}

void add_at_specific_position(int data, int pos)
{
    node *new_node = create_node();
    if (head == NULL)
    {
        if (pos == 1)
            add_first(data);
        else
            printf("Invalid\n");
    }
    else if (pos == 1)
        add_first(data);
    else if (pos == count_nodes() + 1)
        add_last(data);
    else if (pos < 1 || pos > count_nodes() + 1)
        printf("Invalid\n");

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
        while (trav != NULL)
        {
            count++;
            trav = trav->next;
        }
    }
    return count;
}

void delete_first()
{
    if (head == NULL)
    {
        printf("List empty\n");
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
        tail = NULL;
    }
    else
    {
        node *temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
        temp = NULL;
    }
}

void delete_last()
{
    if (head == NULL)
    {
        printf("List empty\n");
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
        tail = NULL;
    }
    else
    {
        node *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        free(temp);
        temp = NULL;
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
    for (sel_pos = head; sel_pos->next != NULL; sel_pos = sel_pos->next)
    {
        for (pos = sel_pos->next; pos != NULL; pos = pos->next)
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

node *find_mid()
{
    node *slow = head;
    node *fast = head;

    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == head)
            break;
    } 
    return slow;
}