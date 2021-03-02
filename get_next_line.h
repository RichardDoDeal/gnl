/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 15:08:33 by mamahali          #+#    #+#             */
/*   Updated: 2021/01/07 15:08:34 by mamahali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int		get_next_line(int fd, char **line);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin_free_first(char *s1, char *s2);
size_t	ft_strlen(const char *str);
int		func(long long res, int *flag, char **g_buf, char *temp_buf);
int		exit_with_free_error(char *buf_to_free);
int		search_line(char *buffer);
#endif
