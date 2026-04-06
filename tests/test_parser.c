#include "unit.h"
#include "pushswap.h"

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

static t_ctx	*__parse(char *s, char delim)
{
	int		argc;
	char	**argv;
	t_ctx	*ctx;

	argv = ft_split(s, delim);
	for (argc=0; argv[argc]; argc++);
	ctx = parse(argc, argv);
	free_argv(argv);
	return (ctx);
}

int	test_input_parse()
{
	{
		t_ctx *ctx = __parse("./push_swap 1 2 3", ' ');
		int n1 = pop(&ctx->stack);
		int n2 = pop(&ctx->stack);
		int n3 = pop(&ctx->stack);
		// int n4 = pop(&ctx->stack);
		stack_clear(&ctx->stack);
		TEST(n1, 1, "for num_lst[0] != 1");
		TEST(n2, 2, "for num_lst[1] != 2");
		TEST(n3, 3, "for num_lst[2] != 3");
		// TEST(n4, 0, TEXT("pop() should return 0 when empty but was %d", n4));
	}

	{
		t_ctx *ctx = __parse("./push_swap?1 +2 -3 4", '?');
		int n1 = pop(&ctx->stack);
		int n2 = pop(&ctx->stack);
		int n3 = pop(&ctx->stack);
		stack_clear(&ctx->stack);
		TEST(n1, 1, TEXT("for 1st pop() expected: 1 but was: %d", n1));
		TEST(n2, 2, TEXT("for 2nd pop() expected: 2 but was: %d", n2));
		TEST(n3, -3, TEXT("for 3rd pop() expected: -3 but was: %d", n3));
	}

	{
		t_ctx *ctx = __parse("./push_swap 999 --simple --bench", ' ');
		int bench_flag = ctx->bench;
		int n = pop(&ctx->stack);
		stack_clear(&ctx->stack);
		TEST(bench_flag, 1, TEXT("given --bench arg should set ctx->bench 1 but was: %d", bench_flag));
		TEST(n, 999, TEXT("given --bench broked stack values. pop() exp: 999 but was: %d", n));
	}

	{
		t_ctx *ctx = __parse("./push_swap 999 --simple", ' ');
		int bench_flag = ctx->bench;
		stack_clear(&ctx->stack);
		TEST(bench_flag, 0, TEXT("given --bench arg should set ctx->bench 1 but was: %d", bench_flag));
	}

	{
		t_ctx *ctx = __parse("./push_swap 999 --simple", ' ');
		void (*f)(t_stack *) = ctx->sort;
		stack_clear(&ctx->stack);
		TEST(f, &simple_sort, "--simple flag didn't choose simple_sort()");
	}

	{
		t_ctx *ctx = __parse("./push_swap 999", ' ');
		void (*f)(t_stack *) = ctx->sort;
		stack_clear(&ctx->stack);
		TEST(f, &adaptive_sort, "no flag given should choose adaptive_sort()");
	}
	return (1);
}

REGISTER_TEST(test_input_validation);
REGISTER_TEST(test_input_parse);
