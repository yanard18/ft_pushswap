/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekablan <ekablan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 21:06:24 by ekablan           #+#    #+#             */
/*   Updated: 2026/04/04 21:06:42 by ekablan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *s)
{
	if (s->size < 2)
		return ;
	s->start = (s->start + 1 + s->capacity) % s->capacity;
	s->end = (s->end + 1 + s->capacity) % s->capacity;
}

void	rrotate(t_stack *s)
{
	if (s->size < 2)
		return ;
	s->start = (s->start - 1 + s->capacity) % s->capacity;
	s->end = (s->end - 1 + s->capacity) % s->capacity;
}

void	swap(t_stack *s)
{
	int	tmp;
	int	second_index;

	if (s->size < 2)
		return ;
	second_index = (s->start + 1) % s->capacity;
	tmp = s->value[s->start];
	s->value[s->start] = s->value[second_index];
	s->value[second_index] = tmp;
}

void	push(t_stack *s, int value)
{
	if (s->size == 0)
	{
		s->start = 0;
		s->end = 0;
	}
	else
		s->start = (s->start - 1 + s->capacity) % s->capacity;
	s->value[s->start] = value;
	s->size++;
}

int	pop(t_stack *s)
{
	int	value;

	value = s->value[s->start];
	s->size--;
	if (s->size == 0)
	{
		s->start = 0;
		s->end = 0;
	}
	else
		s->start = (s->start + 1) % s->capacity;
	return (value);
}
