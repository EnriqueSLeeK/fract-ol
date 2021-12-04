/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:37:18 by ensebast          #+#    #+#             */
/*   Updated: 2021/10/24 18:18:31 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom_canvas(int x, int y, t_canvas *canvas, void (*f)(t_canvas*));

int	mouse_event(int button, int x, int y, void *param)
{
	if (button == S_UP)
		zoom_canvas(x, y, (t_canvas *)param, zoom_in);
	else if (button == S_DOWN)
		zoom_canvas(x, y, (t_canvas *)param, zoom_out);
	return (0);
}

static void	zoom_canvas(int x, int y, t_canvas *canvas, void (*f)(t_canvas*))
{
	t_mouse	*mouse;
	t_coord	*coord;

	coord = canvas -> ptr_coord;
	mouse = canvas -> ptr_mouse;
	mapper_sw_x(coord, x, &(mouse -> before_x_w));
	mapper_sw_y(coord, y, &(mouse -> before_y_w));
	f(canvas);
	mapper_sw_x(coord, x, &(mouse -> after_x_w));
	mapper_sw_y(coord, y, &(mouse -> after_y_w));
	coord -> tl_w[0] -= mouse -> after_x_w - mouse -> before_x_w;
	coord -> dr_w[0] -= mouse -> after_x_w - mouse -> before_x_w;
	coord -> tl_w[1] -= mouse -> after_y_w - mouse -> before_y_w;
	coord -> dr_w[1] -= mouse -> after_y_w - mouse -> before_y_w;
	draw_select(canvas, canvas -> comp);
}
