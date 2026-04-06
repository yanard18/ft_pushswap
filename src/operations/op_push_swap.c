#include "../../inc/push_swap.h"

void pb(t_stack *a, t_stack *b)
{
    int x;

    x = pop(a);
    push(b, x);
    write(1, "pb\n", 3);
}

void pa(t_stack *b, t_stack *a)
{
    int x;

    x = pop(b);
    push(a, x);
    write(1, "pa\n", 3);
}