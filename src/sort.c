#include "push_swap.h"

void ft_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortcheck(t_stack *a)
{
    t_node *now = a->top;

    while (now->prev)
    {
        if (now->data < now->prev->data)
            now = now->prev;
        else
            return;
    }

    exit(0);
}

void quick_sort(int start, int end, int *arr)
{
    int p;
    int i;
    int j;

    if (start >= end)
        return;
    p = end;
    i = start;
    j = end - 1;

    while (i <= j)
    {
        while (i <= end && arr[i] < arr[p])
            ++i;
        while (j >= start && arr[j] > arr[p])
            --j;
        if (i < j)
            ft_swap(&arr[i], &arr[j]);
    }
    ft_swap(&arr[i], &arr[p]);
    quick_sort(start, i - 1, arr);
    quick_sort(i + 1, end, arr);
}

int set_pivot(t_stack *list, int num)
{
    int *arr = (int *)malloc(sizeof(int) * list->size);
    int pivot[4];
    int i = 0;
    t_node *now = list->top;

    while (i < list->size)
    {
        arr[i] = now->data;
        now = now->prev;
        i++;
    }
    quick_sort(0, i - 1, arr);
    pivot[0] = (arr[(i - 1) / 5]);
    pivot[1] = (arr[(((i - 1) / 5) * 2)]);
    pivot[2] = (arr[(((i - 1) / 5) * 3)]);
    pivot[3] = (arr[(((i - 1) / 5) * 4)]);
    free(arr);
    return (pivot[num]);
}

void div_three(t_stack *a_stack, t_stack *b_stack)
{
    int max;
    int min;
    int asize;
    int p1;

    asize = a_stack->size;
    max = max0min1(a_stack, 0);
    min = max0min1(a_stack, 1);
    p1 = (max + min) / 3;
    while (asize--)
    {
        if (a_stack->top->data > p1 * 2)
            ra(a_stack);
        else
        {
            pb(a_stack, b_stack);
            if (b_stack->top->data < p1)
                rb(b_stack);
        }
    }
}

void div_middle(t_stack *a_stack, t_stack *b_stack, int p3, int p0)
{
    int asize = a_stack->size;

    while (asize--)
    {
        if (a_stack->top->data > p3)
            ra(a_stack);
        else
        {
            pb(a_stack, b_stack);
            if (b_stack->top->data <= p0)
                rb(b_stack);
        }
    }
}

void div_over_hundred(t_stack *a_stack, t_stack *b_stack)
{
    int pivot[4];
    int asize = a_stack->size;
    pivot[0] = set_pivot(a_stack, 0);
    pivot[0] = set_pivot(a_stack, 1);
    pivot[0] = set_pivot(a_stack, 2);
    pivot[0] = set_pivot(a_stack, 3);

    while (asize--)
    {
        if (a_stack->top->data > pivot[2] || a_stack->top->data <= pivot[0])
            ra(a_stack);
        else if (a_stack->top->data <= pivot[2] && a_stack->top->data > pivot[0])
        {
            pa(a_stack, b_stack);
            if (b_stack->top->data < pivot[1])
                rb(b_stack);
        }
    }
    div_middle(a_stack, b_stack, pivot[3], pivot[0]);
}

void harda(t_stack *a)
{
    t_node *now;

    now = a->top;
    if (now->data > now->prev->data && now->prev->data > a->bottom->data)
    {
        sa(a);
        rra(a);
    }
    else if (now->data > a->bottom->data && a->bottom->data > now->prev->data)
        ra(a);
    else if (a->bottom->data > now->data && now->data > now->prev->data)
        sa(a);
    else if (now->prev->data > now->data && now->data > a->bottom->data)
        rra(a);
    else if (now->prev->data > a->bottom->data && a->bottom->data > now->data)
    {
        rra(a);
        sa(a);
    }
    else
        return;
}

void hardcoding(t_stack *a)
{
    if (a->size <= 1)
        return;
    else if (a->size == 2)
    {
        if (a->top->data > a->bottom->data)
            sa(a);
    }
    else
        harda(a);
}

