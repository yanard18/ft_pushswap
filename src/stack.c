/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekablan <ekablan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 21:04:24 by ekablan           #+#    #+#             */
/*   Updated: 2026/04/04 21:06:04 by ekablan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack, int size)
{
	stack->value = malloc(sizeof(int) * size);
	stack->capacity = size;
	stack->size = 0;
	stack->start = 0;
	stack->end = 0;
}

void	fill_stack(t_stack *stack, int *num_buf, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		stack->value[i] = num_buf[i];
		i++;
	}
	stack->size = size;
	stack->start = 0;
	stack->end = size - 1;
}
