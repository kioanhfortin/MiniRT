/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:02:30 by kfortin           #+#    #+#             */
/*   Updated: 2023/08/15 17:06:13 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_stock_line(char **stash, char **res, int end)
{
	int		len;
	char	*new_stash;

	*res = ft_strdup_2(*stash, end, 1);
	len = ft_strlen_2(*stash + end + 1);
	if (!len)
	{
		free(*stash);
		*stash = NULL;
		return (*res);
	}
	new_stash = ft_strdup_2(*stash + end + 1, end, 2);
	free(*stash);
	*stash = new_stash;
	return (*res);
}

char	*ft_strdup_2(char *src, int end, int flag)
{
	char	*dup;
	int		i;

	i = -1;
	if (flag == 1)
	{
		dup = malloc(sizeof(char) * end + 1);
		if (dup == 0)
			return (NULL);
		while (src[++i] && i <= end)
			dup[i] = src[i];
	}
	if (flag == 2)
	{
		dup = malloc(sizeof(char) * ft_strlen_2(src) + 1);
		if (dup == 0)
			return (NULL);
		while (src[++i])
			dup[i] = src[i];
	}
	dup[i] = '\0';
	return (dup);
}

int	ft_last_line(char **stash, char **res, int size_read)
{
	int	i;

	i = 0;
	if (size_read < 0)
		return (-1);
	if (*stash)
		i = ft_strchr_2(*stash);
	if (*stash && (i > -1))
		ft_stock_line(stash, res, i);
	if (*stash)
	{
		*res = *stash;
		*stash = NULL;
		return (0);
	}
	*res = NULL;
	return (0);
}

void	ft_norminette(char **buf, char **stash)
{
	if (!(*stash))
		*stash = ft_strdup_2(*buf, BUFFER_SIZE, 2);
	else
		*stash = ft_strjoin_2(*stash, *buf);
	free(*buf);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*stash;
	char		*res;
	int			j;

	res = NULL;
	j = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buf = ft_calloc_2(sizeof(char), BUFFER_SIZE + 1);
	while (read(fd, buf, BUFFER_SIZE) > 0 || ft_strchr_2(stash) != -1)
	{
		ft_norminette(&buf, &stash);
		j = ft_strchr_2(stash);
		if (j > -1)
			return (ft_stock_line(&stash, &res, j));
		j = 0;
		buf = ft_calloc_2(sizeof(char), BUFFER_SIZE + 1);
	}
	free(buf);
	if ((ft_last_line(&stash, &res, j)) < 0)
		return (NULL);
	return (res);
}