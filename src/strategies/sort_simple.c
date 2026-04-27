#include "push_swap.h"

void simple_sort(t_stack **stack_a, t_stack **stack_b, t_ctx *ctx)
{
    int min_idx;
    int size;

    if (!stack_a || !*stack_a)
        return ;
    if (handle_small_stacks(stack_a, stack_b, ctx))
        return ;
    while (*stack_a)
    {
        size = get_stack_size(*stack_a); 
        min_idx = find_min_idx(*stack_a);

        if (min_idx <= size / 2)
        {
            while (min_idx > 0)
            {
                ra(stack_a, ctx, 1);
                min_idx--;
            }
        }
        else
        {
            while (min_idx < size)
            {
                rra(stack_a, ctx, 1);
                min_idx++;
            }
        }
        pb(stack_a, stack_b, ctx);
    }
    while (*stack_b)
    {
        pa(stack_a, stack_b, ctx);
    }
}