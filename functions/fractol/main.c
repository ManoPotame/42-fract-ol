/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrenn <mcrenn@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 13:22:36 by mcrenn            #+#    #+#             */
/*   Updated: 2026/03/07 23:41:16 by mcrenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/header.h"

static t_fractol	*init(void)
{
	t_fractol				*fract;
	mlx_image				img;
	mlx_window				win;
	mlx_window_create_info	info;

	fract = malloc(sizeof(t_fractol));
	if (!fract)
		exit(1);
	fract->mlx = mlx_init();
	fract->win_width = 700;
	fract->win_height = 700;
	fract->x = 0;
	fract->y = 0;
	fract->zoom = 1;
	fract->offset_x = 0;
	fract->offset_y = 0;
	fract->max_iterations = 100;
	info = (mlx_window_create_info){.title = "fractol",
		.height = fract->win_height, .width = fract->win_width,};
	img = mlx_new_image(fract->mlx, fract->win_width, fract->win_width);
	win = mlx_new_window(fract->mlx, &info);
	fract->img = img;
	fract->win = win;
	return (fract);
}

int	main(int argc, char **argv)
{
	t_fractol	*fract;

	if(argc > 4)
	{
		//error
		return (1);
	}
 	fract = init();
	make_window(fract);
}
