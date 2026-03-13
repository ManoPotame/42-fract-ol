/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrenn <mcrenn@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 13:22:36 by mcrenn            #+#    #+#             */
/*   Updated: 2026/03/12 16:26:50 by mcrenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fractol.h"

/**
 * @brief Function that choose the good fractal to execute,
 * convert string elements to float if the fractal is julia.
 *
 * @param fract The structure of fractol.
 * @param argc Number of argument when "./fractol" will be execute.
 * @param argv Array string for all arguments "./fractol" will be execute.
 * @return int
 */
int	choose_fractal(t_fractol *fract, int argc, char **argv)
{
	int	fract_code;

	fract_code = -1;
	if (ft_strcmp(argv[1], "mandelbrot") == 0 && argc == 2)
		fract_code = 0;
	else if (ft_strcmp(argv[1], "julia") == 0)
	{
		if (argc == 4)
		{
			fract->cx = ft_atof(argv[2], fract);
			fract->cy = ft_atof(argv[3], fract);
			if (fract->cx < -2. || fract->cx > 2.)
				error_manager(1, "cx must be betwenn -2 and 2", fract);
			if (fract->cy < -2. || fract->cy > 2.)
				error_manager(1, "cy must be betwenn -2 and 2", fract);
		}
		else
			error_manager(3, "Bad number of arguments after julia.", fract);
		fract_code = 1;
	}
	else
		error_manager(2, "Incorrect formulation of fractal.", fract);
	return (fract_code);
}

/**
 * @brief Function that initialize the structure of fractol.
 *
 * @param argc Number of argument when "./fractol" will be execute.
 * @param argv Array string for all arguments "./fractol" will be execute.
 * @return t_fractol*
 */
static t_fractol	*init(int argc, char **argv)
{
	t_fractol				*fract;
	mlx_image				img;
	mlx_window				win;
	mlx_window_create_info	info;

	fract = malloc(sizeof(t_fractol));
	if (!fract)
		exit(1);
	fract->mlx = mlx_init();
	fract->win_width = WIDTH_WIN;
	fract->win_height = HEIGH_WIN;
	fract->x = 0;
	fract->y = 0;
	fract->zoom = 1;
	fract->fract_id = choose_fractal(fract, argc, argv);
	fract->offset_x = 0;
	fract->offset_y = 0;
	fract->max_iterations = 200;
	info = (mlx_window_create_info){.title = "fractol",
		.height = fract->win_height, .width = fract->win_width,};
	img = mlx_new_image(fract->mlx, fract->win_width, fract->win_width);
	win = mlx_new_window(fract->mlx, &info);
	fract->img = img;
	fract->win = win;
	return (fract);
}

/**
 * @brief Main function that open a window and display julia's or mandelbrot's
 * fractal.
 *
 * @param argc Number of argument when "./fractol" will be execute.
 * @param argv Array string for all arguments "./fractol" will be execute.
 * @return int
 */
int	main(int argc, char **argv)
{
	t_fractol	*fract;

	if (argc < 2)
	{
		error_manager(1, "Bad number of arguments.", NULL);
		return (1);
	}
	fract = init(argc, argv);
	make_window(fract);
	free(fract);
}
