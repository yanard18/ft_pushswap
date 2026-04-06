/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekablan <ekablan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 21:09:52 by ekablan           #+#    #+#             */
/*   Updated: 2026/04/05 05:17:07 by ekablan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*value;
	int	capacity;
	int	size;
	int	start;
	int	end;
}				t_stack;

int	ps_atoi(const char *str);
void	push(t_stack *s, int value);
int		pop(t_stack *s);
void	swap(t_stack *s);
void	rotate(t_stack *s);
void	rrotate(t_stack *s);
void	init_stack(t_stack *stack, int size);
void	fill_stack(t_stack *stack, int *num_buf, int size);
void pb(t_stack *a, t_stack *b);
void pa(t_stack *b, t_stack *a);
void ra(t_stack *a);
void rb(t_stack *b);
void rr(t_stack *a, t_stack *b);

#endif
