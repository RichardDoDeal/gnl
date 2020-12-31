/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishat <rishat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 23:14:36 by rishat            #+#    #+#             */
/*   Updated: 2020/12/31 13:52:05 by rishat           ###   ########.fr       */
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
	int fd = open("test_two_line.txt", O_RDONLY);
	int res;

	while((res = get_next_line(fd, &s)))
	{		
		printf("%s",s);
		free(s);
	}
	close(fd);

	return (0);
}
