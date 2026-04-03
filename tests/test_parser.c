#include "unit.h"
#include "pushswap.h"

int	test_input_validation()
{
	char **argv = (char **)malloc(sizeof(char **));
	return (is_input_valid(argv));
}

REGISTER_TEST(test_input_validation);
