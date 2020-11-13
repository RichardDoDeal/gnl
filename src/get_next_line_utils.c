
#include "get_next_line.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *dest;
	char *source;

	if (dst == NULL && src == NULL && len > 0)
		return (NULL);
	dest = (char *)dst;
	source = (char *)src;
	if (dest > source)
	{
		dest += len - 1;
		source += len - 1;
		while (len--)
			*dest-- = *source--;
	}
	else
		while (len--)
			*dest++ = *source++;
	return (dst);
}

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char *dest;
	char *source;
	char sb;

	if ((dst == NULL && src == NULL) || n == 0)
		return (NULL);
	sb = (char)c;
	dest = (char *)dst;
	source = (char *)src;
	while (1)
	{
		*dest = *source;
		if (*dest == sb)
			return (dest + 1);
		dest++;
		source++;
		n--;
		if (n == 0)
			break ;
	}
	return (NULL);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *source;
	char *dest;

	if (dst == NULL && src == NULL)
		return (dst);
	source = (char *)src;
	dest = dst;
	while (n > 0)
	{
		*dest = *source;
		source++;
		dest++;
		n--;
	}
	return (dst);
}

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
