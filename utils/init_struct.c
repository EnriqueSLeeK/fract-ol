/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:30:05 by ensebast          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/10/25 18:29:19 by ensebast         ###   ########.br       */
=======
/*   Updated: 2021/10/24 14:43:11 by ensebast         ###   ########.br       */
>>>>>>> b2c0f17 (project)
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	init_img(t_img *img, void *mlx)
{
	if (!img)
		return (0);
	img -> img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!(img -> img))
		return (0);
	img -> buff = mlx_get_data_addr(
			img -> img, &(img -> bpp), &(img -> line_byte), &(img -> endian));
	return (1);
}

void	init_zoom(t_zoom *zoom)
{
	zoom -> zoom_x = 1.0;
	zoom -> zoom_y = 1.0;
}

/*
 * tl = top left
 * dr = down right
 * w = world space
 * s = screen space
 */
void	init_coord(t_coord *coord)
{
<<<<<<< HEAD
	coord -> scale = (double)(5.0 / WIDTH);
=======
	coord -> scale = (double)(6.0 / WIDTH);
>>>>>>> b2c0f17 (project)
	coord -> tl_s[0] = 0;
	coord -> tl_s[1] = 0;
	coord -> dr_s[0] = WIDTH;
	coord -> dr_s[1] = HEIGHT;
	coord -> tl_w[0] = -1 * coord -> scale * (WIDTH / 2.0);
	coord -> tl_w[1] = coord -> scale * (HEIGHT / 2.0);
	coord -> dr_w[0] = -1 * coord -> tl_w[0];
	coord -> dr_w[1] = -1 * coord -> tl_w[1];
}

void	init_mouse(t_mouse *mouse)
{
	mouse -> before_x_w = 0;
	mouse -> before_y_w = 0;
	mouse -> after_x_w = 0;
	mouse -> after_y_w = 0;
}

void	init_rgb(t_color *color)
{
	color -> r = 255;
	color -> g = 255;
	color -> b = 255;
	color -> a = 100;
}
