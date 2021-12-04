/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 21:46:06 by ensebast          #+#    #+#             */
/*   Updated: 2021/10/24 15:00:42 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	build_double(char *num, int *i, double *res, double *fact)
{
	int		tmp;
	int		point;

	point = 0;
	while (num[*i])
	{
		if (num[*i] == '.')
		{
			point = 1;
			*i += 1;
			continue ;
		}
		tmp = num[*i] - '0';
		if (tmp >= 0 && tmp <= 9)
		{
			if (point)
				*fact /= 10.0f;
			*res = *res * 10.0f + (double)(tmp);
		}
		else
			return (-1);
		*i += 1;
	}
	return (1);
}

double	ft_atof(char *num)
{
	int		i;
	double	res;
	double	fact;

	fact = 1;
	res = 0;
	i = 0;
	if (num == 0)
		return (0);
	if (num[0] == '-')
	{
		fact *= -1;
		i += 1;
	}
	if (build_double(num, &i, &res, &fact) == -1)
	{
		printf("Not properly formatted!\nReturning default value.\n");
		return (0);
	}
	return (res * fact);
}
