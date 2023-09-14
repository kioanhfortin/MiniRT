/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utilis.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:27:48 by kfortin           #+#    #+#             */
/*   Updated: 2023/08/15 17:06:19 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*strjoin;
	int		i;
	int		j;
	int		len1;
	int		len2;

	i = -1;
	j = -1;
	if (!s2)
		return (NULL);
	len1 = ft_strlen_2(s1);
	len2 = ft_strlen_2(s2);
	strjoin = ft_calloc_2(len1 + len2 + 1, sizeof(char));
	if (!strjoin)
		return (NULL);
	while (++i < len1)
		strjoin[i] = s1[i];
	if (s1)
		free(s1);
	while (++j < len2)
		strjoin[i + j] = s2[j];
	strjoin[i + j] = '\0';
	return (strjoin);
}

size_t	ft_strlen_2(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_calloc_2(size_t count, size_t size)
{
	void	*str;
	size_t	i;

	i = count * size;
	if (count == SIZE_MAX && size == SIZE_MAX)
		return (NULL);
	str = malloc(sizeof(char) * i);
	if (!str)
		return (NULL);
	ft_memset_2(str, 0, i);
	return (str);
}

void	*ft_memset_2(void *b, int c, size_t len)
{
	while (len-- > 0)
		((unsigned char *)b)[len] = (unsigned char)c;
	return (b);
}

int	ft_strchr_2(char *stash)
{
	int	i;

	i = -1;
	if (!stash)
		return (-1);
	while (stash[++i])
		if (stash[i] == '\n')
			return (i);
	return (-1);
}