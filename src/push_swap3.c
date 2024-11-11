#include "push_swap.h"

void rrrab(t_stack *a, t_stack *b, int *ra_c, int *rb_c)
{
    while (*ra_c > 0 && *rb_c > 0)
    {
        rr(a, b);
        *ra_c -= 1;
        *rb_c -= 1;
    }
    while (*ra_c < 0 && *rb_c < 0)
    {
        rrr(a, b);
        *ra_c += 1;
        *rb_c += 1;
    }
}

void rrra(t_stack *a, int *ra_c)
{
    while (*ra_c)
    {
        if (*ra_c > 0)
        {
            ra(a);
            *ra_c -= 1;
        }
        else
        {
            rra(a);
            *ra_c += 1;
        }
    }
}

void rrrb(t_stack *b, int *rb_c)
{
    while (*rb_c)
    {
        if (*rb_c > 0)
        {
            rb(b);
            *rb_c -= 1;
        }
        else
        {
            rrb(b);
            *rb_c += 1;
        }
    }
}
