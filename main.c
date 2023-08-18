/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:06:17 by kfortin           #+#    #+#             */
/*   Updated: 2023/08/18 16:16:04 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"

void    ft_print_list(t_list *file)
{
    while (file)
    {
        // ft_putstr_fd(file->str, 1);
        printf("%s\n", file->str);
        file = (struct s_list *)file->next;
    }
}

void    ft_parsing(t_mss *mss, char *argv)
{
    int i;
    int fd;
    char *str;
    t_list *node;
    t_list *file;
    
    (void)mss;
    i = 0;
    file = NULL;
    ft_tchek_file_name(argv);
    fd = open(argv, O_RDONLY);
    file = ft_lstnew(get_next_line(fd));
    node = file;
    str = file->str;
    if (file->str == NULL)
        ft_write_error();
    i++;
    while (str != NULL)
    {
        str = get_next_line(fd);
        ft_lstadd_back(&node, ft_lstnew(str));
		node = (struct s_list *)node->next;
		i++;
    }
    ft_check_legit(file);
    // ft_fetch_info(file);
    ft_print_list(file);
}

void    ft_plan_drawing(t_mss *mss)
{
    // (void)mss;
    int x;
    int y;
    int z;
    double a;
    double b;
    double c;
    double d;
    
    a = 0.0;
    b = 1.0;
    c = 0.0;
    d = 0.0;
    y = 0;
    while (y < 800)
    {
        x = 0;
        while (x < 800)
        {
            z = ((-a*x - b*y - d) / c);
            if (a * x + b * y + d == -c * z)
                mlx_put_pixel(mss->img, x, y, get_rgba(199, 0, 57, 255));
            x++;
        }
        y++;
    }
}

int main(int argc, char **argv)
{
    t_mss   *mss;
    
    mss = ft_calloc(sizeof(t_mss), 1);
    if (mss == NULL)
    {
        printf("error memory allocation\n");
        return (1);
    }
    if (argc == 2)
    {
        ft_parsing(mss, argv[1]);
        mss->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "MINIRT", false);
        mss->img = mlx_new_image(mss->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
        ft_plan_drawing(mss);
        // mlx_put_pixel(mss->img, 600, 300, get_rgba(199, 0, 57, 255));
        mlx_image_to_window(mss->mlx, mss->img, 0, 0);
        mlx_loop(mss->mlx);
    }
    else
        printf("error\n");
    return (0);
}