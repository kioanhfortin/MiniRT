/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:06:17 by kfortin           #+#    #+#             */
/*   Updated: 2023/08/23 13:50:08 by kfortin          ###   ########.fr       */
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
    ft_fetch_info(file, mss);
    ft_print_list(file);
}

// void    ft_init_mat(t_mss *mss)
// {
//     int i;

//     i = 2;
//     mss->modif_mat = ft_calloc(sizeof(int*), 3);
//     while (i < 2)
//     {
//         mss->modif_mat[i] = ft_calloc(sizeof(int), 4);
//         i++;
//     }
// }

void ft_fetch_form(t_mss *mss)
{
    int i;

    i = 0;
    /*while (i < mss->plnum)
    {
        ft_plan_drawing(mss, i); //a refaire probablement
        i++;
    }*/
    i = 0;
    while (i < mss->spnum)
    {
        //ft_circle_2_drawing(mss, i);
        ft_intersection_sp(mss, i);
        i++;
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
        //ft_init_mat(mss);
        mss->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "MINIRT", false);
        mss->img = mlx_new_image(mss->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
        mlx_close_hook(mss->mlx, on_destroy, mss->mlx);
        mlx_key_hook(mss->mlx, print_key, mss->mlx);
        ft_set_up_camera(mss);
        //lancer rayons
        ft_affichage_plan_camera(mss);
        //ft_plan_drawing(mss); //intersection des chaques
        //ft_plan_drawing(mss);
        //ft_circle_drawing(mss);
        //ft_cylinder_drawing(mss);
        //ft_circle_2_drawing(mss); 
        ft_fetch_form(mss);
        // mlx_put_pixel(mss->img, 600, 300, get_rgba(199, 0, 57, 255));
        mlx_image_to_window(mss->mlx, mss->img, 0, 0);
        mlx_loop(mss->mlx);
    }
    else
        printf("error\n");
    return (0);
}