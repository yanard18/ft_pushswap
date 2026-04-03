#include "pushswap.h"
#include "libft.h"

static int	is_valid_flag(char *s)
{
	if (ft_strncmp(s, "--simple", 8) == 0)
		return (1);
	return (0);
}

static int	is_valid_number(char *s)
{
	char	**argv;

	argv = ft_split(s, ' ');
	while (*argv)
	{
		if(!ft_isdigit(**argv))
			return (0);
		argv++;
	}
	return (1);
}
int	is_input_valid(int argc, char **argv)
{
	int		i;

	if (argc <= 1)
		return (0);
	i = 0;
	while (++i < argc)
	{
		char *str = argv[i];
		if (!is_valid_number(str) && !is_valid_flag(str))
			return (0);
	}
	return (1);
}
