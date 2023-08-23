/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:53:57 by fboulang          #+#    #+#             */
/*   Updated: 2023/08/22 16:40:13 by kfortin          ###   ########.fr       */
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
#include <math.h>
# include <stdlib.h>

# define WINDOW_WIDTH 2000
# define WINDOW_HEIGHT 1180

/*--  DATA STRUCTURES  --*/
typedef struct s_cam
{
	double	coor_position[3]; 	// Camera position (x, y, z);
	double	coor_look[3];		// Point where the camera is looking;
	double	view_direction_up[3];
	double	view_direction_right[3];
	double 	up[3];				// Up vector (normalized)
	double 	right[3];			// Right vector & up vector are needed to construct le systeme de coor local de la camera
	
	double	fov;				//Field of view in degrees
	double	aspect_ratio;		//Width/height ratio of the sensor
	double 	focal_length;		//Focal lenght of the lens
	double	aperture;			//Aperture size for depth of field
	double	view_direction_norm_up;	//assurer la precision des calculs de vision en 3D
	double	view_direction_norm_right;
	double half_width;
	double half_height;
}	t_cam;
typedef struct s_mss
{
    t_cam	*cam;
    mlx_image_t		*img;
	mlx_t			*mlx;
    int **mat;
	int **modif_mat;
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

/*--  02 - INITIATION FONCTION  ---*/
void    ft_init_mat(t_mss *mss);

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

/*--  OBJECT FONCTION  ---*/
void    ft_plan_drawing(t_mss *mss);
double	ft_deg_rad(int deg);
int 	ft_is_out_of_range(int x, int y);
void    ft_cylinder_drawing(t_mss *mss);
void    ft_circle_drawing(t_mss *mss);
void    ft_circle_2_drawing(t_mss *mss);
// void    ft_apply_trans(t_mss *mss, int x, int y, int z);

/*--  CAMERA FONCTION  ---*/
void	ft_set_up_camera(t_mss *mss);
void    ft_affichage_plan_camera(t_mss *mss);

/*--  ERROR FONCTION  ---*/
void    ft_write_error(void);
void    ft_write_error_2(t_list *file);
void    ft_write_error_3(t_list *file);

#endif