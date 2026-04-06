#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft.h"
# include "push_swap.h"

typedef struct s_ctx
{
	t_stack	stack;
	void	(*sort)(t_stack *);
	int		bench;
}	t_ctx;


int		is_input_valid(int argc, char **argv);
t_ctx	*parse(int argc, char **argv);
		
void	free_argv(char **argv);

void	simple_sort(t_stack *stack_a);
void	medium_sort(t_stack *stack_a);
void	complex_sort(t_stack *stack_a);
void	adaptive_sort(t_stack *stack_a);

#endif
