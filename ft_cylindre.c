/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cylindre.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 14:20:34 by kfortin           #+#    #+#             */
/*   Updated: 2023/08/21 17:02:08 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"

// void    ft_cylinder_drawing(t_mss *mss)
// {
//     double x;
//     double y;
//     double z;
//     double new_x;
//     double new_y;
//     double ray;
//     int rad;
    
//     (void)mss;    
//     new_x = 30;
//     ray = 7.1;
//     new_y = -ray;
//     y = 0;
//     rad = ft_deg_rad(0);rad = ft_deg_rad(0);
//     while (y < 20) //de 0 à la hauteur
//     {
//         x = -ray;
//         while(x < ray) //de -ray à ray
//         {
//             new_x = x * cos(rad) - y * cos(rad);
//             new_y = x * sin(rad) - y * sin(rad);
//             z = (ray * ray - x * x);
//             if (z > 0)
//             {
//                 if (ft_is_out_of_range(new_x, new_y + new_x) == 1 || ft_is_out_of_range(new_x, new_y - new_x) == 1)
//                     break;
//                 mlx_put_pixel(mss->img, new_x, new_y + new_x, get_rgba(199, 0, 57, 255));
//                 mlx_put_pixel(mss->img, new_x, new_y - new_x, get_rgba(199, 0, 57, 255));
//             }
//             x++;
//         }
//         y++;
//     }
// }

void    ft_cylinder_drawing(t_mss *mss)
{
    double a = 100.0;
    double b = 100.0;
    double c = 100.0;
    double r = 50.0;
    double h = 150.0;
    double equation;
    int x;
    int y;
    int z;
    
    x = 0;
    while(x < 200)
    {
        y = 0;
        while(y < 200)
        {
            z = 0;
            while(z < 200)
            {
                equation = pow(x - a, 2) + pow(y - b, 2);
                if (fabs(equation - pow(r, 2)) < 10.0 && z >= c && z <= c + h)
                {
                    mlx_put_pixel(mss->img, x, y, get_rgba(255, 195, 0, 255));
                }
                z++;
            }
            y++;
        }
        x++;
    }
}