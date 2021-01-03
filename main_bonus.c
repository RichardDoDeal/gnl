/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishat <rishat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 23:14:36 by rishat            #+#    #+#             */
/*   Updated: 2021/01/03 18:22:39 by rishat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <check.h>
#include <unistd.h>
#include <stdlib.h>
#include "src/get_next_line_bonus.h"

int main()
{
	
	char *s = NULL;
	int fd = open("test_case/multipleshortlines", O_RDONLY);
	int res;

	int fd2 = open("test_case/multipleshortlines", O_RDONLY);
	//int res2;

	res = get_next_line(fd, &s);
	printf("%d|%d|%s\n",res,fd,s);
	free(s);

	res = get_next_line(fd2, &s);
	printf("%d|%d|%s\n",res,fd2,s);
	free(s);

	res = get_next_line(fd, &s);
	printf("%d|%d|%s\n",res,fd,s);
	free(s);

	res = get_next_line(fd2, &s);
	printf("%d|%d|%s\n",res,fd2,s);
	free(s);

		res = get_next_line(fd, &s);
	printf("%d|%d|%s\n",res,fd,s);
	free(s);

	res = get_next_line(fd2, &s);
	printf("%d|%d|%s\n",res,fd2,s);
	free(s);

	res = get_next_line(fd, &s);
	printf("%d|%d|%s\n",res,fd,s);
	free(s);

	res = get_next_line(fd2, &s);
	printf("%d|%d|%s\n",res,fd2,s);
	free(s);

	res = get_next_line(fd, &s);
	printf("%d|%d|%s\n",res,fd,s);
	free(s);

	res = get_next_line(fd2, &s);
	printf("%d|%d|%s\n",res,fd2,s);
	free(s);
	
	res = get_next_line(fd, &s);
	printf("%d|%d|%s\n",res,fd,s);
	free(s);

	res = get_next_line(fd2, &s);
	printf("%d|%d|%s\n",res,fd2,s);
	free(s);

	close(fd);
	close(fd2);
	
	while (1)
	{
		
	}
	

	return (0);
}
