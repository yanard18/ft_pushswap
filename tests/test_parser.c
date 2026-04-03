#include "unit.h"
#include "pushswap.h"
#include "libft.h"

int	test_input_validation()
{
	{
		char **argv = ft_split("push_swap", ' ');
		TEST(is_input_valid(1, argv), 0, "given argc=1 expected 0 but returned 1");
	}

	{
		char **argv = ft_split("push_swap 1 2 3 4 5", ' ');
		TEST(is_input_valid(6, argv), 1, "given only numbers as separate args expected 1 but returned 0");
	}
	return (1);
}

REGISTER_TEST(test_input_validation);
