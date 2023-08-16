/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:53:34 by fboulang          #+#    #+#             */
/*   Updated: 2023/08/15 14:48:03 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"

/*
keyhooks nécessaire :
croix rouge = exit;
escape = exit;
on destroy = exit;
souris + roue de souris = déplacement dans la fenêtre (maybe);
arrow keys = déplacement dans la fenêtre.
*/
void on_destroy(void *param)
{
	mlx_t	*temp;
	temp = (mlx_t *)param;
	mlx_close_window(temp);
	mlx_terminate(temp);
	exit (EXIT_SUCCESS);
}

void	print_key(mlx_key_data_t keydata, void *param)
{
	mlx_t	*temp;

	temp = (mlx_t *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(temp);
		mlx_terminate(temp);
		exit(EXIT_SUCCESS);
	}
}
