/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 15:09:30 by mamahali          #+#    #+#             */
/*   Updated: 2021/01/07 15:09:32 by mamahali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t count;

	count = 0;
	while (*str != '\0')
	{
		str++;
		count++;
	}
	return (count);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	char	*iter;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen((char *)s);
	if (start > s_len)
	{
		res = malloc(1);
		*res = '\0';
		return (res);
	}
	s_len = len >= s_len - start ? s_len - start + 1 : len + 1;
	res = malloc(s_len * sizeof(char));
	if (!res)
		return (NULL);
	iter = res;
	while (len-- > 0 && *(s + start))
		*iter++ = *(s + start++);
	*iter = '\0';
	return (res);
}

char	*ft_strjoin_free_first(char *s1, char *s2)
{
	char	*res;
	size_t	len;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = 0;
	len_s2 = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	if (!(res = malloc(len * sizeof(char))))
		return (NULL);
	while (s1[len_s1])
	{
		res[len_s1] = s1[len_s1];
		len_s1++;
	}
	while (s2[len_s2])
	{
		res[len_s2 + len_s1] = s2[len_s2];
		len_s2++;
	}
	res[len_s2 + len_s1] = '\0';
	free(s1);
	return (res);
}

t_file	*find_file(int s_fd, t_file *file)
{
	t_file	*t;

	while (file->prev)
		file = file->prev;
	while (file->fd != s_fd)
	{
		if (file->next == NULL)
		{
			t = file;
			if (!(file = (t_file *)malloc(sizeof(t_file))))
				return (NULL);
			*file = (t_file){.fd = s_fd, .buf = NULL, .next = NULL, .prev = t};
			t->next = file;
			return (file);
		}
		file = file->next;
	}
	return (file);
}

void	lst_edit(t_file **file, int mode)
{
	t_file			*temp;

	if (!file || !*file)
		return ;
	if (mode == 0 && *file)
	{
		while ((*file)->prev != NULL)
			*file = (*file)->prev;
		while (*file)
		{
			temp = (*file)->next;
			free((*file)->buf);
			free(*file);
			*file = temp;
		}
		return ;
	}
	if ((*file)->prev)
		(*file)->prev->next = (*file)->next;
	if ((*file)->next)
		(*file)->next->prev = (*file)->prev;
	temp = ((*file)->prev) ? (*file)->prev : (*file)->next;
	free((*file)->buf);
	free(*file);
	*file = temp;
}
