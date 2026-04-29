/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekablan <ekablan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 21:09:52 by ekablan           #+#    #+#             */
/*   Updated: 2026/04/28 20:01:04 by ekablan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"

typedef struct s_stack
{
    int value;
	int	normalized_value;
	int	index;
    struct s_stack *next;
} t_stack;

typedef struct s_bench
{
	float	disorder;
	char	*strategy;
	int		total_ops;
    int		sa;
	int		sb;
	int		ss;
    int		pa; 
	int		pb;
    int		ra;
	int		rb; 
	int		rr;
    int		rra; 
	int		rrb; 
	int		rrr;
}   t_bench;

typedef struct s_ctx
{
	t_stack	*stack;
	void	(*sort)(t_stack **, t_stack **, struct s_ctx *ctx);
	int		bench;
	t_bench benchmark;
}	t_ctx;

void	stack_clear(t_stack **stack);
void 	stack_push(t_stack **stack, int value);
int 	stack_pop(t_stack **stack);
int 	stack_pop_normalized(t_stack **stack);
t_stack *stack_last(t_stack *stack);
void	stack_normalize(t_stack *stack);

void pb(t_stack **a, t_stack **b, t_ctx *ctx);
void pa(t_stack **a, t_stack **b, t_ctx *ctx);
void sa(t_stack **a, t_ctx *ctx, int print);
void sb(t_stack **b, t_ctx *ctx, int print);
void ss(t_stack **a, t_stack **b, t_ctx *ctx);
void ra(t_stack **a, t_ctx *ctx, int print);
void rb(t_stack **b, t_ctx *ctx, int print);
void rr(t_stack **a, t_stack **b, t_ctx *ctx);
void rra(t_stack **a, t_ctx *ctx, int print);
void rrb(t_stack **b, t_ctx *ctx, int print);
void rrr(t_stack **a, t_stack **b, t_ctx *ctx);
int find_min_idx(t_stack *stack);
int get_stack_size(t_stack *stack);
float calculate_disorder(t_stack *stack_a);

int		is_input_valid(int argc, char **argv);
t_ctx	*parse(int argc, char **argv);
void	free_argv(char **argv);
void	simple_sort(t_stack **stack_a, t_stack **stack_b, t_ctx *ctx);
void	medium_sort(t_stack **stack_a, t_stack **stack_b, t_ctx *ctx);
void	complex_sort(t_stack **stack_a, t_stack **stack_b, t_ctx *ctx);
void	adaptive_sort(t_stack **stack_a, t_stack **stack_b, t_ctx *ctx);

void print_benchmark(t_ctx *ctx);
void set_adaptive_string(t_ctx *ctx, float disorder);

void sort_three(t_stack **stack_a, t_ctx *ctx);
void sort_two(t_stack **stack_a, t_ctx *ctx);
void sort_five(t_stack **stack_a, t_stack **stack_b, t_ctx *ctx);
int handle_small_stacks(t_stack **stack_a, t_stack **stack_b, t_ctx *ctx);

#endif
