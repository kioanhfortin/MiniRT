/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:31:46 by kfortin           #+#    #+#             */
/*   Updated: 2023/08/15 17:03:48 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_strjoin_2(char *s1, char *s2);
void	*ft_memset_2(void *b, int c, size_t len);
char	*ft_strdup_2(char *src, int end, int flag);
char	*ft_strdup_n(char *src, int end);
int		ft_strchr_2(char *stash);
size_t	ft_strlen_2(char *s);
void	*ft_calloc_2(size_t count, size_t size);
int		ft_last_line(char **stash, char **res, int size_read);
char	*ft_stock_line(char **stash, char **res, int end);
#endif