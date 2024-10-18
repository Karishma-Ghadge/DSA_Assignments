#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head = NULL;

node *create_node();
void add_first(int data);
void display();
void add_last(int data);
void add_at_specific_pos(int data, int pos);
int count_nodes();
void delete_first();
void delete_last();
void delete_at_specific_position(int pos);
void reverse_list();
node *search(int key);

int main()
{

    add_first(10);
    add_first(100);
    add_first(200);
    add_last(5);
    display();
    add_last(25);
    add_first(300);
    display();
    add_at_specific_pos(50, 2);
    display();
    delete_first();
    delete_last();
    delete_at_specific_position(4);
    display();
    reverse_list();
    display();

    node *result;
    result = search(5);
    if (result == NULL)
        printf("Key not found\n");
    else
        printf("Key found\n");
    return 0;
}

node *create_node()
{
    node *ptr = (struct node *)malloc(sizeof(node));
    ptr->data = 0;
    ptr->next = NULL;
}

void add_first(int data)
{
    node *ptr = create_node();
    ptr->data = data;

    if (head == NULL)
    {
        head = ptr;
    }
    else
    {
        ptr->next = head;
        head = ptr;
    }
}

void display()
{
    if (head == NULL)
        printf("The list is empty\n");
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

void add_last(int data)
{
    node *ptr = create_node();
    ptr->data = data;
    if (head == NULL)
        head = ptr;
    else
    {
        node *trav = head;
        while (trav->next != NULL)
        {
            trav = trav->next;
        }
        trav->next = ptr;
    }
}

void add_at_specific_pos(int data, int pos)
{
    if (head == NULL)
    {
        if (pos == 1)
        {
            add_first(data);
        }
        else
        {
            printf("Invalid\n");
        }
    }
    else if (pos == 1)
    {
        add_first(data);
    }
    else if (pos == count_nodes() + 1)
    {
        add_last(data);
    }
    else if (pos < 1 || pos > count_nodes() + 1)
    {
        printf("Invalid position\n");
    }
    else
    {
        node *ptr = create_node();
        ptr->data = data;

        node *trav = head;
        for (int i = 1; i < pos - 1; i++)
        {
            trav = trav->next;
        }
        ptr->next = trav->next;
        trav->next = ptr;
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
    }
    else
    {
        node *temp = head;
        head = head->next;
        free(temp);
        temp = NULL;
    }
}

void delete_last()
{
    if (head == NULL)
    {
        printf("Cannot delete,list empty\n");
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        node *trav = head;
        while (trav->next->next != NULL)
        {
            trav = trav->next;
        }
        free(trav->next);
        trav->next = NULL;
    }
}
void delete_at_specific_position(int pos)
{
    if (head == NULL)
    {
        printf("List empty,cannot delete\n");
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
        for (int i = 1; i < pos - 1; i++)
        {
            trav = trav->next;
        }
        node *temp = trav->next;
        trav->next = temp->next;
        free(temp);
        temp = NULL;
    }
}

void reverse_list()
{
    node *n1 = head;
    node *n2 = head->next;

    while (n2 != NULL)
    {
        node *n3 = n2->next;
        n2->next = n1;
        n1 = n2;
        n2 = n3;
    }
    head->next = NULL;
    head = n1;
}

node *search(int key)
{
    node *trav = head;
    while (trav != NULL)
    {
        if (trav->data == key)
            return trav;

        trav = trav->next;
    }
    return NULL;
}