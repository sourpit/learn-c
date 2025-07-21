#ifndef DS_H
#define DS_H
#define NULL (void *)0

typedef struct node
{
    int val;
    struct node *next, *previous;
} node;

void create(double p);
void insert(node *p, double val, int pos);
void del(node *p);
void pop(node *p);
void display(node *p);

#endif /* ifndef DS_H */
