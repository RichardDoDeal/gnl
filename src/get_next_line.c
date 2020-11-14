/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahali <mamahali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:38:18 by mamahali          #+#    #+#             */
/*   Updated: 2020/11/14 14:43:32 by mamahali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stdio.h"
#include "get_next_line.h"

static char	buf[BUFFER_SIZE];
/*
static size_t get_len()
{
	char 	*p_buf;
	size_t	len;

	p_buf = buf;
	len = 0;
	while (*p_buf != EOF || *p_buf != '\n' || len <= BUFFER_SIZE)
	{
		len++;
		p_buf++;
	}
	return (len);
}
*/

static char	*get_word(size_t b_count)
{
	char 	*p_buf;
	size_t	len;
	char 	*res;

	len = 0;
	p_buf = buf;
	while (*p_buf != '\n' || len <= BUFFER_SIZE)
	{
		len++;
		p_buf++;
	}
	res = ft_substr(buf, 0, len);
	return (res);
}

int get_next_line(int fd, char **line)
{
	int res;
	if (fd < 0)
		return (-1);
	res = read(fd, &buf, BUFFER_SIZE);
	if (res == -1)
		return (-1);
	//buf[res] = '\0';
	//*line = ft_substr(buf, 0, BUFFER_SIZE);
	*line = get_word(res);
	res = res < 0 ? -1 : !!res;
	return (res);
}
