/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 21:37:52 by ensebast          #+#    #+#             */
/*   Updated: 2021/10/27 01:48:58 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	alloc_start(t_canvas **canvas, t_complex_z_c **comp_nums)
{
	*canvas = malloc(sizeof(t_canvas));
	if (!init(canvas))
	{
		printf("Error!\n");
		exit(0);
	}
	*comp_nums = malloc(sizeof(t_complex_z_c));
	if (comp_nums == 0)
	{
		free_all(*canvas);
		exit(0);
	}
	(*canvas)-> comp = *comp_nums;
	init_complex(*comp_nums);
}

int	main(int argc, char *argv[])
{
	t_canvas		*canvas;
	t_complex_z_c	*comp_nums;

	comp_nums = 0;
	if (argc > 1)
	{
		alloc_start(&canvas, &comp_nums);
		canvas -> mode = parsing(argv[1], argv[3], argv[2], comp_nums);
		if (canvas -> mode == -1)
		{
			printf("Available set: mandelbrot, julia <img> <real>,");
			printf(" burning_ship\n");
			end_prog(canvas);
		}
		draw_select(canvas, comp_nums);
		mlx_key_hook(canvas -> win, &key_event, canvas);
		mlx_mouse_hook(canvas -> win, &mouse_event, canvas);
		mlx_loop(canvas -> mlx);
	}
	else
		printf("Available set: mandelbrot, julia <img> <real> burning_ship\n");
	return (0);
}
