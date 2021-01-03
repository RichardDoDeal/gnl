
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

t_file	*find_file(int search_fd, t_file *file_now)
{
	t_file	*temp;

	while (file_now->prev)
		file_now = file_now->prev;
	while (file_now->fd != search_fd)
	{
		if (file_now->next == NULL)
		{
			temp = file_now;
			if (!(file_now = (t_file *)malloc(sizeof(t_file))))
				return (NULL);
			*file_now = (t_file){.fd = search_fd, .buf = NULL, .next = NULL, .prev = temp};
			temp->next = file_now;
			return (file_now);
		}
		file_now = file_now->next;
	}
	return (file_now);
}

void	lst_edit(t_file	**file, int mode)
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
	}
	if (mode == 1 && *file)
	{
		if ((*file)->prev)
			(*file)->prev->next = (*file)->next;
		if ((*file)->next)
			(*file)->next->prev = (*file)->prev;
		temp = ((*file)->prev) ? (*file)->prev : (*file)->next;
		free((*file)->buf);
		free(*file);
		*file = temp;
	}
}