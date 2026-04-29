/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanar <dyanar@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 19:07:15 by dyanar            #+#    #+#             */
/*   Updated: 2026/04/27 19:07:39 by dyanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_adaptive_string(t_ctx *ctx, float disorder)
{
	if (disorder < 20.0)
		ctx->benchmark.strategy = "Adaptive / O(n²)";
	else if (disorder >= 20.0 && disorder < 50.0)
		ctx->benchmark.strategy = "Adaptive / O(n√n)";
	else if (disorder >= 50.0)
		ctx->benchmark.strategy = "Adaptive / O(nlogn)";
}

void	adaptive_sort(t_stack **stack_a, t_stack **stack_b, t_ctx *ctx)
{
	float	disorder;
	int		size;

	if (!stack_a || !*stack_a)
		return ;
	disorder = calculate_disorder(*stack_a);
	set_adaptive_string(ctx, disorder);
	if (handle_small_stacks(stack_a, stack_b, ctx))
		return ;
	if (disorder == 0.0)
		return ;
	size = get_stack_size(*stack_a);
	if (size <= 100)
		medium_sort(stack_a, stack_b, ctx);
	else if (disorder < 20.0)
		simple_sort(stack_a, stack_b, ctx);
	else if (disorder >= 20.0 && disorder < 50.0)
		medium_sort(stack_a, stack_b, ctx);
	else if (disorder >= 50.0)
		complex_sort(stack_a, stack_b, ctx);
}
