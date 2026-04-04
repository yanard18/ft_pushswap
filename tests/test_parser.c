#include "unit.h"
#include "pushswap.h"

/*
static void	__free_lst(void *content)
{
	(void)content;
}
*/


static int	__is_input_valid(char *input, char delim)
{
		int		argc;
		char	**argv;

		if (input == NULL)
			return (is_input_valid(0, NULL));
		argv = ft_split(input, delim);
		for (argc=0; argv[argc]; argc++);
		int res = is_input_valid(argc, argv);
		free_argv(argv);
		return (res);
}


int	test_input_validation()
{
	/* === Invalid Inputs === */

	TEST(__is_input_valid("./push_swap", ' '),
		 0, "given argc=1 expected 0 but returned 1");

	TEST(__is_input_valid("./push_swap invalid", ' '),
		 0, "given arg without \"--\" prefix, expected 0, but returned 1");

	TEST(__is_input_valid("./push_swap --invalid", ' '),
		 0, "given --invalid flag, expected 0, but returned 1");

	TEST(__is_input_valid("./push_swap --invalid 1 2 3", ' '),
		 0, "given ./push_swap --invalid 1 2 3, expected 0, but returned 1");

	TEST(__is_input_valid("./push_swap 1 2 3 --invalid", ' '),
		 0, "given ./push_swap 1 2 3 --invalid (invalid flag), expected 0, but returned 1");

	TEST(__is_input_valid("./push_swap --simple", ' '),
		 0, "given ./push_swawp --simple (without num sequence), expected 0, but returned 1");

	TEST(__is_input_valid("./push_swap -simple 1 2 3", ' '),
		 0, "given ./push_swawp -simple (correct flag with only one '-'), expected 0, but returned 1");

	TEST(__is_input_valid("./push_swap 0 one 2 3", ' '),
		 0, "given ./push_swap 0 one 2 3, expected 0, but returned 1");

	TEST(__is_input_valid("./push_swap 1a 2 3", ' '),
		 0, "given ./push_swap 1a 2 3, expected 0, but returned 1");

	TEST(__is_input_valid("./push_swap 0 --simple 2 3", ' '),
		 0, "given ./push_swap 0 --simple 2 3, expected 0, but returned 1");

	TEST(__is_input_valid(NULL, ' '),
		 0, "given (NULL) str expected 0, but returned 1");

	TEST(__is_input_valid("./push_swap --simple 21474836477 2 3", ' '),
		 0, "given (long) value, expected 1, but returned 0");

	TEST(__is_input_valid("./push_swap --simple --bench", ' '),
		 0, "given \"--simple 1 2 3\", expected 1, but returned 0");

	/*
	TEST(__is_input_valid("./push_swap 3 2 3", ' '),
		 0, "given ./push_swap 3 2 3 (duplicate numbers), expected 0, but returned 1");
	*/

	/* === Valid Inputs === */

	TEST(__is_input_valid("./push_swap --simple 1 2 3", ' '),
		 1, "given \"--simple 1 2 3\", expected 1, but returned 0");

	TEST(__is_input_valid("./push_swap -1 2 3", ' '),
		 1, "given \"--simple 1 2 3\", expected 1, but returned 0");

	TEST(__is_input_valid("./push_swap -1 +1 3", ' '),
		 1, "given -1 +1 3, expected 1, but returned 0");

	TEST(__is_input_valid("./push_swap --medium 1 2 3", ' '),
		 1, "given \"--medium 1 2 3\", expected 1, but returned 0");

	TEST(__is_input_valid("./push_swap --complex 1 2 3", ' '),
		 1, "given \"--complex 1 2 3\", expected 1, but returned 0");

	TEST(__is_input_valid("./push_swap --adaptive 1 2 3", ' '),
		 1, "given \"--adaptive 1 2 3\", expected 1, but returned 0");

	TEST(__is_input_valid("./push_swap --bench --adaptive 1 2 3", ' '),
		 1, "given --bench --adaptive 1 2 3, expected 1, but returned 0");

	TEST(__is_input_valid("./push_swap --adaptive 1 2 3 --bench", ' '),
		 1, "given --adaptive 1 2 3 --bench, expected 1, but returned 0");

	TEST(__is_input_valid("./push_swap 1 2 3 4 5", ' '),
		 1, "given ./push_swap 1 2 3 4 5 expected 1 but returned 0");

	TEST(__is_input_valid("./push_swap+1 2 3 4 5", '+'),
		 1, "given ./push_swap '1 2 3 4 5' expected 1 but returned 0");

	TEST(__is_input_valid("./push_swap+1 2 3+4 5 6", '+'),
		 1, "given '1 2 3' '4 5 6' expected 1, but returned 0");


	/* === !WARNING: Check those tests and ensure they are correct === */
	TEST(__is_input_valid("./push_swap --simple --medium 1 2 3", ' '),
		 1, "given ./push_swawp -simple (two correct strategy), expected 0, but returned 1");


	return (1);
}

int	test_input_parse()
{
	{
		int		argc;
		char	**argv;

		argv = ft_split("./push_swap 1 2 3", ' ');
		for (argc=0; argv[argc]; argc++);

		t_ctx *ctx = parse(argc, argv);
		int n1 = *(int *)(ctx->num_lst->content);
		int n2 = *(int *)(ctx->num_lst->next->content);
		int n3 = *(int *)(ctx->num_lst->next->next->content);
		free_argv(argv);
		ft_lstclear(&ctx->num_lst, free);
		free(ctx);
		TEST(n1, 1, "for num_lst[0] != 1");
		TEST(n2, 2, "for num_lst[1] != 2");
		TEST(n3, 3, "for num_lst[2] != 3");
	}

	return (1);
}

REGISTER_TEST(test_input_validation);
REGISTER_TEST(test_input_parse);
