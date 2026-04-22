/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanar <dyanar@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 21:38:07 by dyanar            #+#    #+#             */
/*   Updated: 2026/04/14 18:15:33 by dyanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stacks(t_stack *a, t_stack *b)
{
    printf("--- STACK A --- | --- STACK B ---\n");
    while (a || b)
    {
        if (a)
        {
            printf("%15d | ", a->value);
            a = a->next;
        }
        else
            printf("                | ");
        if (b)
        {
            printf("%d\n", b->value);
            b = b->next;
        }
        else
            printf("\n");
    }
    printf("----------------------------------\n");
}

int	main(int argc, char **argv)
{
	t_ctx *ctx;
	t_stack *stack_b;

	stack_b = NULL;
	
	if (argc < 2)
		return (1);

	if (!is_input_valid(argc, argv))
		return (ft_putstr_fd("Error\n", 2), 1);

	ctx = parse(argc, argv);
	if (ctx == NULL)
		return (ft_putstr_fd("Error\n", 2), 1);

	print_stacks(ctx->stack, stack_b);

	if (ctx->bench)
		ctx->benchmark.disorder = calculate_disorder(ctx->stack);

	if (ctx->sort)
		ctx->sort(&(ctx->stack), &stack_b, ctx);

	print_stacks(ctx->stack, stack_b);
		
	if (ctx->bench)
		print_benchmark(ctx);

	stack_clear(&ctx->stack);
	free(ctx);
	return (0);
}

//  ./push_swap --complex 1 5 2 4 3
//  ./push_swap --bench --complex 3 1 2
