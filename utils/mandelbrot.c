/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:54:09 by ensebast          #+#    #+#             */
/*   Updated: 2021/10/24 14:55:41 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_complex_z_c *comp_num)
{
	t_complex	*comp;
	int			i;

	comp = malloc(sizeof(t_complex));
	if (!comp)
		return (0);
	i = 0;
	comp -> real = comp_num -> z_real;
	comp -> img = comp_num -> z_img;
	while (i < comp_num -> iter)
	{
		square(comp);
		sum(comp, comp_num -> c_img, comp_num -> c_real);
		if (check_distance(distance(comp)))
			break ;
		i += 1;
	}
	free(comp);
	return (i);
}
