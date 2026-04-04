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
