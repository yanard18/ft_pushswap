#include "unit.h"
#include "pushswap.h"
#include "libft.h"

int	test_input_validation()
{
	char **argv = ft_split("push_swap 1 2 3 4 5", ' ');
	TEST(is_input_valid(argv), 1);
	return (0);
}

REGISTER_TEST(test_input_validation);
