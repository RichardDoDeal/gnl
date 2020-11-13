#include <stdlib.h>
#include <check.h>
#include <ctype.h>
#include "../src/get_next_line.h"

static const char *answer[3] = {
		"test_one", "test_two",""
};

START_TEST (get_next_line_base_input1)
	{
	char *s = malloc(sizeof(char) * 9);
	if(!s)
	{
		ck_abort_msg("malloc failed not Error!");
	}
	int fd = open("test.txt",O_RDONLY);
	int res;
	while((res = get_next_line(fd, &s)) == 1)
	{
		ck_assert_str_eq(s, answer[_i]);
	}
	ck_assert_int_eq(res, 0);
	close(fd);
	free(s);
	}
END_TEST

Suite * ft_get_next_line_suite(void)
{
	Suite *s;
	TCase *tc_core;

	s = suite_create("get_next_line_base");

	/* Core test case */
	tc_core = tcase_create("Core");

	tcase_add_test(tc_core, get_next_line_base_input1);
	suite_add_tcase(s, tc_core);
	return s;
}

int main(void)
{
	int number_failed = 0;
	Suite *s;
	SRunner *sr;
	s = ft_get_next_line_suite();
	sr = srunner_create(s);
	srunner_run_all(sr, CK_NORMAL);
	number_failed += srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}


