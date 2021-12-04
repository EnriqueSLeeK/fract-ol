/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_panning.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:11:20 by ensebast          #+#    #+#             */
/*   Updated: 2021/10/24 17:18:01 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom_apply(t_canvas *canvas, double factor)
{
	(canvas -> ptr_coord)-> tl_w[0] *= factor;
	(canvas -> ptr_coord)-> tl_w[1] *= factor;
	(canvas -> ptr_coord)-> dr_w[0] *= factor;
	(canvas -> ptr_coord)-> dr_w[1] *= factor;
	(canvas -> ptr_coord)-> scale *= factor;
}

void	zoom_in(t_canvas *zoom)
{
	zoom_apply(zoom, ZOOM_IN);
}

void	zoom_out(t_canvas *zoom)
{
	zoom_apply(zoom, ZOOM_OUT);
}

void	panning_h(t_coord *coord, double pann_x)
{
	double	diff;

	diff = pann_x * (coord -> dr_w[0] - coord -> tl_w[0]);
	coord -> tl_w[0] += diff;
	coord -> dr_w[0] += diff;
}

void	panning_v(t_coord *coord, double pann_y)
{
	double	diff;

	diff = pann_y * (coord -> dr_w[1] - coord -> tl_w[1]);
	coord -> tl_w[1] += diff;
	coord -> dr_w[1] += diff;
}
