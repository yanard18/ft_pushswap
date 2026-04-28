/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekablan <ekablan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 18:45:56 by dyanar            #+#    #+#             */
/*   Updated: 2026/04/28 21:51:04 by dyanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_benchmark(t_ctx *ctx)
{
	if (!ctx || ctx->bench == 0)
		return ;
		
	ft_printf("[bench] disorder: %.2f%%\n", ctx->benchmark.disorder);
	ft_printf("[bench] strategy: %s\n", ctx->benchmark.strategy);
	ft_printf("[bench] total_ops: %d\n", ctx->benchmark.total_ops);
	ft_printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
		ctx->benchmark.sa, ctx->benchmark.sb, ctx->benchmark.ss,
		ctx->benchmark.pa, ctx->benchmark.pb);
	ft_printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		ctx->benchmark.ra, ctx->benchmark.rb, ctx->benchmark.rr,
		ctx->benchmark.rra, ctx->benchmark.rrb, ctx->benchmark.rrr);
}
