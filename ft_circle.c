/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_circle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:07:27 by kfortin           #+#    #+#             */
/*   Updated: 2023/08/23 14:15:14 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"

// void    ft_circle_drawing(t_mss *mss)
// {
//     int ray;
//     double rad;
//     double center_x;
//     double center_y;
//     double d;
//     double x;
//     double y;
//     double new_x;
//     double new_y;

//     ray = 50;
//     center_x = 400;
//     center_y = 400;
//     y = -ray;
//     rad = ft_deg_rad(0);
//     while (y < ray)
//     {
//         x = -ray;
//         while (x < ray)
//         {
//             new_x = x * cos(rad) - y * cos(rad) + center_x;
//             new_y = y  * sin(rad) + y * sin(rad) + center_y;
//             d = sqrt((new_x - center_x) * (new_x - center_x) + (new_y - center_y) * (new_y - center_y));
//             if (d <= ray)
//                 mlx_put_pixel(mss->img, new_x, new_y, get_rgba(199, 0, 57, 255));
//             x++;
//         }
//         y++;
//     }
// }

// void    ft_circle_drawing(t_mss *mss)
// {
//     double r = 50;
//     double center_x = 400;
//     double center_y = 400;
//     double x_c = center_x;
//     double y_c = center_y;
//     double x = 0;
//     double y = r;
//     double d = 4 * (r - 1) -2 * r * r;

//     while (x <= y)
//     {
//         mlx_put_pixel(mss->img, x_c + x, y_c + y, get_rgba(199, 0, 57, 255));
//         mlx_put_pixel(mss->img, x_c - x, y_c + y, get_rgba(199, 0, 57, 255));
//         mlx_put_pixel(mss->img, x_c + x, y_c - y, get_rgba(199, 0, 57, 255));
//         mlx_put_pixel(mss->img, x_c - x, y_c - y, get_rgba(199, 0, 57, 255));
//         if (d < 0)
//             d = d + 4 * x + 6;
//         else
//         {
//             d = d + 4 * (x - y) + 10;
//             y--;
//         }
//         x++;
//     }
// }

void    ft_circle_drawing(t_mss *mss)
{
    double a = 100.0;
    double b = 100.0;
    double c = 100.0;
    double r = 50.0;
    double equation;
    int x;
    int y;
    int z;

    x = 0;
    while (x < 200)
    {
        y = 0;
        while (y < 200)
        {
            z = 0;
            while(z < 200)
            {
                equation = pow(x - a, 2) + pow(y - b, 2) + pow(z - c, 2);
                if (fabs(equation - pow(r, 2)) < 10.0)
                    mlx_put_pixel(mss->img, x + 200, y + 200, get_rgba(218, 247, 166, 255));
                z++;
            }
            y++;
        }
        x++;
    }
}

void    ft_circle_2_drawing(t_mss *mss)
{
    double a = 100.0;
    double b = 100.0;
    double c = 100.0;
    double r = 50.0;
    double equation;
    int x;
    int y;
    int z;

    x = (int)(a - r);
    while (x <= (int)(a + r))
    {
        y = (int)(b - r);
        while (y < (int)(b + r))
        {
            z = (int)(c - r);
            while(z < (int)(c + r))
            {
                equation = pow(x - a, 2) + pow(y - b, 2) + pow(z - c, 2);
                if (equation <= pow(r, 2))
                {
                    mlx_put_pixel(mss->img, x + 100, y + 100, get_rgba(88, 24, 69, 255));
                }
                z++;
            }
            y++;
        }
        x++;
    }
}

/*void    ft_intersection_sp(t_mss *mss, i)
{
    mss->circ[i]->spo[0]; //point centre
    mss->circ[i]->spo[1];
    mss->circ[i]->spo[2];
    //mss->vis.pov[0] (x), mss->vis.pov[1] (y), mss->vis.pov[2] (z); //point d'origine de la cam
    mss->circ[i]->diam / 2;

    mss->cam2->coor_position[0];
    mss->cam2->coor_position[1];
    mss->cam2->coor_position[2];

    mss->ray.ray_direction_x;
    mss->ray.ray_direction_y;
    mss->ray.ray_direction_z;

    //(x - Cx)² + (y - Cy)² + (z - Cz)² = R²;
    (t*(dx) - Cx)² + (t*(dy) - Cy)² + (t*(dz) - Cz)² = R²;
    pow((t* (mss->ray.ray_direction_x) - mss->circ[i]->spo[0]), 2) + pow(((t *(mss->ray.ray_direction_y) - mss->circ[i]->spo[1])), 2) + pow((t*(mss->ray.ray_direction_z) - mss->circ[i]->spo[2]), 2) = pow(mss->circ[i]->diam / 2, 2);
    
    //calculer t a partir de 2 points (camera object);
    t² * (dx)² + t² * (dy)² + t² * (dz)² - 2t(dxCx + dyCy + dz*Cz) + Cx² + Cy² + Cz² - R² = 0;
    //if (!= 0) pas toucher object sp[i];
}*/

