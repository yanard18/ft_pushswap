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

void	init_stacks(t_stack *a, t_stack *b, int size)
{
	a->value = malloc(sizeof(int) * size);
	b->value = malloc(sizeof(int) * size);
	a->capacity = size;
	b->capacity = size;
	a->size = 0;
	b->size = 0;
	a->start = 0;
	b->start = 0;
	a->end = 0;
	a->end = 0;
}

void	fill_stack_a(t_stack *a, int *numbers, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		a->value[i] = numbers[i];
		i++;
	}
	a->size = size;
	a->start = 0;
	a->end = size - 1;
}
