/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:53:57 by fboulang          #+#    #+#             */
/*   Updated: 2023/08/23 17:33:14 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "./get_next_line.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include "./libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>

# include <GLFW/glfw3.h>

# define WINDOW_WIDTH 1080
# define WINDOW_HEIGHT 900

/*--  DATA STRUCTURES  --*/
typedef struct s_cam2
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
}	t_cam2;

typedef struct s_pix
{
	double	pixel_x;
	double	pixel_y;
}			t_pix;

typedef struct s_ray
{
	double	ray_direction_x;
	double	ray_direction_y;
	double	ray_direction_z;
}			t_ray;


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
 	t_cam2			*cam2;
	t_pix			pixs;
	t_ray			ray;
    mlx_image_t		*img;
	mlx_t			*mlx;
    int 			**mat;
	t_alight		amb;
	t_cam			vis;
	t_light			sun;
	t_sp			**circ;
	t_pl			**tac;
	t_cy			**cyl;
	int				plnum;
	int				spnum;
	int				cylnum;
	int				resolution;
}   				t_mss;

/*--  MEMORY FONCTION  ---*/
void    ft_print_list(t_list *file);


/*--  02 - INITIATION FONCTION  ---*/
void    ft_init_val(t_mss *mss);
void    ft_init_mod(t_mss *mss, int i);

/*--  02 - PARSING FONCTION  ---*/
void    ft_parsing(t_mss *mss, char *argv);
int		ft_atoi(const char *str);
void 	ft_fetch_info(t_list *file, t_mss *mss);
void	ft_fetch_alight(char *str, t_mss *mss);
void	ft_fetch_cam(char *str, t_mss *mss);
void	ft_fetch_light(char *str, t_mss *mss);
t_pl	*ft_fetch_plan(char *str);
t_sp	*ft_fetch_sphere(char *str);
t_cy	*ft_fetch_cylinder(char *str);
char	*acquire_data(char *inc, int nums[3]);
void	acquire_nums(t_mss *mss, t_list *file);
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
void	ft_fetch_form(t_mss *mss);
void    ft_plan_drawing(t_mss *mss, int i);
double	ft_deg_rad(int deg);
int 	ft_is_out_of_range(int x, int y);
void    ft_cylinder_drawing(t_mss *mss);
void    ft_circle_drawing(t_mss *mss);
void    ft_circle_2_drawing(t_mss *mss, int i);
// void    ft_apply_trans(t_mss *mss, int x, int y, int z);
int    ft_intersection_sp(t_mss *mss, int i, double *t);

/*--  CAMERA FONCTION  ---*/
void	ft_set_up_camera(t_mss *mss);
void    ft_affichage_plan_camera(t_mss *mss);
void    ft_ray_trace(t_mss *mss);

/*--  ERROR FONCTION  ---*/
void    ft_write_error(void);
void    ft_write_error_2(t_list *file);
void    ft_write_error_3(t_list *file);

/*-- KEYHOOK FUNCTIONS ---*/
void	on_destroy(void *param);
void	print_key(mlx_key_data_t keydata, void *param);

#endif