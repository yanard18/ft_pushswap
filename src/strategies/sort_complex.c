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

static int	stack_get(t_stack *stack, int n)
{
	int	i;

	i = 0;
	while (i < n && stack)
	{
		stack = stack->next;
		i++;
	}
	return (stack->value);
}

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

static void print_count(int count[10])
{
	int	i;

	i = 0;
	while (i < 10)
	{
		printf("%d, ", count[i]);
		i++;
	}
	printf("\n");
}

static void	count_sort(t_stack **stack, int n, int exp)
{
	int	*output;
	int	count[10] = {0};
	int	i = 0;


	output = malloc(sizeof(int) * n);
	if (!output)
		return ;

	t_stack *next = *stack;
	// store the count of occurance of the current digit
	for (i = 0; i < n && next; i++)
	{
		count[(next->value / exp) % 10]++;
		next = next->next;
	}

	
	printf("count freq: ");
	print_count(count);


	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	printf("cummilative sum: ");
	print_count(count);

	for (i = n - 1; i >= 0; i--)
	{
		output[count[(stack_get(*stack, i) / exp) % 10] - 1] = stack_get(*stack, i);
		count[(stack_get(*stack, i) / exp) % 10]--;
	}

	printf("last count: ");
	print_count(count);
}

void	complex_sort(t_stack **stack_a, t_stack **stack_b)
{
	(void)stack_b;
	count_sort(stack_a, 5, 1);
	print_stack(*stack_a);
}
