#include "../../inc/push_swap.h"

void rra(t_stack **a, int print)
{
    t_stack *last;
    t_stack *second_last;

    if (!*a || !(*a)->next)
        return ;

    second_last = *a;
    while (second_last->next->next)
        second_last = second_last->next;

    last = second_last->next;
    
    second_last->next = NULL;
    last->next = *a;
    *a = last;

    if (print)
        write(1, "rra\n", 4);
    move_counter(1);
}
void rrb(t_stack **b, int print)
{
    t_stack *last;
    t_stack *second_last;

    if (!*b || !(*b)->next)
        return ;

    second_last = *b;
    while (second_last->next->next)
        second_last = second_last->next;

    last = second_last->next;
    
    second_last->next = NULL;
    last->next = *b;
    *b = last;

    if (print)
        write(1, "rrb\n", 4);
    move_counter(1);
}

void rrr(t_stack **a, t_stack **b)
{
    int can_rra;
    int can_rrb;

    can_rra = (*a && (*a)->next);
    can_rrb = (*b && (*b)->next);

    if (!can_rra && !can_rrb)
        return ;

    if (can_rra)
        rra(a, 0);
    if (can_rrb)
        rrb(b, 0);

    write(1, "rrr\n", 4);
}