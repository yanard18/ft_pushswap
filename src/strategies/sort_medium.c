/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanar <dyanar@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 19:24:54 by dyanar            #+#    #+#             */
/*   Updated: 2026/04/27 19:26:20 by dyanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	assign_idx(t_stack *stack)
{
	t_stack	*current;
	t_stack	*compare;

	current = stack;
	while (current)
	{
		current->index = 0;
		compare = stack;
		while (compare)
		{
			if (current->value > compare->value)
				current->index++;
			compare = compare->next;
		}
		current = current->next;
	}
}

static int	get_max_idx_position(t_stack *stack_b)
{
	int	max_value;
	int	max_idx;
	int	current_idx;

	if (!stack_b)
		return (0);
	max_value = stack_b->index;
	max_idx = 0;
	current_idx = 1;
	stack_b = stack_b->next;
	while (stack_b)
	{
		if (stack_b->index > max_value)
		{
			max_value = stack_b->index;
			max_idx = current_idx;
		}
		current_idx++;
		stack_b = stack_b->next;
	}
	return (max_idx);
}

static void	push_chunks_to_b(t_stack **a, t_stack **b, t_ctx *ctx, int c_size)
{
	int	pushed;

	pushed = 0;
	while (*a)
	{
		if ((*a)->index <= pushed)
		{
			pb(a, b, ctx);
			rb(b, ctx, 1);
			pushed++;
		}
		else if ((*a)->index <= pushed + c_size)
		{
			pb(a, b, ctx);
			pushed++;
		}
		else
			ra(a, ctx, 1);
	}
}

static void	push_chunks_to_a(t_stack **a, t_stack **b, t_ctx *ctx)
{
	int	size;
	int	max_idx;

	while (*b)
	{
		size = get_stack_size(*b);
		max_idx = get_max_idx_position(*b);
		while (max_idx != 0)
		{
			if (max_idx <= size / 2)
			{
				rb(b, ctx, 1);
				max_idx--;
			}
			else
			{
				rrb(b, ctx, 1);
				if (++max_idx == size)
					max_idx = 0;
			}
		}
		pa(a, b, ctx);
	}
}

void	medium_sort(t_stack **stack_a, t_stack **stack_b, t_ctx *ctx)
{
	int	size;
	int	chunk_size;

	if (!stack_a || !*stack_a || handle_small_stacks(stack_a, stack_b, ctx))
		return ;
	size = get_stack_size(*stack_a);
	assign_idx(*stack_a);
	chunk_size = 1;
	while (chunk_size <= size / chunk_size)
		chunk_size++;
	chunk_size--;
	push_chunks_to_b(stack_a, stack_b, ctx, chunk_size);
	push_chunks_to_a(stack_a, stack_b, ctx);
}
