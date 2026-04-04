#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft.h"

typedef struct s_ctx
{
	t_list	*num_lst;
	void	(*sort)(t_list **);
	int		bench;
}	t_ctx;


int		is_input_valid(int argc, char **argv);
t_ctx	*parse(int argc, char **argv);
		
void	free_argv(char **argv);


#endif
