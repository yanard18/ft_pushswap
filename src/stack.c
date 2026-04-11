#include "../inc/push_swap.h"

void stack_push(t_stack **stack, int value)
{
    t_stack *new_node;

    new_node = malloc(sizeof(t_stack));
    if (!new_node)
        return;
    new_node->value = value;
    new_node->next = *stack;
    *stack = new_node;
}

int stack_pop(t_stack **stack)
{
    t_stack *temp;
    int    val;

    if (!*stack || !stack)
        return (0);

    temp = *stack;
    val = temp->value;
    *stack = (*stack)->next;
    free(temp);
    return (val);
}

void	stack_clear(t_stack *stack)
{
	(void)stack;
	// implement later
}

t_stack *stack_last(t_stack *stack)
{
    if (!stack)
        return (NULL);
    while (stack->next)
        stack = stack->next;
    return (stack);
}

int get_stack_size(t_stack *stack)
{
    int size;

    size = 0;
    while (stack != NULL)
    {
        size++;
        stack = stack->next;
    }
    return (size);
}

int find_min_idx(t_stack *stack)
{
    int min_val;
    int min_index;
    int current_index;

    if (!stack)
        return (0);
    min_val = stack->value;
    min_index = 0;
    current_index = 0;
    while (stack != NULL)
    {
        if (stack->value < min_val)
        {
            min_val = stack->value;
            min_index = current_index;
        }
        stack = stack->next;
        current_index++;
    }
    return (min_index);
}
