/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 20:42:31 by ensebast          #+#    #+#             */
/*   Updated: 2021/10/24 17:01:30 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	square(t_complex *comp_num)
{
	double	real;

	real = comp_num -> real;
	comp_num -> real = (comp_num -> real * comp_num -> real)
		- (comp_num -> img * comp_num -> img);
	comp_num -> img = 2 * (real * comp_num -> img);
}

void	sum(t_complex *comp_num_f, double img, double real)
{
	comp_num_f -> real += real;
	comp_num_f -> img += img;
}

double	ft_abs(double num)
{
	if (num < 0)
		return (-1 * num);
	return (num);
}

void	ship_sum(t_complex *comp, double img, double real)
{
	comp -> real = comp -> real + real;
	comp -> img = ft_abs(comp -> img) + img;
}
