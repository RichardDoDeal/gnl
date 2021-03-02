/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 15:27:02 by mamahali          #+#    #+#             */
/*   Updated: 2021/01/07 15:27:04 by mamahali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	save_line(char **line, char **buf)
{
	size_t		len;
	char		*temp;

	len = 0;
	while ((*buf)[len] != '\n' && (*buf)[len])
		len++;
	*line = ft_substr(*buf, 0, len);
	if (!(*line))
		return (-1);
	temp = *buf;
	if (!((*buf) = ft_substr(*buf, len + 1, ft_strlen(*buf) - len)))
	{
		free(temp);
		return (-1);
	}
	free(temp);
	return (1);
}

int	search_line(char *buffer)
{
	while (*buffer)
	{
		if (*buffer == '\n')
			return (1);
		buffer++;
	}
	return (0);
}

int	end_func(int *flag, int res)
{
	if (*flag == -1)
		return (-1);
	res = !!res;
	return (res);
}

static int	get_line(char **line, int fd, int *flag, char **g_buf)
{
	char			*temp_buf;
	long long		res;

	temp_buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp_buf)
		return (-1);
	*flag = search_line(*g_buf);
	if (*flag)
	{
		free(temp_buf);
		return (*flag = save_line(line, g_buf));
	}
	if (!(*flag))
		res = read(fd, temp_buf, BUFFER_SIZE);
	while (!(*flag) && res)
	{
		if (func(res, flag, g_buf, temp_buf) == -1)
			return (-1);
		if (!(*flag))
			res = read(fd, temp_buf, BUFFER_SIZE);
	}
	free(temp_buf);
	*flag = save_line(line, g_buf);
	res = end_func(flag, res);
	return (res);
}

int	get_next_line(int fd, char **line)
{
	int			res;
	int			flag;
	static char	*g_buf;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!g_buf)
	{
		g_buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!g_buf)
			return (-1);
		*g_buf = '\0';
	}
	res = get_line(line, fd, &flag, &g_buf);
	if ((res == 0 || res == -1) && g_buf)
	{
		free(g_buf);
		g_buf = NULL;
	}
	return (res);
}
