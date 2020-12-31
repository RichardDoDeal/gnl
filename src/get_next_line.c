/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishat <rishat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:38:18 by mamahali          #+#    #+#             */
/*   Updated: 2020/12/31 13:54:46 by rishat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*buf;

int			save_lines(char **line)
{
	size_t		len;
	char		*temp;

	len = 0;
	while (buf[len] != '\n' && buf[len])
		len++;
	if (!(*line = ft_substr(buf, 0, len)))
		return (-1);
	temp = buf;
	if (!(buf = ft_substr(buf, len + 1, ft_strlen(buf) - len)))
		return (-1);
	free(temp);
	return (1);
}

int			search_line(char *buffer)
{
	while (*buffer)
	{
		if (*buffer == '\n')
			return (1);
		buffer++;
	}
	return (0);
}

static int get_line(char **line, int fd)
{
	char			*temp_buf;
	long long		res;
	int				flag;

	if (!(temp_buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	flag = search_line(buf);
	while (!flag && (res = read(fd, temp_buf, BUFFER_SIZE)))
	{
		if (res < 0)
		{
			free(temp_buf);
			return (-1);
		}
		temp_buf[res] = '\0';
		buf = ft_strjoin_free_first(buf, temp_buf);
		flag = search_line(buf);
	}
	free(temp_buf);
	flag = save_lines(line);
	if (flag == -1)
		return (-1);
	return (res == 0 ? res : !!res);
}

int get_next_line(int fd, char **line)
{
	int res;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);	
	if(!buf)
		if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (-1);
	res = get_line(line, fd);
	if (res == 0 || res == -1)
		free(buf);
	return (res);
}
