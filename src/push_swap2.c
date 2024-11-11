#include "push_swap.h"

void ra(t_stack *a)
{
    if (a->size < 2)
        return;
    push_bottom(a, a->top->data);
    pop_top(a);
    write(1, "ra\n", 3);
}

void rb(t_stack *b)
{
    if (b->size < 2)
        return;
    push_bottom(b, b->top->data);
    pop_top(b);
    write(1, "rb\n", 3);
}

void rra(t_stack *a)
{
    if (a->size < 2)
        return;
    push_top(a, a->bottom->data);
    pop_bottom(a);
    write(1, "rra\n", 4);
}

void rrb(t_stack *b)
{
    if (b->size < 2)
        return;
    push_top(b, b->bottom->data);
    pop_bottom(b);
    write(1, "rrb\n", 4);
}

void rrr(t_stack *a, t_stack *b)
{
    push_top(a, a->bottom->data);
    pop_bottom(a);
    push_top(b, b->bottom->data);
    pop_bottom(b);
    write(1, "rrr\n", 4);
}