/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanar <dyanar@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 18:59:57 by dyanar            #+#    #+#             */
/*   Updated: 2026/04/27 18:59:58 by dyanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a, t_ctx *ctx, int print)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!*a || !(*a)->next)
		return ;
	second_last = *a;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *a;
	*a = last;
	if (print)
	{
		write(1, "rra\n", 4);
		if (ctx && ctx->bench)
		{
			ctx->benchmark.rra++;
			ctx->benchmark.total_ops++;
		}
	}
}

void	rrb(t_stack **b, t_ctx *ctx, int print)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!*b || !(*b)->next)
		return ;
	second_last = *b;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *b;
	*b = last;
	if (print)
	{
		write(1, "rrb\n", 4);
		if (ctx && ctx->bench)
		{
			ctx->benchmark.rrb++;
			ctx->benchmark.total_ops++;
		}
	}
}

void	rrr(t_stack **a, t_stack **b, t_ctx *ctx)
{
	int	can_rra;
	int	can_rrb;

	can_rra = (*a && (*a)->next);
	can_rrb = (*b && (*b)->next);
	if (!can_rra && !can_rrb)
		return ;
	if (can_rra)
		rra(a, ctx, 0);
	if (can_rrb)
		rrb(b, ctx, 0);
	write(1, "rrr\n", 4);
	if (ctx && ctx->bench)
	{
		ctx->benchmark.rrr++;
		ctx->benchmark.total_ops++;
	}
}
