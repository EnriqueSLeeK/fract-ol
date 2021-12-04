/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 19:08:15 by ensebast          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/12/04 17:13:18 by ensebast         ###   ########.br       */
=======
/*   Updated: 2021/10/24 17:42:06 by ensebast         ###   ########.br       */
>>>>>>> b2c0f17 (project)
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include "fractol_struct.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

<<<<<<< HEAD
# define WIDTH 500
# define HEIGHT 500
=======
# define WIDTH 900
# define HEIGHT 640
>>>>>>> b2c0f17 (project)

# define ESC 65307
# define Q 113
# define E 101
# define W 119
# define S 115
# define A 97
# define D 100
<<<<<<< HEAD
=======
# define R 114
>>>>>>> b2c0f17 (project)
# define Z 122
# define X 120

# define S_UP 4
# define S_DOWN 5

# define ZOOM_IN 0.9
# define ZOOM_OUT 1.1

//Init functions
int		init(t_canvas **canvas);
void	init_zoom(t_zoom *zoom);
void	init_rgb(t_color *color);
void	init_coord(t_coord *coord);
void	init_mouse(t_mouse *mouse);
int		init_img(t_img *img, void *mlx);
void	init_complex(t_complex_z_c *complex_nums);

//Events
int		key_event(int keycode, void *param);
int		mouse_event(int button, int x, int y, void *param);

//Iterators
int		julia(t_complex_z_c *comp_num);
int		mandelbrot(t_complex_z_c *comp_num);
int		burning_ship(t_complex_z_c *comp_num);

//Free everything after
void	free_all(t_canvas *canvas);

//Misc Utils
double	ft_atof(char *num);
double	distance(t_complex *comp);
void	end_prog(t_canvas *canvas);
int		check_distance(double dist);
int		ft_strcmp(char *target, char *str_control);
int		parsing(char *mode, char *x, char *y, t_complex_z_c *set_complex);

//Complex number operation
void	square(t_complex *comp);
void	sum(t_complex *comp_f, double img, double real);
void	ship_sum(t_complex *comp, double img, double real);

//Zoom and panning
void	zoom_in(t_canvas *zoom);
void	zoom_out(t_canvas *zoom);
void	panning_h(t_coord *c, double pann_x);
void	panning_v(t_coord *c, double pann_y);

//Mapper
void	mapper_sw_x(t_coord *coord, int s_coord, double *w_coord);
void	mapper_sw_y(t_coord *coord, int s_coord, double *w_coord);

//Draw selection
void	draw_select(t_canvas *canvas, t_complex_z_c *comp);
#endif
