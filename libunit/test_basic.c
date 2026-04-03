#include "unit.h"

int test_basic()
{
	TEST_STDOUT_FUNC(printf, printf, "ABC");
	TEST_STDOUT_FUNC(printf, printf, "AB");
	return (1);
}

int test_fail()
{
	TEST_STDOUT_FUNC(printf, printf, "ABC");
	TEST(0, 1);
	return (1);
}

REGISTER_TEST(test_basic)
REGISTER_TEST(test_fail)
