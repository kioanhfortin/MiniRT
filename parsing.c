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

void	ft_fetch_info(t_list *file, t_mss *mss)
{
	char	*temp;
	t_list	*help;

	temp = (char *)file->str;
	help = file;
	acquire_nums(mss, file);
	mss->plnum = 0;
	mss->spnum = 0;
	mss->cylnum = 0;
	while (temp != NULL)
	{
		if (*temp == 'A')
			ft_fetch_alight(temp, mss);
		else if (*temp == 'C')
			ft_fetch_cam(temp, mss);
		else if (*temp == 'L')
			ft_fetch_light(temp, mss);
		else if (*temp == 'p')
			mss->tac[mss->plnum++] = ft_fetch_plan(temp);
		else if (*temp == 's')
			mss->circ[mss->spnum++] = ft_fetch_sphere(temp);
		else if (*temp == 'c')
			mss->cyl[mss->cylnum++] = ft_fetch_cylinder(temp);
		help = (struct s_list *)help->next;
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
	while (*inc != '\0' && *inc == ' ')
		inc++;
	inc = acquire_data(inc, mss->amb.rgb);
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
	inc = acquire_data(inc, mss->vis.pov);
	while (*inc != '\0' && *inc == ' ')
		inc++;
	inc = acquire_data(inc, mss->vis.vec);
	while (*inc != '\0' && *inc == ' ')
		inc++;
	mss->vis.fov = ft_atoi(inc);
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
	inc = acquire_data(inc, mss->sun.ol);
	while (*inc != '\0' && *inc == ' ')
		inc++;
	mss->sun.ratio = ft_atoi(inc);
	while (*inc != '\0' && *inc != ' ')
		inc++;
	while (*inc != '\0' && *inc == ' ')
		inc++;
	inc = acquire_data(inc, mss->sun.rgb);
}
