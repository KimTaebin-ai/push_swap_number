#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

typedef struct s_node
{
    int data;
    struct s_node *prev;
    struct s_node *next;
} t_node;

typedef struct s_stack
{
    int size;
    struct s_node *top;
    struct s_node *bottom;
} t_stack;

// error
void err_message(const char *message);

// clear
void clear(t_stack *list);

// stack utils
int ftpw_atoi(char *str, int len);
t_stack *stack_init(void);
t_node *getnode(int data);
void push_top(t_stack *list, int data);
void push_bottom(t_stack *list, int data);
void pop_top(t_stack *list);
void pop_bottom(t_stack *list);

// push & swap functions
void sa(t_stack *a);
void sb(t_stack *b);
void pa(t_stack *a, t_stack *b);
void pb(t_stack *a, t_stack *b);
void ra(t_stack *a);
void rb(t_stack *b);
void rr(t_stack *a, t_stack *b);
void rra(t_stack *a);
void rrb(t_stack *b);
void rrr(t_stack *a, t_stack *b);
void rrrab(t_stack *a, t_stack *b, int *ra_c, int *rb_c);
void rrra(t_stack *a, int *ra_c);
void rrrb(t_stack *b, int *rb_c);

// sort logic
void atob(t_stack *a_stack, t_stack *b_stack);

// solve utils
int max0min1(t_stack *list, int num);
int maxormin(t_stack *a, int min);
int best(int ra_c, int rb_c, int new_ra_c, int new_rb_c);
int cal(int ra, int rb);

int count_ra(t_stack *a, int data);
void count(t_stack *a, t_stack *b, int *ra_c, int *rb_c);

#endif