/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanar <dyanar@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 21:59:46 by dyanar            #+#    #+#             */
/*   Updated: 2026/04/06 21:59:50 by dyanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "push_swap.h"
#include "libft.h"
#include <limits.h>

void	free_argv(char **argv)
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

static int	is_nbr(char *s)
{
	char	**argv;
	char	**tmp_argv;
	int		i;

	argv = ft_split(s, ' ');
	tmp_argv = argv;
	while (*argv)
	{
		if (is_long(*argv))
			return (free_argv(tmp_argv), 0);
		i = -1;
		if (**argv == '-' || **argv == '+')
			i++;
		while ((*argv)[++i])
			if (!ft_isdigit((*argv)[i]))
				return (free_argv(tmp_argv), 0);
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
		if (has_num_seq && !is_nbr(*argv))
			num_seq_end = 1;
		if (is_nbr(*argv))
			has_num_seq = 1;
		else if (!is_valid_flag(*argv))
			return (0);
		if (num_seq_end && ft_isdigit(**argv))
			return (0);
	}
	return (has_num_seq);
}
