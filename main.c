/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishat <rishat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 23:14:36 by rishat            #+#    #+#             */
/*   Updated: 2021/01/01 19:13:19 by rishat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <check.h>
#include <unistd.h>
#include <stdlib.h>
#include "src/get_next_line.h"

int main()
{
	char *s = NULL;
	int fd = open("test_case/emptylines", O_RDONLY);
	int res;

	while((res = get_next_line(fd, &s)))
	{
		printf("|%s\n",s);
		free(s);
	}
	printf("%s\n",s);
	free(s);
	close(fd);


	int fd2 = open("test_case/emptylines", O_RDONLY);
	int res2;

	while((res2 = get_next_line(fd2, &s)))
	{
		printf("|%s\n",s);
		free(s);
	}
	printf("%s\n",s);
	free(s);
	close(fd2);
	return (0);
}
