#include <stdio.h>
#include <stdlib.h>

/*
Standard Template for creating a Linked List quicky.  Credit: Debasis Sidkar
Functions include:
    1. Insertion (Head and Tail, at any point)
    2. Deletion (any point, element to delete)
    3. Display
    4. Reverse
    5. Sort (Ascending, Descending)
    6. Position Access

To use this template
       Create a node using node* (variable name) and point it to null.
       node* var = NULL;
       This will be the HEAD node for your list.
    Now you can use the template with the syntax as follows:
    insert(&(head node variable), (integer data));
    insert_tail(&(head node variable), (integer data));
    del_node(&(head node variable), (integer data));
    display(&(head node variable));
    reverse(&(head node variable));
    asc_sort(&(head node variable));
    desc_sort(&(head node variable));
    element(&(head node variable), int position); // where position starts from 0.
*/

typedef struct node
{
    int data;
    struct node *next;
} node;

void insert_head(node **head_ref, int new_data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void insert(node **head_ref, int new_data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    node *last = *head_ref;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
}

void del_node(node **head_ref, int del)
{
    node *temp = *head_ref, *prev;
    if (temp != NULL && temp->data == del)
    {
        *head_ref = temp->next;
        return;
    }
    while (temp != NULL && temp->data != del)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
}

void display(node **head_ref)
{
    node *temp = *head_ref;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    free(temp);
}

void reverse(node **head_ref)
{
    node *prev = NULL;
    node *current = *head_ref;
    node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
    free(prev);
    free(current);
    free(next);
}

void asc_sort(node **head_ref)
{
    node *current, *index;
    int temp;

    if (*head_ref == NULL)
    {
        return;
    }
    else
    {
        for (current = *head_ref; current->next != NULL; current = current->next)
        {
            for (index = current->next; index != NULL; index = index->next)
            {
                if (current->data > index->data)
                {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
            }
        }
    }
    free(current);
    free(index);
}

void desc_sort(node **head_ref)
{
    node *current, *index;
    int temp;

    if (*head_ref == NULL)
    {
        return;
    }
    else
    {
        for (current = *head_ref; current->next != NULL; current = current->next)
        {
            for (index = current->next; index != NULL; index = index->next)
            {
                if (current->data < index->data)
                {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
            }
        }
    }
    free(current);
    free(index);
}

int element(node **head_ref, int pos)
{
    node *temp = *head_ref;
    int i = 0;

    while (temp != NULL)
    {
        if (pos == i)
        {
            return temp->data;
        }
        temp = temp->next;
        i++;
    }

    free(temp);
    return 0;
}
void insert_pos(node **head_ref, int pos, int new_data)
{
    node *temp = *head_ref;
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = new_data;
    new_node->next = NULL;

    if (pos == 0)
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }

    for (int i = 0; temp != NULL && i < pos - 1; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of bounds");
        return;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

void del_pos(node **head_ref, int pos)
{
    if (*head_ref == NULL)
        return;

    node *temp = *head_ref;

    if (pos == 0)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < pos - 1; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL)
    {
        printf("Position out of bounds");
        return;
    }

    node *next = temp->next->next;

    free(temp->next);
    temp->next = next;
}