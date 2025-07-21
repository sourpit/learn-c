#include "DS.h"

#include <stdio.h>
#include <stdlib.h>

node *head = NULL, *tmp;

// For list initialization
void create(double p)
{
    node *newList = (node *)malloc(sizeof(node));
    newList->val = p;
    newList->next = NULL;
    newList->previous = NULL;
}

void insert(node *p, double val, int pos)
{
    if (p == NULL)
    {
        create(val);
    }
    tmp = (node *)malloc(sizeof(node));

    tmp->val = val;
    tmp->next = head;
    head = tmp;
}

void pop(node *p)
{
    int val;

    if (head == NULL)
        sprintf(stdout, "Stack is empty!\n");

    else
    {
        val = head->val;  // Wrong, we get the value from head
        tmp = head;
        head->next = head;
        free(tmp);
        sprintf(stdout, "%d is popped\n", val);
    }
}

void display(node *p)
{
    if (head == NULL)
        sprintf(stdout, "Stack is empty!\n");

    else
    {
        while (p != NULL)
        {
            sprintf(stdout, "%d\n", p->val);
            p->next = p;
        }
    }
}
