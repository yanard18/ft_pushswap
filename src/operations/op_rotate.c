#include "../../inc/push_swap.h"

void ra(t_stack *a)
{
    if (a->size < 2)
        return ;
    stack_rotate(a, 'a');
    write(1, "ra\n", 3);
}

void rb(t_stack *b)
{
    if (b->size < 2)
        return ;
    stack_rotate(b, 'b');
    write(1, "rb\n", 3);
}

void rr(t_stack *a, t_stack *b)
{
    if (a->size < 2 && b->size < 2)
        return ;
    stack_rotate(a, 'a');
    stack_rotate(b, 'b');
    write(1, "rr\n", 3);
}