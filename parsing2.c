/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:36:40 by fboulang          #+#    #+#             */
/*   Updated: 2023/08/21 13:36:41 by fboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"

t_pl	*ft_fetch_plan(char *str)
{
	char	*inc;
	t_pl	*plan;

	plan = ft_calloc (1, sizeof(t_pl));
	inc = str;
	inc += 2;
	while (*inc != '\0' && *inc == ' ')
		inc++;
	inc = acquire_data(inc, plan->po);
	while (*inc != '\0' && *inc == ' ')
		inc++;
	inc = acquire_data(inc, plan->vec);
	while (*inc != '\0' && *inc == ' ')
		inc++;
	inc = acquire_data(inc, plan->rgb);
	return (plan);
}

t_sp	*ft_fetch_sphere(char *str)
{
	t_sp	*sphere;
	char	*inc;

	inc = str;
	sphere = ft_calloc(1, sizeof(t_sp));
	inc += 2;
	while (*inc != '\0' && *inc == ' ')
		inc++;
	inc = acquire_data(inc, sphere->spo);
	while (*inc != '\0' && *inc == ' ')
		inc++;
	sphere->diam = ft_atoi(inc);
	while (*inc != '\0' && *inc != ' ')
		inc++;
	while (*inc != '\0' && *inc == ' ')
		inc++;
	inc = acquire_data(inc, sphere->rgb);
	return (sphere);
}

t_cy	*ft_fetch_cylinder(char *str)
{
	t_cy	*cylinder;
	char	*inc;

	inc = str;
	cylinder = ft_calloc(1, sizeof(t_cy));
	inc += 2;
	while (*inc != '\0' && *inc == ' ')
		inc++;
	inc = acquire_data(inc, cylinder->co);
	while (*inc != '\0' && *inc == ' ')
		inc++;
	inc = acquire_data(inc, cylinder->vec);
	while (*inc != '\0' && *inc == ' ')
		inc++;
	cylinder->diam = ft_atoi(inc);
	while (*inc != '\0' && *inc != ' ')
		inc++;
	while (*inc != '\0' && *inc == ' ')
		inc++;
	cylinder->height = ft_atoi(inc);
	while (*inc != '\0' && *inc != ' ')
		inc++;
	while (*inc != '\0' && *inc == ' ')
		inc++;
	inc = acquire_data(inc, cylinder->rgb);
	return (cylinder);
}

char	*acquire_data(char *inc, int nums[3])
{
	int	i;

	i = 0;
	while (*inc != '\0' && *inc != ' ')
	{
		while (i < 3)
		{
			nums[i] = ft_atoi(inc);
			while (*inc != ',' && *inc != ' ')
				inc++;
			if (*inc == ',')
				inc++;
			i++;
		}
	}
	return (inc);
}

void	acquire_nums(t_mss *mss, t_list *file)
{
	t_list	*help;
	char	*temp;

	help = file;
	temp = (char *)help->str;
	mss->plnum = 0;
	mss->cylnum = 0;
	mss->spnum = 0;
	while (temp != NULL)
	{
		if (*temp == 'p')
			mss->plnum++;
		else if (*temp == 'c')
			mss->cylnum++;
		else if (*temp == 's')
			mss->spnum++;
		help = (struct s_list *)help->next;
		temp = (char *)help->str;
	}
	mss->tac = ft_calloc(1 + mss->plnum, sizeof(t_pl *));
	mss->circ = ft_calloc(1 + mss->spnum, sizeof(t_sp *));
	mss->cyl = ft_calloc(1 + mss->cylnum, sizeof(t_cy *));
}
