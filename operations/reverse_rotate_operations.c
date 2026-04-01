#include "../push_swap.h"

/*

shift 'down' all elements of the stack by one 

1. find the last node of the stack
2. identify the node comes before the last one as the new last node
3. link the old bottom to the top (link its next to the current top before actually
identifying it as the new head)
4. identify the old bottom as the new head

*/

void rra(t_stack **stack_a)
{
    t_stack *last;

    if (!stack_a || !(*stack_a)->next)
        return ;
    last = stack_last(*stack_a);
    last->previous->next = NULL;
    last->next = *stack_a;
    last->previous = NULL;
    (*stack_a)->previous = last;
    *stack_a = last;
    write(1, "rra\n", 4);
    move_counter(1);
}

void rrb(t_stack **stack_b)
{
    t_stack *last;

    if (!stack_b || !(*stack_b)->next)
        return ;
    last = stack_last(*stack_b);
    last->previous->next = NULL;
    last->next = *stack_b;
    last->previous = NULL;
    (*stack_b)->previous = last;
    *stack_b = last;
    write(1, "rrb\n", 4);
    move_counter(1);
}