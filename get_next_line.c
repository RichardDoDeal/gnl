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

static int			save_line(char **line, char **buf)
{
	size_t		len;
	char		*temp;

	len = 0;
	while ((*buf)[len] != '\n' && (*buf)[len])
		len++;
	if (!(*line = ft_substr(*buf, 0, len)))
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

static int			search_line(char *buffer)
{
	while (*buffer)
	{
		if (*buffer == '\n')
			return (1);
		buffer++;
	}
	return (0);
}

static int			exit_with_free_error(char *buf_to_free)
{
	free(buf_to_free);
	return (-1);
}

static int			get_line(char **line, int fd, int *flag, char **g_buf)
{
	char			*temp_buf;
	long long		res;

	if (!(temp_buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if ((*flag = search_line(*g_buf)))
	{
		free(temp_buf);
		return (*flag = save_line(line, g_buf));
	}
	while (!(*flag) && (res = read(fd, temp_buf, BUFFER_SIZE)))
	{
		if (res < 0)
			return (exit_with_free_error(temp_buf));
		temp_buf[res] = '\0';
		if (!(*g_buf = ft_strjoin_free_first(*g_buf, temp_buf)))
			return (exit_with_free_error(temp_buf));
		*flag = search_line(*g_buf);
	}
	free(temp_buf);
	if ((*flag = save_line(line, g_buf)) == -1)
		return (-1);
	return (res == 0 ? 0 : !!res);
}

int					get_next_line(int fd, char **line)
{
	int			res;
	int			flag;
	static char	*g_buf;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!g_buf)
	{
		if (!(g_buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
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
