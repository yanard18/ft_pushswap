#include "../inc/push_swap.h"

int	ps_atoi(const char *str)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

void sort_three(t_stack **a)
{
    int top;
    int middle;
    int bottom;

    if (!(*a)->next || !(*a)->next->next)
        return ;
    top = (*a)->value;
    middle = (*a)->next->value;
    bottom = (*a)->next->next->value;
    
    if (top > middle && top > bottom)
        ra(a, 1);
    else if (top < middle && middle > bottom)
        rra(a, 1);
        
    if ((*a)->value > (*a)->next->value)
        sa(a, 1);
}