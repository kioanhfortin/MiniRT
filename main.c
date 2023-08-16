/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:06:17 by kfortin           #+#    #+#             */
/*   Updated: 2023/08/15 17:32:48 by kfortin          ###   ########.fr       */
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
    fd = open(argv, O_RDONLY);
    file = ft_lstnew(get_next_line(fd));
    node = file;
    str = file->str;
    if (file->str == NULL)
        printf("error\n");
    i++;
    while (str != NULL)
    {
        str = get_next_line(fd);
        ft_lstadd_back(&node, ft_lstnew(str));
		node = (struct s_list *)node->next;
		i++;
    }
    // ft_fetch_info(file);
    ft_print_list(file);
}

int main(int argc, char **argv)
{
    t_mss   *mss;
    (void)argv;
    
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
        mlx_close_hook(mss->mlx, on_destroy, mss->mlx);
        mlx_key_hook(mss->mlx, print_key, mss->mlx);
        mlx_put_pixel(mss->img, 600, 300, get_rgba(199, 0, 57, 255));
        mlx_image_to_window(mss->mlx, mss->img, 0, 0);
        mlx_loop(mss->mlx);
    }
    else
        printf("error\n");
    return (0);
}