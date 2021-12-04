/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 23:07:01 by ensebast          #+#    #+#             */
/*   Updated: 2021/10/23 21:26:21 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_complex(t_complex_z_c *complex_nums)
{
	complex_nums -> iter = 64;
	complex_nums -> z_img = 0;
	complex_nums -> z_real = 0;
	complex_nums -> c_img = 0;
	complex_nums -> c_real = 0;
}
