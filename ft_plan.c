/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plan.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 14:19:42 by kfortin           #+#    #+#             */
/*   Updated: 2023/08/24 09:51:46 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"

void    ft_plan_drawing(t_mss *mss, int i)
{
    int x;
    int y;
    int z;
    double a = mss->tac[i]->po[0];
    double b = mss->tac[i]->po[1];
    double c = mss->tac[i]->po[2];
    double d = mss->tac[i]->vec[0];
    // double new_x;
    // double new_y;
    // int rad;
    
    y = 0;
    x = 0;
    // rad = ft_deg_rad(0);
    while (y < WINDOW_HEIGHT)
    {
        x = 0;
        while (x < WINDOW_WIDTH)
        {
            z = ((-a * x - b * y - d) / c);
            // new_x = x *cos(rad) - y *cos(rad);
            // new_y = x *sin(rad) + y *sin(rad);
            if (a * x + b * y + d == -c * z)
            {
                if (ft_is_out_of_range(x, y) == 1)
                    break;
                mlx_put_pixel(mss->img, x, y, get_rgba(mss->tac[i]->rgb[0], mss->tac[i]->rgb[1], mss->tac[i]->rgb[2], 100));
            }
            x++;
        }
        y++;
    }
}

int ft_is_out_of_range(int x, int y)
{
    if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT)
        return (1);
    return (0);
}

double	ft_deg_rad(int deg)
{
	double	rad;

	rad = deg * M_PI / 180.0;
	return (rad);
}


// void    ft_apply_trans(t_mss *mss, int x, int y, int z)
// {
//     float new_x;
//     float new_y;
    
//     main->mat_coor[mod].x1 = x + cos(main->mat.rad) * main->mat.mat[y][x] - cos(main->mat.rad) * y;
//     new_x = mss->modif_mat[0][0] * x + mss->modif_mat[0][1] * y + mss->modif_mat[0][2] * z + mss->modif_mat[0][3];
//     new_y = mss->modif_mat[1][0] * x + mss->modif_mat[1][1] * y + mss->modif_mat[1][2] * z + mss->modif_mat[1][3];
// }

// void    ft_plan_drawing(t_mss *mss)
// {
//     double a;
//     double b;
//     double c;
//     double d;

//     a = Nor
// }