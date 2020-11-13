/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahali <mamahali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:38:18 by mamahali          #+#    #+#             */
/*   Updated: 2020/11/12 12:47:11 by mamahali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	buf[BUFFER_SIZE];

int get_next_line(int fd, char **line)
{
	(void) line;
	int res;
	if (fd < 0)
		return (-1);
	res = read(fd, &buf, BUFFER_SIZE);
	res = res < 0 ? -1 : !!res;

	return (res);
}
