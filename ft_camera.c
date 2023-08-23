/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:12:48 by kfortin           #+#    #+#             */
/*   Updated: 2023/08/22 16:41:52 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"

void	ft_set_up_camera(t_mss *mss)
{
    int i;

    i = 0;
    mss->cam = ft_calloc(sizeof(t_cam), 1);
    mss->cam->coor_position[0] = -50.0;
    mss->cam->coor_position[1] = 0.0;
    mss->cam->coor_position[2] = 20.0;
    
    mss->cam->up[0] = 0.0;
    mss->cam->up[1] = 0.0;
    mss->cam->up[2] = 1.0;
    
    mss->cam->fov = 70;
    mss->cam->aspect_ratio = 0.0;
    mss->cam->focal_length = 1.0;
    
    // Calcul de l'aspect ratio
    mss->cam->aspect_ratio = (double)WINDOW_WIDTH / WINDOW_HEIGHT;

    while (i < 3)
    {
        mss->cam->coor_look[i] = mss->cam->coor_position[i] + mss->cam->up[i];
        i++;
    }
    i = 0;
    while (i < 3)
    {
        mss->cam->view_direction_up[i] = mss->cam->coor_look[i] - mss->cam->coor_position[i];
        i++;
    }
    // Calcul du vecteur right (cross product)
    mss->cam->right[0] = mss->cam->view_direction_up[1] * mss->cam->up[2] - mss->cam->view_direction_up[2] * mss->cam->up[1];
    mss->cam->right[1] = mss->cam->view_direction_up[2] * mss->cam->up[0] - mss->cam->view_direction_up[0] * mss->cam->up[2];
    mss->cam->right[2] = mss->cam->view_direction_up[0] * mss->cam->up[1] - mss->cam->view_direction_up[1] * mss->cam->up[0];
    // Calcul de la norme du vecteur de direction right
    mss->cam->view_direction_norm_right = sqrt(pow(mss->cam->right[0], 2) + pow(mss->cam->right[1], 2) + pow(mss->cam->right[2], 2));
    // Normalisation du vecteur de direction right
    i = 0;
    while (i < 3)
    {
        mss->cam->view_direction_right[i] /= mss->cam->view_direction_norm_right;
        i++;
    }
    // Calcul de la norme du vecteur de direction up
    mss->cam->view_direction_norm_up = sqrt(pow(mss->cam->view_direction_up[0], 2) + pow(mss->cam->view_direction_up[1], 2) + pow(mss->cam->view_direction_up[2], 2));
    // Normalisation du vecteur de direction up
    i = 0;
    while (i < 3)
    {
        mss->cam->view_direction_up[i] /= mss->cam->view_direction_norm_up;
        i++;
    }
    // Calcul de la moitié de la largeur de l'écran à une distance focale donnée
    mss->cam->half_width = mss->cam->focal_length * tan(0.5 * mss->cam->fov * M_PI / 180.0);
    mss->cam->half_height = mss->cam->half_width / mss->cam->aspect_ratio;
}

void    ft_affichage_plan_camera(t_mss *mss)
{
    double pixel_x;
    double pixel_y;
    int x;
    int y;

    (void)mss;
    y = 0;
    while (y < WINDOW_HEIGHT)
    {
        x = 0;
        while (x < WINDOW_WIDTH)
        {
            // Calcul des coordonnées du pixel sur le plan de la caméra
            pixel_x = (x + 0.5) / WINDOW_WIDTH - 0.5;
            pixel_y = -(y + 0.5) / WINDOW_HEIGHT + 0.5;
            // Calcul de la direction du rayon pour chaque point d'un object
            x++;
        }
        y++;
    }
}