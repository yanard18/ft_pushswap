/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekablan <ekablan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 21:09:52 by ekablan           #+#    #+#             */
/*   Updated: 2026/04/11 18:26:06 by ekablan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_stack
{
    int value;
    struct s_stack *next;
} t_stack;

int		ps_atoi(const char *str);
void	push(t_stack *s, int value);
int		pop(t_stack *s);
void	swap(t_stack *s);
void	rotate(t_stack *s);
void	rrotate(t_stack *s);
void	init_stack(t_stack *stack, int size);
void	fill_stack(t_stack *stack, int *num_buf, int size);
void	stack_clear(t_stack *stack);

int	ps_atoi(const char *str);
void stack_push(t_stack **stack, int value);
int stack_pop(t_stack **stack);
t_stack *stack_last(t_stack *stack);
void pb(t_stack **a, t_stack **b);
void pa(t_stack **a, t_stack **b);
void sa(t_stack **a, int print);
void sb(t_stack **b, int print);
void ss(t_stack **a, t_stack **b);
void ra(t_stack **a, int print);
void rb(t_stack **b, int print);
void rr(t_stack **a, t_stack **b);
void rra(t_stack **a, int print);
void rrb(t_stack **b, int print);
void rrr(t_stack **a, t_stack **b);
void sort_simple(t_stack **a, t_stack **b);
void sort_complex(t_stack **a, t_stack **b);
void sort_three(t_stack **a);
int find_min_idx(t_stack *stack);
int get_stack_size(t_stack *stack);
float calculate_disorder(t_stack *stack_a);
void adaptive_sort(t_stack **a, t_stack **b);


int move_counter(int increment);

#endif
