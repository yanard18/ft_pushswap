/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanar <dyanar@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 19:04:56 by dyanar            #+#    #+#             */
/*   Updated: 2026/04/27 19:06:54 by dyanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_three(t_stack **stack_a, t_ctx *ctx)
{
	int	top;
	int	middle;
	int	bottom;

	if (!(*stack_a) || !(*stack_a)->next || !(*stack_a)->next->next)
		return ;
	top = (*stack_a)->value;
	middle = (*stack_a)->next->value;
	bottom = (*stack_a)->next->next->value;
	if (top > middle && top > bottom)
		ra(stack_a, ctx, 1);
	else if (top < middle && middle > bottom)
		rra(stack_a, ctx, 1);
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a, ctx, 1);
}

void	sort_two(t_stack **stack_a, t_ctx *ctx)
{
	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a, ctx, 1);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b, t_ctx *ctx)
{
	int	size;
	int	min_idx;

	while (get_stack_size(*stack_a) > 3)
	{
		size = get_stack_size(*stack_a);
		min_idx = find_min_idx(*stack_a);
		if (min_idx <= size / 2)
			while (min_idx-- > 0)
				ra(stack_a, ctx, 1);
		else
			while (min_idx++ < size)
				rra(stack_a, ctx, 1);
		pb(stack_a, stack_b, ctx);
	}
	sort_three(stack_a, ctx);
	while (get_stack_size(*stack_b) > 0)
		pa(stack_a, stack_b, ctx);
}

int	handle_small_stacks(t_stack **stack_a, t_stack **stack_b, t_ctx *ctx)
{
	int	size;

	if (!stack_a || !*stack_a)
		return (1);
	if (is_sorted(*stack_a))
		return (1);
	size = get_stack_size(*stack_a);
	if (size == 2)
		sort_two(stack_a, ctx);
	else if (size == 3)
		sort_three(stack_a, ctx);
	else if (size <= 5)
		sort_five(stack_a, stack_b, ctx);
	else
		return (0);
	return (1);
}
