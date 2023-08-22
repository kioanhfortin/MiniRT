/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_circle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:07:27 by kfortin           #+#    #+#             */
/*   Updated: 2023/08/21 17:28:00 by kfortin          ###   ########.fr       */
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
                    mlx_put_pixel(mss->img, x + 100, y + 100, get_rgba(88, 24, 69, 255));
                z++;
            }
            y++;
        }
        x++;
    }
}