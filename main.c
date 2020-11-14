#include <stdio.h>
#include <check.h>
#include <unistd.h>
#include <stdlib.h>
#include "src/get_next_line.h"

int main()
{
	char *s = NULL;
	int fd = open("test_two_line.txt", O_RDONLY);
	int res;
//	ck_assert_int_gt(fd, -1);
	while((res = get_next_line(fd, &s)))
	{
		//ck_assert_str_eq(s, answer_one_line[_i]);
		printf("%s",s);
		free(s);
	}
	//ck_assert_int_gt(res, 0);
	close(fd);
//	free(s);
	return (0);
}
