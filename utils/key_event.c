/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:29:13 by ensebast          #+#    #+#             */
/*   Updated: 2021/10/25 00:10:51 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	iteration(t_canvas *canvas, double factor);
static void	color_change(t_canvas *canvas, double factor);
static void	panning(
				double pann_fact,
				t_canvas *canvas,
				void (*func)(t_coord*, double));

int	key_event(int keycode, void *param)
{
	if (ESC == keycode)
		end_prog((t_canvas *)param);
	else if (keycode == 65362 || W == keycode)
		panning(0.1, (t_canvas *)param, panning_v);
	else if (keycode == 65364 || S == keycode)
		panning(-0.1, (t_canvas *)param, panning_v);
	else if (keycode == 65363 || D == keycode)
		panning(0.1, (t_canvas *)param, panning_h);
	else if (keycode == 65361 || A == keycode)
		panning(-0.1, (t_canvas *)param, panning_h);
	else if (Z == keycode)
		iteration((t_canvas *)param, 2);
	else if (X == keycode)
		iteration((t_canvas *)param, 0.5);
	else if (Q == keycode)
		color_change((t_canvas *)param, 0.75);
	else if (E == keycode)
		color_change((t_canvas *)param, 1.1);
	return (0);
}

static void	color_change(t_canvas *canvas, double factor)
{
	t_color	*color;

	color = canvas -> ptr_color;
	color -> r *= factor;
	color -> g *= factor;
	color -> b *= factor;
	if ((int)(color -> r) < 30)
		color -> r = 235;
	if ((int)(color -> g) < 30)
		color -> g = 321;
	if ((int)(color -> b) < 30)
		color -> b = 429;
	draw_select(canvas, canvas -> comp);
}

static void	iteration(t_canvas *canvas, double factor)
{
	(canvas -> comp)-> iter *= factor;
	if ((canvas -> comp)-> iter == 0)
		(canvas -> comp)-> iter = 1;
	draw_select(canvas, canvas -> comp);
}

static void	panning(
		double pann_fact, t_canvas *canvas, void (*func)(t_coord*, double))
{
	func(canvas -> ptr_coord, pann_fact);
	draw_select(canvas, canvas -> comp);
}

void	end_prog(t_canvas *canvas)
{
	free_all(canvas);
	exit(0);
}
