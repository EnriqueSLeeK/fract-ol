/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 21:29:55 by ensebast          #+#    #+#             */
/*   Updated: 2021/10/24 14:46:14 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	free_all(t_canvas *canvas)
{
	mlx_destroy_image(canvas -> mlx, (canvas -> ptr_img)-> img);
	mlx_destroy_window(canvas -> mlx, canvas -> win);
	mlx_destroy_display(canvas -> mlx);
	free(canvas -> ptr_img);
	if (canvas -> ptr_zoom)
		free(canvas -> ptr_zoom);
	if (canvas -> ptr_mouse)
		free(canvas -> ptr_mouse);
	if (canvas -> ptr_coord)
		free(canvas -> ptr_coord);
	if (canvas -> ptr_color)
		free(canvas -> ptr_color);
	free(canvas -> mlx);
	free(canvas -> comp);
	free(canvas);
}
