/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekablan <ekablan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 18:45:56 by dyanar            #+#    #+#             */
/*   Updated: 2026/04/28 21:55:09 by dyanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_float_two_decimals(float num)
{
	int	integer_part;
	int	fractional_part;

	num += 0.005f;
	integer_part = (int)num;
	fractional_part = (int)((num - integer_part) * 100);
	ft_putnbr_fd(integer_part, 2);
	write(2, ".", 1);
	if (fractional_part < 10)
		write(2, "0", 1);
	ft_putnbr_fd(fractional_part, 2);
}

void	print_benchmark(t_ctx *ctx)
{
	if (!ctx || ctx->bench == 0)
		return ;
	ft_printf("[bench] disorder: ");
	print_float_two_decimals(ctx->benchmark.disorder * 100.0f);
	ft_printf("%%\n");
	ft_printf("[bench] strategy: %s\n", ctx->benchmark.strategy);
	ft_printf("[bench] total_ops: %d\n", ctx->benchmark.total_ops);
	ft_printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
		ctx->benchmark.sa, ctx->benchmark.sb, ctx->benchmark.ss,
		ctx->benchmark.pa, ctx->benchmark.pb);
	ft_printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		ctx->benchmark.ra, ctx->benchmark.rb, ctx->benchmark.rr,
		ctx->benchmark.rra, ctx->benchmark.rrb, ctx->benchmark.rrr);
}
