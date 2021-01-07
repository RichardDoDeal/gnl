/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishat <rishat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:38:18 by mamahali          #+#    #+#             */
/*   Updated: 2021/01/03 20:16:59 by rishat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*g_buf;

static int			save_line(char **line)
{
	size_t		len;
	char		*temp;

	len = 0;
	while (g_buf[len] != '\n' && g_buf[len])
		len++;
	if (!(*line = ft_substr(g_buf, 0, len)))
		return (-1);
	temp = g_buf;
	if (!(g_buf = ft_substr(g_buf, len + 1, ft_strlen(g_buf) - len)))
		return (-1);
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

static int				exit_with_free_error(char *buf_to_free)
{
	free(buf_to_free);
	return (-1);
}

static int			get_line(char **line, int fd, int *flag)
{
	char			*temp_buf;
	long long		res;

	if (!(temp_buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if ((*flag = search_line(g_buf)))
	{
		free(temp_buf);
		return (*flag = save_line(line));
	}
	while (!(*flag) && (res = read(fd, temp_buf, BUFFER_SIZE)))
	{
		if (res < 0)
			return (exit_with_free_error(temp_buf));
		temp_buf[res] = '\0';
		if (!(g_buf = ft_strjoin_free_first(g_buf, temp_buf)))
			return (exit_with_free_error(temp_buf));
		*flag = search_line(g_buf);
	}
	free(temp_buf);
	if ((*flag = save_line(line)) == -1)
		return (-1);
	return (res == 0 ? 0 : !!res);
}

int					get_next_line(int fd, char **line)
{
	int	res;
	int	flag;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!g_buf)
	{
		if (!(g_buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (-1);
		*g_buf = '\0';
	}
	res = get_line(line, fd, &flag);
	if ((res == 0 || res == -1) && g_buf)
	{
		free(g_buf);
		g_buf = NULL;
	}
	return (res);
}
