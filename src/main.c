/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekablan <ekablan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 21:38:07 by dyanar            #+#    #+#             */
/*   Updated: 2026/04/30 17:06:47 by dyanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ctx	*ctx;
	t_stack	*stack_b;

	stack_b = NULL;
	if (argc < 2)
		return (1);
	if (!is_input_valid(argc, argv))
		return (ft_putstr_fd("Error\n", 2), 1);
	ctx = parse(argc, argv);
	if (ctx == NULL)
		return (ft_putstr_fd("Error\n", 2), 1);
	if (ctx->bench)
		ctx->benchmark.disorder = calculate_disorder(ctx->stack);
	if (ctx->sort)
		ctx->sort(&(ctx->stack), &stack_b, ctx);
	if (ctx->bench)
		print_benchmark(ctx);
	stack_clear(&ctx->stack);
	free(ctx);
	return (0);
}
