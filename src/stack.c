/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanar <dyanar@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 18:49:37 by dyanar            #+#    #+#             */
/*   Updated: 2026/04/27 18:55:18 by dyanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_push(t_stack **stack, int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = *stack;
	*stack = new_node;
}

int	stack_pop(t_stack **stack)
{
	t_stack	*temp;
	int		val;

	if (!stack || !*stack)
		return (0);
	temp = *stack;
	val = temp->value;
	*stack = (*stack)->next;
	free(temp);
	return (val);
}

int	stack_pop_normalized(t_stack **stack)
{
	t_stack	*temp;
	int		val;

	if (!stack || !*stack)
		return (0);
	temp = *stack;
	val = temp->normalized_value;
	*stack = (*stack)->next;
	free(temp);
	return (val);
}

void	stack_clear(t_stack **stack)
{
	t_stack	*next;

	if (!stack)
		return ;
	while (*stack)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = next;
	}
	*stack = NULL;
}

t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
