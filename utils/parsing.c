/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 21:41:04 by ensebast          #+#    #+#             */
/*   Updated: 2021/10/24 15:50:12 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	parsing(char *mode, char *x, char *y, t_complex_z_c *set_complex)
{
	int		i;
	char	*str[4];

	str[0] = "mandelbrot";
	str[1] = "julia";
	str[2] = "burning_ship";
	str[3] = 0;
	i = 0;
	while (str[i])
	{
		if (ft_strcmp(mode, str[i]))
			break ;
		i += 1;
	}
	if (i == 1)
	{
		set_complex -> z_real = ft_atof(x);
		set_complex -> z_img = ft_atof(y);
	}
	if (str[i] == 0)
		return (-1);
	return (i);
}
