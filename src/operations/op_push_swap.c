#include "../../inc/push_swap.h"

void pb(t_stack **a, t_stack **b)
{
    int x;

    if (!*a)
        return ;

    x = stack_pop(a);
    stack_push(b, x);
    write(1, "pb\n", 3);
    move_counter(1);
}

void pa(t_stack **a, t_stack **b)
{
    int x;

    if (!*b)
    return ;
    
    x = stack_pop(b);
    stack_push(a, x);
    write(1, "pa\n", 3);
    move_counter(1);
}

void sa(t_stack **a, int print)
{
    int tmp;

    if (!*a || !(*a)->next)
        return ;

    tmp = (*a)->value;
    (*a)->value = (*a)->next->value;
    (*a)->next->value = tmp;

    if (print)
        write(1, "sa\n", 3);
    move_counter(1);
}        

void sb(t_stack **b, int print)
{
     int tmp;

    if (!*b || !(*b)->next)
        return ;

    tmp = (*b)->value;
    (*b)->value = (*b)->next->value;
    (*b)->next->value = tmp;

    if (print)
        write(1, "sb\n", 3);
    move_counter(1);
}

void ss(t_stack **a, t_stack **b)
{
    int can_swap_a;
    int can_swap_b;

    can_swap_a = 0;
    can_swap_b = 0;
    if (*a && (*a)->next)
        can_swap_a = 1;
    if (*b && (*b)->next)
        can_swap_b = 1;
    
    if (!can_swap_a && !can_swap_b)
        return ;

    if (can_swap_a)
        sa(a, 0);
    if (can_swap_b)
        sb(b, 0);
    
    write(1, "ss\n", 3);
}