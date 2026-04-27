/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanar <dyanar@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 18:49:30 by dyanar            #+#    #+#             */
/*   Updated: 2026/04/27 18:55:15 by dyanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack != NULL)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int	find_min_idx(t_stack *stack)
{
	int	min_val;
	int	min_index;
	int	current_index;

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

int	count_smaller_than(t_stack *stack, int value)
{
	int	count;

	count = 0;
	while (stack)
	{
		if (stack->value < value)
			count++;
		stack = stack->next;
	}
	return (count);
}

void	stack_normalize(t_stack *stack)
{
	t_stack	*tmp_stack;

	tmp_stack = stack;
	while (tmp_stack)
	{
		tmp_stack->normalized_value
			= count_smaller_than(stack, tmp_stack->value);
		tmp_stack = tmp_stack->next;
	}
}
