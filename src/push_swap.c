#include "push_swap.h"

void sa(t_stack *a)
{
    int tmp;

    tmp = a->top->data;
    a->top->data = a->top->prev->data;
    a->top->prev->data = tmp;
    write(1, "sa\n", 3);
}

void sb(t_stack *b)
{
    int tmp;

    tmp = b->top->data;
    b->top->data = b->top->prev->data;
    b->top->prev->data = tmp;
    write(1, "sb\n", 3);
}

void pa(t_stack *a, t_stack *b)
{
    if (b->size == 0)
        return;
    push_top(a, b->top->data);
    pop_top(b);
    write(1, "pa\n", 3);
}

void pb(t_stack *a, t_stack *b)
{
    if (a->size == 0)
        return;
    push_top(b, a->top->data);
    pop_top(a);
    write(1, "pb\n", 3);
}

void rr(t_stack *a, t_stack *b)
{
    push_bottom(a, a->top->data);
    pop_top(a);
    push_bottom(b, b->top->data);
    pop_top(b);
    write(1, "rr\n", 3);
}
