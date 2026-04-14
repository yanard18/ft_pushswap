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

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_stack *stack;
	t_stack *stack_b;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (1);
	stack_b = NULL;

	stack_push(&stack, 13);
	stack_push(&stack, 53);
	stack_push(&stack, 7);
	stack_push(&stack, 2);
	stack_push(&stack, 22);

	complex_sort(&stack, &stack_b);

	return (0);
}
