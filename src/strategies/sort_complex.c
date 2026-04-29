/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekablan <ekablan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 22:15:20 by dyanar            #+#    #+#             */
/*   Updated: 2026/04/27 19:13:08 by dyanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int	count;

	count = 0;
	while (value)
	{
		count++;
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

void	complex_sort(t_stack **stack_a, t_stack **stack_b, t_ctx *ctx)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	if (handle_small_stacks(stack_a, stack_b, ctx))
		return ;
	size = stack_size(*stack_a);
	stack_normalize(*stack_a);
	max_bits = get_bits_count(get_max_normalized_val(*stack_a));
	i = -1;
	while (++i < max_bits)
	{
		if (is_sorted(*stack_a))
			break ;
		j = -1;
		while (++j < size)
		{
			if ((((*stack_a)->normalized_value >> i) & 1) == 0)
				pb(stack_a, stack_b, ctx);
			else
				ra(stack_a, ctx, 1);
		}
		while (*stack_b)
			pa(stack_a, stack_b, ctx);
	}
}
