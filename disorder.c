#include "push_swap.h"

float calculate_disorder(t_stack *stack_a)
{
    float   mistakes;
    float   total_pairs;
    t_stack *current;
    t_stack *pair;

    if (!stack_a || !stack_a->next)
        return (0.0);
    
    mistakes = 0;
    total_pairs = 0;
    current = stack_a;
    
    while (current)
    {
        pair = current->next;
        while (pair)
        {
            total_pairs++;
            if (current->value > pair->value)
                mistakes++;
            pair = pair->next;
        }
        current = current->next;
    }
    return (mistakes / total_pairs);
}