/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 15:08:21 by mamahali          #+#    #+#             */
/*   Updated: 2021/01/07 15:08:23 by mamahali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	func(long long res, int *flag, char **g_buf, char *temp_buf)
{
	if (res < 0)
		return (exit_with_free_error(temp_buf));
	temp_buf[res] = '\0';
	*g_buf = ft_strjoin_free_first(*g_buf, temp_buf);
	if (!(*g_buf))
		return (exit_with_free_error(temp_buf));
	*flag = search_line(*g_buf);
	return (0);
}

int	exit_with_free_error(char *buf_to_free)
{
	free(buf_to_free);
	return (-1);
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

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
	if (len >= s_len - start)
		s_len = s_len - start + 1;
	else
		s_len = len + 1;
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

	len_s1 = -1;
	len_s2 = 0;
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	res = malloc(len * sizeof(char));
	if (!res)
	{
		free(s1);
		return (NULL);
	}
	while (s1[++len_s1])
		res[len_s1] = s1[len_s1];
	while (s2[len_s2])
	{
		res[len_s2 + len_s1] = s2[len_s2];
		len_s2++;
	}
	res[len_s2 + len_s1] = '\0';
	free(s1);
	return (res);
}
