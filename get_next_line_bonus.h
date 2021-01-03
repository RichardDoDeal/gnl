/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishat <rishat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 20:06:20 by rishat            #+#    #+#             */
/*   Updated: 2021/01/03 20:10:33 by rishat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_file
{
	int					fd;
	char				*buf;
	struct s_file		*next;
	struct s_file		*prev;
}					t_file;

int					get_next_line(int fd, char **line);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin_free_first(char *s1, char *s2);
size_t				ft_strlen(const char *str);
void				lst_edit(t_file	**file, int mode);
t_file				*find_file(int search_fd, t_file *file_now);
#endif
