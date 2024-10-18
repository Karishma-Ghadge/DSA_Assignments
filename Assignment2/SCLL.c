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
void add_at_specific_position(int data, int pos);
int count_nodes();
void delete_first();
void delete_last();
void delete_at_specific_position(int pos);
struct node *search(int key);
node* find_mid();
int main()
{

    add_first(10);
    add_first(20);
    add_first(30);
    display();
    add_last(40);
    add_last(50);
    add_last(60);
    display();
    add_at_specific_position(55, 6);
    display();
    delete_first();
    delete_last();
    display();
    delete_at_specific_position(2);
    display();
   node *mid= find_mid();
   printf("Mid: %d",mid->data);

    node *result;
    result = search(20);
    if (result == NULL)
        printf("\nKey not found\n");
    else
        printf("\nKey found\n");

    return 0;
}

node *create_node()
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = 0;
    new_node->next = NULL;
    return new_node;
}

void add_first(int data)
{
    node *new_node = create_node();
    new_node->data = data;

    if (head == NULL)
    {
        head = new_node;
        new_node->next = head;
    }
    else
    {
        node *trav = head;
        while (trav->next != head)
        {
            trav = trav->next;
        }
        new_node->next = head;
        head = new_node;
        trav->next = head;
    }
}

void display()
{
    if (head == NULL)
    {
        printf("List is empty\n");
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

void add_last(int data)
{
    node *new_node = create_node();
    new_node->data = data;

    if (head == NULL)
    {
        head = new_node;
        new_node->next = head;
    }
    else
    {
        node *trav = head;
        while (trav->next != head)
        {
            trav = trav->next;
        }
        trav->next = new_node;
        new_node->next = head;
    }
}
void add_at_specific_position(int data, int pos)
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
        node *new_node = create_node();
        new_node->data = data;

        node *trav = head;
        for (int i = 1; i < pos - 1; i++)
        {
            trav = trav->next;
        }
        new_node->next = trav->next;
        trav->next = new_node;
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
        printf("List is empty,cannot delete\n");
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        node *trav = head;
        while (trav->next != head)
        {
            trav = trav->next;
        }
        node *temp = head;
        head = temp->next;
        trav->next = head;
        free(temp);
        temp = NULL;
    }
}
void delete_last()
{
    if (head == NULL)
    {
        printf("List is empty,cannot delete\n");
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        node *trav = head;
        while (trav->next->next != head)
        {
            trav = trav->next;
        }
        free(trav->next);
        trav->next = head;
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

    while (n2 != head)
    {
        node *n3 = n2->next;
        n2->next = n1;
        n1 = n2;
        n2 = n3;
    }
    head->next = NULL;
    head = n1;
}

struct node *search(int key)
{
    node *trav = head;
    do
    {
        if (trav->data == key)
            return trav;

        trav = trav->next;
    } while (trav != head);
    return NULL;
}

node *find_mid()
{
    node *slow = head;
    node *fast = head;

    do
    {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == head)
            break;
    } while (fast->next != head);
    return slow;
}