int max0min1(t_stack *list, int num)
{
    int max;
    int min;
    int p[2];
    t_node *now;

    now = list->top;
    max = list->top->data;
    min = list->top->data;
    while (now)
    {
        if (now->data > max)
            max = now->data;
        if (now->data < min)
            min = now->data;
        now = now->prev;
    }
    p[0] = max;
    p[1] = min;
    return (p[num]);
}

int maxormin(t_stack *a, int min)
{
    int a_index;
    t_node *now;

    now = a->top;
    a_index = 0;
    while (now->data != min)
    {
        now = now->prev;
        a_index++;
    }
    if (a_index > (a->size) / 2)
        return ((a->size - a_index) * -1);
    return (a_index);
}

int best(int ra_c, int rb_c, int new_ra_c, int new_rb_c)
{
    int old;
    int new;

    old = cal(ra_c, rb_c);
    new = cal(new_ra_c, new_rb_c);
    if (new < old)
        return (1);
    else
        return (0);
}

int cal(int ra, int rb)
{
    int ra_buho;
    int rb_buho;

    ra_buho = 1;
    rb_buho = 1;
    if (ra < 0)
        ra_buho = -1;
    if (rb < 0)
        rb_buho = -1;
    if (ra_buho * rb_buho == -1)
        return (ra * ra_buho + rb * rb_buho);
    else if (ra * ra_buho < rb * rb_buho)
        return (rb * rb_buho);
    else
        return (ra * ra_buho);
}

int count_ra(t_stack *a, int data)
{
    int min;
    int max;
    int a_index;
    t_node *now;

    a_index = 1;
    now = a->top;
    max = max0min1(a, 0);
    min = max0min1(a, 1);
    if (max < data || min > data)
        return (maxormin(a, min));
    if (a->top->data > data && a->bottom->data < data)
        return (0);
    while (1)
    {
        if (now->data < data && now->prev->data > data)
        {
            if (a_index > (a->size) / 2)
                return ((a->size - a_index) * -1);
            return (a_index);
        }
        now = now->prev;
        a_index++;
    }
}

void count(t_stack *a, t_stack *b, int *ra_c, int *rb_c)
{
    int b_index;
    int new_ra_c;
    int new_rb_c;
    t_node *now;

    now = b->top;
    b_index = 0;
    while (b_index < b->size)
    {
        new_ra_c = count_ra(a, now->data);
        if (b_index > (b->size) / 2)
            new_rb_c = (b->size - b_index) * -1;
        else
            new_rb_c = b_index;
        if (b_index == 0 || best(*ra_c, *rb_c, new_ra_c, new_rb_c))
        {
            *ra_c = new_ra_c;
            *rb_c = new_rb_c;
        }
        now = now->prev;
        b_index++;
    }
}

void btoa(t_stack *a_stack, t_stack *b_stack)
{
    int ra_c;
    int rb_c;

    ra_c = 0;
    rb_c = 0;
    count(a_stack, b_stack, &ra_c, &rb_c);
    rrrab(a_stack, b_stack, &ra_c, &rb_c);
    rrra(a_stack, &ra_c);
    rrrb(b_stack, &rb_c);
    pa(a_stack, b_stack);
}

void finish(t_stack *a)
{
    int min;
    int a_index;
    t_node *now;

    a_index = 0;
    now = a->top;
    min = max0min1(a, 1);
    while (now->data != min)
    {
        now = now->prev;
        a_index++;
    }
    if (a_index > a->size / 2)
    {
        a_index = a->size - a_index;
        while (a_index--)
            rra(a);
    }
    else
    {
        while (a_index--)
            ra(a);
    }
}

void atob(t_stack *a_stack, t_stack *b_stack)
{
    sortcheck(a_stack);
    if (a_stack->size >= 100)
        div_over_hundred(a_stack, b_stack);
    else if (a_stack->size < 100 && a_stack->size > 10)
        div_three(a_stack, b_stack);
    while (a_stack->size > 3)
        pb(a_stack, b_stack);
    hardcoding(a_stack);
    while (b_stack->size)
        btoa(a_stack, b_stack);
    finish(a_stack);
    return;
}