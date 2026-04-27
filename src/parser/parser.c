/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanar <dyanar@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 21:55:03 by dyanar            #+#    #+#             */
/*   Updated: 2026/04/27 19:04:35 by dyanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_atoi(t_stack **stack, char *s)
{
	char	**argv;
	int		argc;

	argv = ft_split(s, ' ');
	if (!argv)
		return ;
	argc = 0;
	while (argv[argc])
		argc++;
	while (--argc >= 0)
	{
		stack_push(stack, ft_atoi(argv[argc]));
		free(argv[argc]);
	}
	free(argv);
}

static t_stack	*create_stack(int argc, char **argv)
{
	t_stack	*stack;

	stack = NULL;
	while (argc-- > 1)
		if (ft_isdigit(argv[argc][0])
			|| (argv[argc][1] && argv[argc][0] == '-'
				&& ft_isdigit(argv[argc][1]))
			|| (argv[argc][1] && argv[argc][0] == '+'
				&& ft_isdigit(argv[argc][1])))
			push_atoi(&stack, argv[argc]);
	return (stack);
}

static void	set_strategy(t_ctx *ctx, char *argv)
{
	if (ft_strncmp(argv, "--bench", 7) == 0)
		ctx->bench = 1;
	if (ft_strncmp(argv, "--simple", 8) == 0)
	{
		ctx->sort = &simple_sort;
		ctx->benchmark.strategy = "Simple / O(n²)";
	}
	else if (ft_strncmp(argv, "--medium", 8) == 0)
	{
		ctx->sort = &medium_sort;
		ctx->benchmark.strategy = "Medium / O(n√n)";
	}
	else if (ft_strncmp(argv, "--complex", 9) == 0)
	{
		ctx->sort = &complex_sort;
		ctx->benchmark.strategy = "Complex / O(nlogn)";
	}
	else if (ft_strncmp(argv, "--adaptive", 10) == 0)
	{
		ctx->sort = &adaptive_sort;
		ctx->benchmark.strategy = "Adaptive / ?";
	}
}

static int	has_duplicate(t_stack *stack)
{
	t_stack	*iter_stack;

	while (stack)
	{
		iter_stack = stack->next;
		while (iter_stack)
		{
			if (iter_stack->value == stack->value)
				return (1);
			iter_stack = iter_stack->next;
		}
		stack = stack->next;
	}
	return (0);
}

t_ctx	*parse(int argc, char **argv)
{
	t_ctx	*ctx;

	ctx = malloc(sizeof(t_ctx));
	if (!ctx)
		return (NULL);
	ctx->stack = create_stack(argc, argv);
	if (ctx->stack == NULL || has_duplicate(ctx->stack))
		return (stack_clear(&ctx->stack), free(ctx), NULL);
	ctx->sort = &adaptive_sort;
	while (*++argv)
		set_strategy(ctx, *argv);
	return (ctx);
}
