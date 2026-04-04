#include "push_swap.h"

void pa(t_stack *a, t_stack *b)
{
    pop(&b);
    pudh(&a);
    write(1, "pa\n", 3);
}

void pb(t_stack *a, t_stack *b)
{
    pop(&a);
    pudh(&b);
    write(1, "pb\n", 3);
}