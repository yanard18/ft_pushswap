#include "pushswap.h"
#include "push_swap.h"
#include "libft.h"
#include <limits.h>

static int	is_valid_flag(char *s)
{
	if (ft_strncmp(s, "--simple", 8) == 0)
		return (1);
	else if (ft_strncmp(s, "--medium", 8) == 0)
		return (1);
	else if (ft_strncmp(s, "--complex", 9) == 0)
		return (1);
	else if (ft_strncmp(s, "--adaptive", 10) == 0)
		return (1);
	else if (ft_strncmp(s, "--bench", 10) == 0)
		return (1);
	return (0);
}

static int	is_long(const char *nptr)
{
	long	i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		if (result * sign > INT_MAX)
			return (1);
		else if (result * sign < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

static int	is_valid_number(char *s)
{
	char	**argv;
	char	**tmp_argv;

	argv = ft_split(s, ' ');
	tmp_argv = argv;
	while (*argv)
	{
		if (is_long(*argv))
		{
			free_argv(tmp_argv);
			return (0);
		}
		int i = 0;
		if ((*argv)[i] == '-' || (*argv)[i] == '+')
			i++;
		while ((*argv)[i])
		{
			if (!ft_isdigit((*argv)[i]))
			{
				free_argv(tmp_argv);
				return (0);
			}
			i++;
		}
		argv++;
	}
	free_argv(tmp_argv);
	return (1);
}

int	is_input_valid(int argc, char **argv)
{
	int		has_num_seq;
	int		num_seq_end;

	if (argc <= 1 && !argv)
		return (0);
	has_num_seq = 0;
	num_seq_end = 0;
	while (*++argv)
	{
		if (has_num_seq && !is_valid_number(*argv))
			num_seq_end = 1;
		if (is_valid_number(*argv))
			has_num_seq = 1;
		else if (!is_valid_flag(*argv))
			return (0);
		if (num_seq_end && ft_isdigit(**argv))
			return (0);
	}
	return (has_num_seq);
}

void	free_argv(char **argv)
{
	int	i;

	i = -1;
	while (argv[++i])
		free(argv[i]);
	free(argv);
}

int		get_nbrs_in_str(char *s)
{
	int		argc;
	char	**argv;
	
	argv = ft_split(s, ' ');
	if (!argv)
		return (0);
	argc = 0;
	while (argv[argc])
		argc++;
	free_argv(argv);
	return (argc);
}

static void	push_atoi(t_stack *stack, char *s)
{
	char	**argv;
	int		argc;

	argv = ft_split(s, ' ');
	if (!argv)
		return ;
	argc = 0;
	while (argv[argc])
		argc++;
	while (--argc >= 0)
	{
		push(stack, ft_atoi(argv[argc]));
		free(argv[argc]);
	}
	free(argv);
}


t_stack		create_stack(int argc, char **argv)
{
	t_stack	stack;
	int		i;
	int		size;

	size = 0;
	i = 0;
	
	while (argv[++i])
	{
		if (ft_isdigit(argv[i][0]) || argv[i][0] == '-' || argv[i][0] == '+')
			size += get_nbrs_in_str(argv[i]);
	}
	init_stack(&stack, size);
	i = argc;
	while (--argc > 0)
		push_atoi(&stack, argv[argc]);
	return (stack);
}

void	simple_sort(t_stack *stack_a)
{
	(void)stack_a;
}
void	medium_sort(t_stack *stack_a)
{
	(void)stack_a;
}
void	complex_sort(t_stack *stack_a)
{
	(void)stack_a;
}
void	adaptive_sort(t_stack *stack_a)
{
	(void)stack_a;
}

t_ctx	*parse(int argc, char **argv)
{
	t_ctx	*ctx;

	ctx = malloc(sizeof(t_ctx));
	if (!ctx)
		return (NULL);
	ctx->stack = create_stack(argc, argv);
	ctx->sort = &adaptive_sort;
	while (*++argv)
	{
		if (ft_strncmp(*argv, "--bench", 7) == 0)
			ctx->bench = 1;
		else
			ctx->bench = 0;
		if (ft_strncmp(*argv, "--simple", 8) == 0)
			ctx->sort = &simple_sort;
		else if (ft_strncmp(*argv, "--medium", 8) == 0)
			ctx->sort = &medium_sort;
		else if (ft_strncmp(*argv, "--complex", 9) == 0)
			ctx->sort = &complex_sort;
		else if (ft_strncmp(*argv, "--adaptive", 10) == 0)
			ctx->sort = &adaptive_sort;
	}
	return (ctx);
}
