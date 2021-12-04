/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 19:22:29 by ensebast          #+#    #+#             */
/*   Updated: 2021/10/23 18:23:15 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	distance(t_complex *comp)
{
	return ((comp -> real * comp -> real) + (comp -> img * comp -> img));
}

int	check_distance(double dist)
{
	if (dist > 4.0)
		return (1);
	return (0);
}
