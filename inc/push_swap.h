/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekablan <ekablan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 21:09:52 by ekablan           #+#    #+#             */
/*   Updated: 2026/04/06 22:32:08 by ekablan          ###   ########.fr       */
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

void	stack_push(t_stack *s, int value, int direction);
int		stack_pop(t_stack *s);
void	stack_swap(t_stack *s);
void	stack_rotate(t_stack *s);
void	stack_rrotate(t_stack *s);
void	init_stack(t_stack *stack, int size);
void	fill_stack(t_stack *stack, int *num_buf, int size);

#endif
