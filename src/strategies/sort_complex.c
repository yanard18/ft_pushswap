/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanar <dyanar@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 22:15:20 by dyanar            #+#    #+#             */
/*   Updated: 2026/04/11 22:15:21 by dyanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void print_stack(t_stack *stack)
{
	t_stack *next;

	next = stack;
	while (next)
	{
		printf("%d, ", next->value);
		next = next->next;
	}
	printf("\n");
}

static int	get_max_normalized_val(t_stack *stack)
{
	int	max_value;

	max_value = 0;
	while (stack)
	{
		if (stack->normalized_value > max_value)
			max_value = stack->normalized_value;
		stack = stack->next;
	}
	return (max_value);
}

static int	get_bits_count(int value)
{
	int count = 0;
    
    while (value) 
    {
        count++; // Just add 1 for every bit position
        value >>= 1;
    }
    return (count);
}

static int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}



void complex_sort(t_stack **stack_a, t_stack **stack_b)
{
    int i;
    int j;
    int size;
    int max_bits;

	printf("original stack: ");
	print_stack(*stack_a);
    stack_normalize(*stack_a);
    size = stack_size(*stack_a);
    max_bits = get_bits_count(get_max_normalized_val(*stack_a));
    i = 0;
    while (i < max_bits)
    {
        j = 0;
        while (j < size)
        {
            if ((((*stack_a)->normalized_value >> i) & 1) == 0)
                pb(stack_a, stack_b);
            else
                ra(stack_a, 1);
            j++;
        }
        // Empty Stack B back into Stack A
        while (*stack_b != NULL)
            pa(stack_a, stack_b);
        i++;
    }
	print_stack(*stack_a);
}
