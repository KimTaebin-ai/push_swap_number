#include "push_swap.h"

t_stack *stack_init()
{
    t_stack *stack;

    stack = malloc(sizeof(t_stack));
    stack->top = NULL;
    stack->bottom = NULL;
    stack->size = 0;
    return (stack);
}

void push_top(t_stack *list, int data)
{
    t_node *new;
    t_node *oldtop;

    new = getnode(data);
    if (list->top == NULL)
    {
        list->top = new;
        list->bottom = new;
    }
    else
    {
        oldtop = list->top;
        oldtop->next = new;
        new->prev = oldtop;
        list->top = new;
    }
    list->size++;
}

void pop_top(t_stack *list)
{
    t_node *nowtop;
    t_node *newtop;

    nowtop = list->top;
    if (nowtop == NULL)
        return;
    else if (list->size == 1)
    {
        list->top = NULL;
        list->bottom = NULL;
    }
    else
    {
        newtop = list->top->prev;
        newtop->next = NULL;
        list->top = newtop;
    }
    list->size--;
    free(nowtop);
}

void push_bottom(t_stack *list, int data)
{
    t_node *new;
    t_node *oldbottom;

    new = getnode(data);
    if (list->bottom == NULL)
    {
        list->top = new;
        list->bottom = new;
    }
    else
    {
        oldbottom = list->bottom;
        oldbottom->prev = new;
        new->next = oldbottom;
        list->bottom = new;
    }
    list->size++;
}

void pop_bottom(t_stack *list)
{
    t_node *nowbottom;
    t_node *newbottom;

    nowbottom = list->bottom;
    if (nowbottom == NULL)
        return;
    else if (list->size == 1)
    {
        list->top = NULL;
        list->bottom = NULL;
    }
    else
    {
        newbottom = list->bottom->next;
        newbottom->prev = NULL;
        list->bottom = newbottom;
    }
    list->size--;
    free(nowbottom);
}
