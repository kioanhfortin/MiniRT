/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:53:57 by fboulang          #+#    #+#             */
/*   Updated: 2023/08/15 17:28:30 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "./get_next_line.h"
# include "../MLX42/include/MLX42/MLX42.h"
//# include "./libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>

# define WINDOW_WIDTH 2000
# define WINDOW_HEIGHT 1180

/*--  DATA STRUCTURES  --*/

typedef struct s_list
{
	void			*str;
	struct t_list	*next;
}					t_list;

typedef struct s_alight
{
	int	ratio;
	int	rgb[3];
}	t_alight;

typedef struct s_cam
{
	int	pov[3];
	int	vec[3];
	int	fov;
}	t_cam;

typedef struct s_light
{
	int	ol[3];
	int ratio;
	int rgb[3];
}	t_light;

typedef struct s_sp
{
	int	spo[3];
	int	diam;
	int	rgb[3];
	int	**mod;
}	t_sp;

typedef struct s_pl
{
	int	po[3];
	int	vec[3];
	int	rgb[3];
	int	**mod;
}	t_pl;

typedef struct s_cy
{
	int	co[3];
	int	vec[3];
	int	diam;
	int	height;
	int	rgb[3];
	int	**mod;
}	t_cy;

typedef struct s_mss
{
    mlx_image_t		*img;
	mlx_t			*mlx;
    int 			**mat;
	t_alight		amb;
	t_cam			vis;
	t_light			sun;
	t_sp			**circ;
	t_pl			**tac;
	t_cy			**cyl;
}   				t_mss;

/*--  MEMORY FONCTION  ---*/
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
void	ft_listclear(t_list *head);
void    ft_print_list(t_list *file);
void	ft_putstr_fd(char *s, int fd);

/*--  02 - PARSING FONCTION  ---*/
void    ft_parsing(t_mss *mss, char *argv);
int		ft_atoi(const char *str);

/*--  COLOR FONCTION  ---*/
int	    get_rgba(int r, int g, int b, int a);

/*-- KEYHOOK FUNCTIONS ---*/
void	on_destroy(void *param);
void	print_key(mlx_key_data_t keydata, void *param);

#endif