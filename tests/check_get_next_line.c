#include <stdlib.h>
#include <check.h>
#include <ctype.h>
#include "../src/get_next_line.h"

static const char *answer_one_line[] = {
		"test_one"
};

static const char *answer_two_line[] = {
		"test_one", "test_two", ""
};

START_TEST (get_next_line_one_line)
	{
	char *s = NULL;
	int fd = open("test_one_line.txt", O_RDONLY);
	int res;
	ck_assert_int_gt(fd, -1);
	res = get_next_line(fd, &s);
	ck_assert_str_eq(s, answer_one_line[0]);
	ck_assert_int_eq(res, 0);
	close(fd);
	free(s);
	}
END_TEST

START_TEST (get_next_line_two_line)
	{
		char *s = NULL;
		int fd = open("test_two_line.txt", O_RDONLY);
		int res;
		int i = 0;
		ck_assert_int_gt(fd, -1);
		while((res = get_next_line(fd, &s)))
		{
			ck_assert_str_eq(s, answer_two_line[i]);
			i++;
		}
		ck_assert_int_eq(res, 0);
		close(fd);
		free(s);
	}
END_TEST

START_TEST (get_next_line_empty_file)
	{
		char *s = NULL;
		int fd = open("empty.txt", O_RDONLY);
		int res;

		ck_assert_int_gt(fd, -1);
		while((res = get_next_line(fd, &s)))
		{
			ck_assert_str_eq(s, NULL);
		}
		ck_assert_int_eq(res, 0);
		close(fd);
		free(s);
	}
END_TEST

START_TEST (get_next_line_many_newline_file)
	{
		char *s = NULL;
		int fd = open("empty.txt", O_RDONLY);
		int res;

		ck_assert_int_gt(fd, -1);
		while((res = get_next_line(fd, &s)))
		{
			ck_assert_str_eq(s, NULL);
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

	tcase_add_test(tc_core, get_next_line_one_line);
	tcase_add_test(tc_core, get_next_line_two_line);
	tcase_add_test(tc_core, get_next_line_empty_file);
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


