#include "push_swap.h"

t_node *getnode(int data)
{
    t_node *new;

    new = malloc(sizeof(t_node));
    if (new == NULL)
        return (0);
    new->data = data;
    new->next = NULL;
    new->prev = NULL;
    return (new);
}