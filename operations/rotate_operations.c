#include "../push_swap.h"

/*
    shift 'up' all elements of the stack by one

    1. identify the head of the stack
    2. identify the last node of the stack
    3. promote the second node of the stack as head node
    4. link the old head to the end of the stack
    5. link the 'old last node to the new last node'

*/

void ra(t_stack **stack_a)
{
    t_stack *first;
    t_stack *last;

    if (!stack_a || !(*stack_a)->next)
        return ;
    first = *stack_a;
    last = *stack_a;
    while (last->next)
        last = last->next;
    *stack_a = first->next;
    (*stack_a)->previous = NULL;
    last->next = first;
    first->previous = last;
    first->next = NULL;
    write(1, "ra\n", 3);
    move_counter(1);
}

void rb(t_stack **stack_b)
{
    t_stack *first;
    t_stack *last;

    if (!stack_b || !(*stack_b)->next)
        return ;
    first = *stack_b;
    last = *stack_b;
    while (last->next)
        last = last->next;
    *stack_b = first->next;
    (*stack_b)->previous = NULL;
    last->next = first;
    first->previous = last;
    first->next = NULL;
    write(1, "rb\n", 3);
    move_counter(1);
}
