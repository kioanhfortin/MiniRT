/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:35:54 by fboulang          #+#    #+#             */
/*   Updated: 2023/08/17 09:35:56 by fboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"

void ft_fetch_info(t_list *file, t_mss *mss)
{
	char	*temp;
	t_list	*help;

	temp = (char *)file->str;
	help = file;
	while (temp != NULL)
	{
		if (*temp == 'A')
			ft_fetch_alight(str, mss);
		else if (*temp == 'C')
			ft_fetch_cam(str, mss);
		else if (*temp == 'L')
			ft_fetch_light(str, mss);
		else if (*temp == 'p')
			ft_fetch_pl(str, mss->);
		else if (*temp == 's')
			ft_fetch_sp(str, mss);
		else if (*temp == 'c');
			ft_fetch_c(str, mss);
		help = file->next;
		temp = (char *)help->str;
	}
}

void	ft_fetch_alight(char *str, t_mss *mss)
{
	char	*inc;

	inc = str;
	while (*inc != '\0' && (*inc < '0' || *inc > '9'))
		inc++;
	mss->amb.ratio = ft_atoi(inc);
	while (*inc != ' ')
		inc++;
	while (*inc == ' ' && *inc != "\0")
		inc++;
	mss->amb.rgb[0] = ft_atoi(inc);
	while (*inc != ',' && *inc != '\0')
		inc++;
	if (*inc == ',')
		inc++;
	mss->amb.rgb[1] = ft_atoi(inc);
	while (*inc != ',' && *inc != '\0')
		inc++;
	if (*inc == ',')
		inc++;
	mss->amb.rgb[2] = ft_atoi(inc);
}

void	ft_fetch_cam(char *str, t_mss *mss)
{
	char	*inc;
	int		i;

	i = 0;
	inc = str;
	inc++;
	while (*inc != '\0' && *inc == ' ')
		inc++;
	while (*inc != '\0' && *inc != ' ')
	{
		while (i < 3)
		{
			mss->cam.pov[i] = ft_atoi(inc);
			while(*inc != ',' && *inc != ' ')
				inc++;
			if (*inc == ',')
				inc++;
			i++;
		}
	}
	while (*inc == ' ' && *inc != "\0")
		inc++;
	i = 0;
	while (*inc != '\0' && *inc != ' ')
	{
		while (i < 3)
		{
			mss->cam.vec[i] = ft_atoi(inc);
			while(*inc != ',' && *inc != ' ')
				inc++;
			if (*inc == ',')
				inc++;
			i++;
		}
	}
	while (*inc != '\0' && *inc == ' ')
		inc++;
	mss->cam.fov = ft_atoi(inc);
}

void	ft_fetch_light(char *str, t_mss *mss)
{
	char	*inc;
	int		i;

	i = 0;
	inc = str;
	inc++;
	while (*inc != '\0' && *inc == ' ')
		inc++;
	while (*inc != '\0' && *inc != ' ')
	{
		while (i < 3)
		{
			mss->cam.ol[i] = ft_atoi(inc);
			while(*inc != ',' && *inc != ' ')
				inc++;
			if (*inc == ',')
				inc++;
			i++;
		}
	}
	while (*inc == ' ' && *inc != "\0")
		inc++;
	while (*inc != '\0' && *inc == ' ')
		inc++;
	mss->cam.ratio = ft_atoi(inc);
	i = 0;
	while (*inc != '\0' && *inc != ' ')
	{
		while (i < 3)
		{
			mss->cam.rgb[i] = ft_atoi(inc);
			while(*inc != ',' && *inc != ' ')
				inc++;
			if (*inc == ',')
				inc++;
			i++;
		}
	}
}

void	ft_fetch_plan(char *str, t_pl *plan)
{
	char	*inc;
	int		i;

	i = 0;
	inc = str;
	inc++;
	while (*inc != '\0' && *inc == ' ')
		inc++;
	while (*inc != '\0' && *inc != ' ')
	{
		while (i < 3)
		{
			mss->cam.ol[i] = ft_atoi(inc);
			while(*inc != ',' && *inc != ' ')
				inc++;
			if (*inc == ',')
				inc++;
			i++;
		}
	}
	while (*inc == ' ' && *inc != "\0")
		inc++;
	while (*inc != '\0' && *inc == ' ')
		inc++;
	mss->cam.ratio = ft_atoi(inc);
	i = 0;
	while (*inc != '\0' && *inc != ' ')
	{
		while (i < 3)
		{
			mss->cam.rgb[i] = ft_atoi(inc);
			while(*inc != ',' && *inc != ' ')
				inc++;
			if (*inc == ',')
				inc++;
			i++;
		}
	}
}
