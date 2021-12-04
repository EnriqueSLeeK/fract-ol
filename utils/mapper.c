/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:18:30 by ensebast          #+#    #+#             */
/*   Updated: 2021/10/24 17:41:39 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mapper_sw_x(t_coord *coord, int s_coord, double *w_coord)
{
	*w_coord
		= ((s_coord * coord -> scale) + coord -> tl_w[0]);
}

void	mapper_sw_y(t_coord *coord, int s_coord, double *w_coord)
{
	*w_coord
		= (coord -> dr_w[1] + (s_coord * coord -> scale));
}
