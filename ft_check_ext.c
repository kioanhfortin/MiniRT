/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ext.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:50:11 by kfortin           #+#    #+#             */
/*   Updated: 2023/08/18 12:50:55 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"

void    ft_write_error(void)
{
    ft_putstr_fd("error file\n", 2);
    exit(0);
}

int ft_tchek_file_name(char *str)
{
    int i;
    char *s1;

    i = 0;
    s1 = NULL;
    while (str[i])
    {
        if (str[i] == '.')
        {
            i = ft_check_point(i, str);
            s1 = ft_copy_ext(str, i);
            if (ft_strcmp(s1, ".rt") != 0)
                ft_write_error();
        }
        i++;
    }
    free(s1);
    return (1);
}

int ft_check_point(int i, char *str)
{
    int j;

    j = i;
    while (str[j])
    {
        if (str[j] == '.')
            i = j;
        j++;
    }
    return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

char *ft_copy_ext(char *str, int i)
{
    char *s1;
    int k;
    int j;

    k = i;
    j = 0; 
    s1 = NULL;
    while (str[k++])
        j++;
    s1 = ft_calloc(j + 1, sizeof(char));
    if (!s1)
        return (NULL);
    k = i;
    j = 0;
    while (str[k])
        s1[j++] = str[k++];
    return (s1);
}
