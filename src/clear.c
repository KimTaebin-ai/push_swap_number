#include "push_swap.h"

void err_message(const char *message)
{
    ft_putstr_fd("mandatory: ", 2);
    ft_putendl_fd((char *)message, 2);
    exit(0);
}

unsigned long long int answer(unsigned long long int num, int buho)
{
    int a;

    a = num * buho;
    if (buho == -1 && num > 2147483648)
        err_message("error");
    if (buho == 1 && num > 2147483647)
        err_message("error");
    return (a);
}

int ftpw_atoi(char *str, int len)
{
    int buho;
    int i;
    unsigned long long int num;

    num = 0;
    buho = 1;
    i = 0;
    str[len] = '\0';
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '+' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
        i++;
    if (str[i] == '-' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
    {
        buho *= -1;
        i++;
    }
    if (!(str[i] >= '0' && str[i] <= '9'))
        err_message("error");
    while (str[i] >= '0' && str[i] <= '9')
    {
        num = num * 10 + (str[i] - '0');
        i++;
    }
    return (answer(num, buho));
}

void clear(t_stack *list)
{
    while (list->size)
        pop_top(list);
    free(list);
}