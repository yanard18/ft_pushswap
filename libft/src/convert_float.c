/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanar <dyanar@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 20:49:40 by dyanar            #+#    #+#             */
/*   Updated: 2026/04/28 20:51:49 by dyanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_int_len(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	fill_f_str(char *res, double frac, long int_part, int sign)
{
	int		i;
	int		len;
	long	temp;

	len = get_int_len(int_part);
	i = 0;
	while (i < 2)
	{
		frac *= 10.0;
		res[sign + len + 1 + i] = "0123456789"[(long)frac % 10];
		frac -= (long)frac;
		i++;
	}
	res[sign + len] = '.';
	temp = int_part;
	i = sign + len - 1;
	if (temp == 0)
		res[i] = '0';
	while (temp != 0)
	{
		res[i--] = "0123456789"[temp % 10];
		temp /= 10;
	}
	if (sign)
		res[0] = '-';
}

char	*convert_f(void *content, t_list *tokens)
{
	double	num;
	long	int_part;
	int		sign;
	int		int_len;
	char	*res;

	(void)tokens;
	num = *(double *)content;
	sign = 0;
	if (num < 0)
	{
		sign = 1;
		num = -num;
	}
	num += 0.005;
	int_part = (long)num;
	int_len = get_int_len(int_part);
	res = (char *)malloc(sizeof(char) * (sign + int_len + 4));
	if (!res)
		return (NULL);
	res[sign + int_len + 3] = '\0';
	fill_f_str(res, num - (double)int_part, int_part, sign);
	return (res);
}
