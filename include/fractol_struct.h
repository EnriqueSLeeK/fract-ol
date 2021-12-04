/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:13:06 by ensebast          #+#    #+#             */
/*   Updated: 2021/10/24 18:09:11 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_STRUCT_H
# define FRACTOL_STRUCT_H

typedef struct s_complex
{
	double	real;
	double	img;
}	t_complex;

typedef struct s_complex_z_c
{
	int		iter;
	double	z_img;
	double	z_real;
	double	c_img;
	double	c_real;
}	t_complex_z_c;

typedef struct s_img
{
	void	*img;
	int		bpp;
	int		endian;
	int		line_byte;
	char	*buff;
}	t_img;

typedef struct s_coord
{
	int		tl_s[2];
	int		dr_s[2];
	double	tl_w[2];
	double	dr_w[2];
	double	scale;
}	t_coord;

typedef struct s_mouse
{
	double	before_x_w;
	double	before_y_w;
	double	after_x_w;
	double	after_y_w;
}	t_mouse;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	a;
}	t_color;

typedef struct s_zoom
{
	double	zoom_x;
	double	zoom_y;
}	t_zoom;

typedef struct s_canvas
{
	int				mode;
	void			*mlx;
	void			*win;
	t_img			*ptr_img;
	t_zoom			*ptr_zoom;
	t_coord			*ptr_coord;
	t_mouse			*ptr_mouse;
	t_color			*ptr_color;
	t_complex_z_c	*comp;
}	t_canvas;

#endif
