#include "../push_swap.h"

/*

NOTE to myself (Deniz'e degil tabii ki):
    stack_a : struct itself
    *stack_a : holds the address of the top node
    **stack_a : holds the address of the pointer itself. i used it so that if i
        move the head. (it's the struct version of what you did in ft_printf)

take the first element at the top of a and put it at the top of b

1. take the first node of stack a
2. move the 'head' of a to the next node
3. unlink the old head 
4. add the 'old top of stack a' to the top of stack b
5. link the 'old top of stack b' to the new top of stack b

*/

void pb(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp;

    if (!stack_a || !*stack_a)
        return ;

    tmp = *stack_a;
    *stack_a = tmp->next;

    // stack_a'da artik bu node yok, bir sonraki node stack_a'nin yeni head'i. Oncesinde de bir onceki node yok 
    // cunku bir onceki node artik stack_b'de 
    if (*stack_a)
        (*stack_a)->previous = NULL;

    tmp->next = *stack_b;
    if (*stack_b)
        (*stack_b)->previous = tmp;

    *stack_b = tmp;
    tmp->previous = NULL;
    write(1, "pb\n", 3);
    move_counter(1);
}

void pa(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp;

    if (!stack_b || !*stack_b)
        return ;

    tmp = *stack_b;
    *stack_b = tmp->next;
    if (*stack_b)
        (*stack_b)->previous = NULL;
        
    tmp->next = *stack_a;
    if (*stack_a)
        (*stack_a)->previous = tmp;
        
    *stack_a = tmp;
    tmp->previous = NULL;
    write(1, "pa\n", 3);
    move_counter(1);
}

/*

*/