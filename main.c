/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:06:17 by kfortin           #+#    #+#             */
/*   Updated: 2023/08/18 15:28:24 by kfortin          ###   ########.fr       */
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

void    ft_check_legit(t_list *file)
{
    int i;
    int flag_a;
    int flag_l;
    int flag_c;
    

    i = 0;
    flag_a = 0;
    flag_l = 0;
    flag_c = 0;
    while (file)
    {
        if (file->str)
        {
            if (ft_check_only_one_per_line(file->str) == 0)
                ft_write_error_2(file);
            if (ft_which_maj(file->str, &flag_a, &flag_l, &flag_c) == 0)
                ft_write_error_3(file);
        }
        file = (struct s_list *)file->next;
    }
}

int    ft_which_maj(char *str, int *flag_a, int *flag_l, int *flag_c)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == 'A' && *flag_a == 0)
        {
            *flag_a = 1;
            return (1);
        }
        if (str[i] == 'L' && *flag_l == 0)
        {
            *flag_l = 1;
            return (1);
        }
        if (str[i] == 'C' && *flag_c == 0)
        {
            *flag_c = 1;
            return (1);
        }
        if (str[i] == 'A' && *flag_a == 1)
            return(0);
        if (str[i] == 'L' && *flag_l == 1)
            return(0);
        if (str[i] == 'C' && *flag_c == 1)
            return(0);
        i++;
    }
    return (1);
}

void    ft_write_error_2(t_list *file)
{
    (void)file;
    ft_putstr_fd("error file : no backslash between each element\n", 2);
    //free file;
    exit(0);
}

void    ft_write_error_3(t_list *file)
{
    (void)file;
    ft_putstr_fd("error file : multiple maj\n", 2);
    //free file;
    exit(0);
}

int    ft_check_only_one_per_line(char *str)
{
    int i;
    int flag;

    i = 0;
    flag = 0;
    while (str[i])
    {
        if (ft_is_element_min(str, i) == 1 && ft_is_element_maj(str, i) == 1 && flag == 0)
            flag = 1;
        else if (ft_is_element_min(str, i) == 1 && ft_is_element_maj(str, i) == 1 && flag == 1)
            return(0);
        i++;
    }
    return (1);
}

int     ft_is_element_min(char *str, int i)
{
    if ((str[i] == 'p' && str[i + 1] == 'l') || (str[i] == 's' && str[i + 1] == 'p') || (str[i] == 'c' && str[i + 1] == 'y'))
        return (1);
    return (0);
}

int     ft_is_element_maj(char *str, int i)
{
    if (str[i] == 'A' || str[i] == 'C' || str[i] == 'L')
        return (1);
    return (0);
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
        // mss->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "MINIRT", false);
        // mss->img = mlx_new_image(mss->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
        // mlx_put_pixel(mss->img, 600, 300, get_rgba(199, 0, 57, 255));
        // mlx_image_to_window(mss->mlx, mss->img, 0, 0);
        // mlx_loop(mss->mlx);
    }
    else
        printf("error\n");
    return (0);
}