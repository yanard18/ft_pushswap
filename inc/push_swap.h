/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekablan <ekablan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 21:09:52 by ekablan           #+#    #+#             */
/*   Updated: 2026/04/04 21:11:31 by ekablan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_stack
{
	int	*value;
	int	capacity;
	int	size;
	int	start;
	int	end;
}				t_stack;

int		ps_atoi(const char *str);
void	push(t_stack *s, int value);
int		pop(t_stack *s);
void	swap(t_stack *s);
void	rotate(t_stack *s);
void	rev_rotate(t_stack *s);
void	init_stacks(t_stack *a, t_stack *b, int count);
void	fill_stack_a(t_stack *a, int *valid_ints, int count);

#endif