double dot(t_ray a, t_ray b)
{
    return (a.ray_direction_x * b.ray_direction_x + a.ray_direction_y * b.ray_direction_y + a.ray_direction_z * b.ray_direction_z);
}

int    ft_intersection_sp(t_mss *mss, int i, double *t)
{
    /*mss->circ[i]->spo[0]; //point centre
    mss->circ[i]->spo[1];
    mss->circ[i]->spo[2];
    //mss->vis.pov[0] (x), mss->vis.pov[1] (y), mss->vis.pov[2] (z); //point d'origine de la cam
    mss->circ[i]->diam / 2;

    mss->cam2->coor_position[0];
    mss->cam2->coor_position[1];
    mss->cam2->coor_position[2];

    mss->ray.ray_direction_x;
    mss->ray.ray_direction_y;
    mss->ray.ray_direction_z;*/

    t_ray *oc;
    (void)i;
    oc = ft_calloc(sizeof(t_ray), 1);
    if(!oc)
        return (-1);
    //printf("%f\n, %d\n", mss->cam2->coor_position[0], mss->circ[i]->spo[0]);
    oc->ray_direction_x = mss->cam2->coor_position[0] - mss->circ[i]->spo[0];
   // printf("%f, %f, %f\n", oc->ray_direction_y, oc->ray_direction_x, oc->ray_direction_z);
    oc->ray_direction_y = mss->cam2->coor_position[1] - mss->circ[i]->spo[1];
    oc->ray_direction_z = mss->cam2->coor_position[2] - mss->circ[i]->spo[2];
    double a = dot(mss->ray, mss->ray); //A
    double b = 2.0 * dot(*oc, mss->ray);
    double c = dot(*oc, *oc) - ((mss->circ[i]->diam / 2) * (mss->circ[i]->diam / 2));

    double discriminant = b * b - 4.0 * a * c;

    if (discriminant > 0.0)
        printf("%f\n", discriminant);
    if (discriminant < 0.0)
    {
        return (0);
    }
    else
    {
        double t1 = (-b - sqrt(discriminant)) / (2.0 * a);
        double t2 = (-b + sqrt(discriminant)) / (2.0 * a);

        if (t1 > 0.0 || t2 > 0.0)
        {
            *t = (t1 < t2) ? t1 : t2;
            return (1); //Il y a une intersection
        }
        else
            return (0); //les intersections sont derriere le rayon
    }
    //(x - Cx)² + (y - Cy)² + (z - Cz)² = R²;
    //(t*(dx) - Cx)² + (t*(dy) - Cy)² + (t*(dz) - Cz)² = R²;
    // pow((t* (mss->ray.ray_direction_x) - mss->circ[i]->spo[0]), 2) + pow(((t *(mss->ray.ray_direction_y) - mss->circ[i]->spo[1])), 2) + pow((t*(mss->ray.ray_direction_z) - mss->circ[i]->spo[2]), 2) = pow(mss->circ[i]->diam / 2, 2);
    
    //calculer t a partir de 2 points (camera object);
    // t² * (dx)² + t² * (dy)² + t² * (dz)² - 2t(dxCx + dyCy + dz*Cz) + Cx² + Cy² + Cz² - R² = 0;
    //if (!= 0) pas toucher object sp[i];
}