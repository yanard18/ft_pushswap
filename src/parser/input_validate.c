#include "pushswap.h"
#include "libft.h"

void free_argv(char **argv)
{
	int	i;

	i = -1;
	while (argv[++i])
		free(argv[i]);
	free(argv);
}

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

static int	is_valid_number(char *s)
{
	char	**argv;
	char	**tmp_argv;

	argv = ft_split(s, ' ');
	tmp_argv = argv;
	while (*argv)
	{
		int i = 0;
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
	int		i;
	int		has_num_seq;

	has_num_seq = 0;
	if (argc <= 1)
		return (0);
	i = 0;
	while (++i < argc)
	{
		char *str = argv[i];
		if (is_valid_number(str))
		{
			has_num_seq = 1;
			continue ;
		}
		else if (!is_valid_flag(str))
			return (0);
	}
	if (has_num_seq == 0)
		return (0);
	return (1);
}
