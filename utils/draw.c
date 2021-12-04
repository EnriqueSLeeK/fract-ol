/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:46:23 by ensebast          #+#    #+#             */
/*   Updated: 2021/10/25 00:16:25 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	draw(t_canvas *canvas,
				int (*algo)(t_complex_z_c *),
				t_complex_z_c *c);

void	put_pixel(t_canvas *canvas, char *buff, int iter, int pixel)
{
	t_color			*rgba;
	t_complex_z_c	*comp;

	rgba = canvas -> ptr_color;
	comp = canvas -> comp;
	if ((canvas -> ptr_img)-> endian)
	{
		buff[pixel] = rgba -> a;
		buff[pixel + 1] = (int)(rgba -> r * cos(360 * iter / comp -> iter));
		buff[pixel + 2] = (int)(rgba -> g * sin(360 * iter / comp -> iter));
		buff[pixel + 3] = (int)(rgba -> b * tan(360 * iter / comp -> iter));
	}
	else
	{
		buff[pixel] = 175 - (int)(rgba -> b * tan(180 * iter / comp -> iter));
		buff[pixel + 1] = 100
			- (int)(rgba -> g * cos(180 * iter / comp -> iter));
		buff[pixel + 2] = 124 - (int)(rgba -> r * iter / comp -> iter);
		buff[pixel + 3] = rgba -> a;
	}
}

void	draw_select(t_canvas *canvas, t_complex_z_c *comp)
{
	if (canvas -> mode == 0)
		draw(canvas, mandelbrot, comp);
	else if (canvas -> mode == 1)
		draw(canvas, julia, comp);
	else if (canvas -> mode == 2)
		draw(canvas, burning_ship, comp);
}

static void	draw(t_canvas *canvas,
				int (*algo)(t_complex_z_c *),
				t_complex_z_c *c)
{
	int	x;
	int	y;
	int	pixel;

	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		while (y < HEIGHT)
		{
			pixel = (x * 4) + (y * (canvas -> ptr_img)-> line_byte);
			mapper_sw_x(canvas -> ptr_coord,
				x, &(c -> c_real));
			mapper_sw_y(canvas -> ptr_coord,
				y, &(c -> c_img));
			put_pixel(canvas, (canvas -> ptr_img)-> buff,
				algo(c), pixel);
			y += 1;
		}
		x += 1;
		y = 0;
	}
	mlx_put_image_to_window(canvas -> mlx, canvas -> win,
		(canvas -> ptr_img)-> img, 0, 0);
}
