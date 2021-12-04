/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 20:50:32 by ensebast          #+#    #+#             */
/*   Updated: 2021/10/23 21:03:41 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_complex_z_c *comp_num)
{
	t_complex	*comp;
	int			i;

	comp = malloc(sizeof(t_complex));
	if (!comp)
		return (0);
	i = 0;
	comp -> real = comp_num -> c_real;
	comp -> img = comp_num -> c_img;
	while (i < comp_num -> iter)
	{
		square(comp);
		sum(comp, comp_num -> z_img, comp_num -> z_real);
		if (check_distance(distance(comp)))
			break ;
		i += 1;
	}
	free(comp);
	return (i);
}
