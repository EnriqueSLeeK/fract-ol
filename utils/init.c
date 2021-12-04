/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:03:59 by ensebast          #+#    #+#             */
/*   Updated: 2021/10/24 14:47:09 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	check_success(t_canvas *canvas, int flag)
{
	if (!(canvas -> ptr_zoom && canvas -> ptr_coord
			&& canvas -> ptr_mouse && canvas -> ptr_color))
	{
		free_all(canvas);
		flag = 0;
	}
	return (flag);
}

static int	mwi_init(t_canvas *canvas)
{
	canvas -> mlx = mlx_init();
	if (canvas -> mlx == 0)
	{
		printf("mlx init fail!\n");
		return (0);
	}
	canvas -> win = mlx_new_window(canvas -> mlx, WIDTH, HEIGHT, "Fract'ol");
	if (canvas -> win == 0)
	{
		printf("Window init fail!\n");
		free(canvas -> mlx);
		return (0);
	}
	canvas -> ptr_img = malloc(sizeof(t_img));
	if (!init_img(canvas -> ptr_img, canvas -> mlx))
	{
		printf("Image init fail!\n");
		if (!(canvas -> ptr_img))
			free(canvas -> ptr_img);
		mlx_destroy_window(canvas -> mlx, canvas -> win);
		free(canvas -> mlx);
		return (0);
	}
	return (1);
}

int	init(t_canvas **canvas)
{
	if (!(mwi_init(*canvas)))
	{
		free(*canvas);
		return (0);
	}
	(*canvas)-> ptr_zoom = malloc(sizeof(t_zoom));
	(*canvas)-> ptr_coord = malloc(sizeof(t_coord));
	(*canvas)-> ptr_mouse = malloc(sizeof(t_mouse));
	(*canvas)-> ptr_color = malloc(sizeof(t_color));
	if (!check_success(*canvas, 1))
		return (0);
	init_zoom((*canvas)-> ptr_zoom);
	init_coord((*canvas)-> ptr_coord);
	init_mouse((*canvas)-> ptr_mouse);
	init_rgb((*canvas)-> ptr_color);
	return (1);
}
