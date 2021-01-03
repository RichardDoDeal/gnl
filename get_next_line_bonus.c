/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishat <rishat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:38:18 by mamahali          #+#    #+#             */
/*   Updated: 2021/01/03 20:18:26 by rishat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_file	*g_file;

static int	save_line(char **line, char **buf)
{
	size_t		len;
	char		*temp;

	len = 0;
	while ((*buf)[len] != '\n' && (*buf)[len])
		len++;
	if (!(*line = ft_substr(*buf, 0, len)))
		return (-1);
	temp = *buf;
	if (!(*buf = ft_substr(*buf, len + 1, ft_strlen(*buf) - len)))
		return (-1);
	free(temp);
	return (1);
}

static int	search_line(char **buffer)
{
	char	*temp;

	if (!*buffer)
	{
		if (!(*buffer = malloc(sizeof(char))))
			return (-1);
		**buffer = '\0';
	}
	temp = *buffer;
	while (*temp)
	{
		if (*temp == '\n')
			return (1);
		temp++;
	}
	return (0);
}

static int	get_line(char **line, t_file *file_in)
{
	char			*temp_buf;
	long long		res;
	int				flag;

	res = -2;
	if (!(temp_buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	flag = search_line(&(file_in->buf));
	while (flag == 0 && (res = read(file_in->fd, temp_buf, BUFFER_SIZE)))
	{
		if (res < 0)
		{
			free(temp_buf);
			return (-1);
		}
		temp_buf[res] = '\0';
		file_in->buf = ft_strjoin_free_first(file_in->buf, temp_buf);
		flag = search_line(&(file_in->buf));
	}
	free(temp_buf);
	if (flag != -1)
		flag = save_line(line, &(file_in->buf));
	if (res == 0)
		return (0);
	return (flag != -1 ? 1 : -1);
}

int			get_next_line(int fd, char **line)
{
	int		res;
	t_file	*file_in;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!g_file)
	{
		if (!(g_file = malloc(sizeof(t_file))))
			return (-1);
		*g_file = (t_file){.fd = fd, .buf = NULL, .next = NULL, .prev = NULL};
	}
	file_in = find_file(fd, g_file);
	res = get_line(line, file_in);
	if (res == -1)
		lst_edit(&g_file, 0);
	if (res == 0)
	{
		lst_edit(&file_in, 1);
		g_file = file_in;
	}
	return (res);
}
