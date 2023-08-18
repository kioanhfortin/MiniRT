/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:53:57 by fboulang          #+#    #+#             */
/*   Updated: 2023/08/18 15:11:55 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "./get_next_line.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>

# define WINDOW_WIDTH 2000
# define WINDOW_HEIGHT 1180

/*--  DATA STRUCTURES  --*/
typedef struct s_mss
{
    mlx_image_t		*img;
	mlx_t			*mlx;
    int **mat;
    
}   t_mss;

typedef struct s_list
{
	void			*str;
	struct t_list	*next;
}					t_list;

/*--  MEMORY FONCTION  ---*/
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
void	ft_listclear(t_list *head);
void    ft_print_list(t_list *file);
void	ft_putstr_fd(char *s, int fd);

/*--  02 - PARSING FONCTION  ---*/
void    ft_parsing(t_mss *mss, char *argv);
char 	*ft_copy_ext(char *str, int i);
int 	ft_tchek_file_name(char *str);
int		ft_strcmp(char *s1, char *s2);
int 	ft_check_point(int i, char *str);
void	ft_check_legit(t_list *file);
int    	ft_check_only_one_per_line(char *str);
int     ft_is_element_maj(char *str, int i);
int     ft_is_element_min(char *str, int i);
int    ft_which_maj(char *str, int *flag_a, int *flag_l, int *flag_c);

/*--  COLOR FONCTION  ---*/
int	    get_rgba(int r, int g, int b, int a);

/*--  ERROR FONCTION  ---*/
void    ft_write_error(void);
void    ft_write_error_2(t_list *file);
void    ft_write_error_3(t_list *file);

#endif