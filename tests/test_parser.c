#include "unit.h"
#include "pushswap.h"
#include "libft.h"

static		void free_argv(int argc, char **argv)
{
	for (int i = 0; i<argc; i++)
		free(argv[i]);
	free(argv);
}

static int	__is_input_valid(char *input, char delim)
{
		int		argc;
		char	**argv;

		argv = ft_split(input, delim);
		for (argc=0; argv[argc]; argc++);
		int res = is_input_valid(argc, argv);
		free_argv(argc, argv);
		return (res);
}

int	test_input_validation()
{
	TEST(__is_input_valid("./push_swap", ' '),
		 0, "given argc=1 expected 0 but returned 1");

	TEST(__is_input_valid("./push_swap 1 2 3 4 5", ' '),
		 1, "given ./push_swap 1 2 3 4 5 expected 1 but returned 0");

	TEST(__is_input_valid("./push_swap+1 2 3 4 5", '+'),
		 1, "given ./push_swap '1 2 3 4 5' expected 1 but returned 0");

	TEST(__is_input_valid("./push_swap invalid", ' '),
		 0, "given arg without \"--\" prefix, expected 0, but returned 1");

	TEST(__is_input_valid("./push_swap --invalid", ' '),
		 0, "given --invalid flag, expected 0, but returned 1");

	TEST(__is_input_valid("./push_swap --simple 1 2 3", ' '),
		 1, "given \"--simple 1 2 3\", expected 1, but returned 0");

	TEST(__is_input_valid("./push_swap --medium 1 2 3", ' '),
		 1, "given \"--medium 1 2 3\", expected 1, but returned 0");

	TEST(__is_input_valid("./push_swap --complex 1 2 3", ' '),
		 1, "given \"--complex 1 2 3\", expected 1, but returned 0");

	TEST(__is_input_valid("./push_swap --adaptive 1 2 3", ' '),
		 1, "given \"--adaptive 1 2 3\", expected 1, but returned 0");

	return (1);
}

REGISTER_TEST(test_input_validation);
