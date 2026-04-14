/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanar <dyanar@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 22:15:20 by dyanar            #+#    #+#             */
/*   Updated: 2026/04/11 22:15:21 by dyanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void print_stack(t_stack *stack)
{
	t_stack *next;

	next = stack;
	while (next)
	{
		printf("%d, ", next->value);
		next = next->next;
	}
	printf("\n");
}

void	complex_sort(t_stack **stack_a, t_stack **stack_b)
{
	(void)stack_b;
	print_stack(*stack_a);
}
