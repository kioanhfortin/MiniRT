/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:12:48 by kfortin           #+#    #+#             */
/*   Updated: 2023/08/23 13:57:39 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"

void	ft_set_up_camera(t_mss *mss)
{
    int i;

    i = 0;
    mss->cam2 = ft_calloc(sizeof(t_cam2), 1);
    mss->cam2->coor_position[0] = mss->vis.pov[0];
    mss->cam2->coor_position[1] = mss->vis.pov[1];
    mss->cam2->coor_position[2] = mss->vis.pov[2];
    
    mss->cam2->up[0] = mss->vis.vec[0];
    mss->cam2->up[1] = mss->vis.vec[1];
    mss->cam2->up[2] = mss->vis.vec[2];
    
    mss->cam2->fov = mss->vis.fov;
    mss->cam2->aspect_ratio = 0.0;
    mss->cam2->focal_length = 1.0;
    
    // Calcul de l'aspect ratio
    mss->cam2->aspect_ratio = (double)WINDOW_WIDTH / WINDOW_HEIGHT;

    while (i < 3)
    {
        mss->cam2->coor_look[i] = mss->cam2->coor_position[i] + mss->cam2->up[i];
        i++;
    }
    i = 0;
    while (i < 3)
    {
        mss->cam2->view_direction_up[i] = mss->cam2->coor_look[i] - mss->cam2->coor_position[i];
        i++;
    }
    // Calcul du vecteur right (cross product)
    mss->cam2->right[0] = mss->cam2->view_direction_up[1] * mss->cam2->up[2] - mss->cam2->view_direction_up[2] * mss->cam2->up[1];
    mss->cam2->right[1] = mss->cam2->view_direction_up[2] * mss->cam2->up[0] - mss->cam2->view_direction_up[0] * mss->cam2->up[2];
    mss->cam2->right[2] = mss->cam2->view_direction_up[0] * mss->cam2->up[1] - mss->cam2->view_direction_up[1] * mss->cam2->up[0];
    // Calcul de la norme du vecteur de direction right
    mss->cam2->view_direction_norm_right = sqrt(pow(mss->cam2->right[0], 2) + pow(mss->cam2->right[1], 2) + pow(mss->cam2->right[2], 2));
    // Normalisation du vecteur de direction right
    i = 0;
    while (i < 3)
    {
        mss->cam2->view_direction_right[i] /= mss->cam2->view_direction_norm_right;
        i++;
    }
    // Calcul de la norme du vecteur de direction up
    mss->cam2->view_direction_norm_up = sqrt(pow(mss->cam2->view_direction_up[0], 2) + pow(mss->cam2->view_direction_up[1], 2) + pow(mss->cam2->view_direction_up[2], 2));
    // Normalisation du vecteur de direction up
    i = 0;
    while (i < 3)
    {
        mss->cam2->view_direction_up[i] /= mss->cam2->view_direction_norm_up;
        i++;
    }
    // Calcul de la moitié de la largeur de l'écran à une distance focale donnée
    mss->cam2->half_width = mss->cam2->focal_length * tan(0.5 * mss->cam2->fov * M_PI / 180.0);
    mss->cam2->half_height = mss->cam2->half_width / mss->cam2->aspect_ratio;
}

void    ft_affichage_plan_camera(t_mss *mss)
{
    int     x;
    int     y;
    //double  t;

    y = 0;
    while (y < WINDOW_HEIGHT)
    {
        x = 0;
        while (x < WINDOW_WIDTH)
        {
            // Calcul des coordonnées du pixel sur le plan de la caméra
            mss->pixs.pixel_x = (x + 0.5) / WINDOW_WIDTH - 0.5;
            mss->pixs.pixel_y = -(y + 0.5) / WINDOW_HEIGHT + 0.5;
            // Calcul de la direction du rayon pour chaque point d'un object
            // r(ray) = r(0) + vt 
            //ft_ray_trace(mss);
            
            //if (ft_intersection_sp(mss, 1, &t) == 1)
                //mlx_put_pixel(mss->img, 600, 300, get_rgba(199, 0, 57, 255)); 
            x++;
        }
        y++;
    }
}

void    ft_ray_trace(t_mss *mss)
{
    double normalized_x;
    double normalized_y;

    normalized_x = (2.0 * mss->pixs.pixel_x - 1.0) * mss->cam2->aspect_ratio * tan(mss->cam2->fov * 0.5);
    normalized_y = 1.0 - 2.0 * mss->pixs.pixel_y * tan(mss->cam2->fov * 0.5);

    mss->ray.ray_direction_x = normalized_x;
    mss->ray.ray_direction_y = normalized_y;
    mss->ray.ray_direction_z = -1.0;
}
