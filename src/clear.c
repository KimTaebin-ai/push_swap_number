#include "push_swap.h"

void err_message(const char *message)
{
    ft_putstr_fd("mandatory: ", 2);
    ft_putendl_fd((char *)message, 2);
    exit(0);
}

void clear(t_stack *list)
{
    while (list->size)
        pop_top(list);
    free(list);
}