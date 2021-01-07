/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishat <rishat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 20:18:49 by rishat            #+#    #+#             */
/*   Updated: 2021/01/03 20:18:53 by rishat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	if (!(res = malloc(s_len * sizeof(char))))
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
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	if (!(res = malloc(len * sizeof(char))))
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
