#include "push_swap.h"


void simple_sort(t_stack **stack_a, t_stack **stack_b, t_ctx *ctx)
{
    int min_idx;
    int size;

    if (!stack_a || !*stack_a)
        return ;

    size = get_stack_size(*stack_a);
    if (size < 3)
    {
        sort_two(stack_a, ctx);
    }
    else
    {
        while (get_stack_size(*stack_a) > 3)
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

        sort_three(stack_a, ctx);

        while (get_stack_size(*stack_b) > 0)
        {
            pa(stack_a, stack_b, ctx);
        }
    }
}
