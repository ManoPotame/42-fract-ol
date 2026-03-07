/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrenn <mcrenn@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 09:17:04 by mcrenn            #+#    #+#             */
/*   Updated: 2026/03/07 23:34:49 by mcrenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/header.h"

static double	remap(int value, double low, double high, double low_og, double high_og)
{
	double	remap;

	remap = ((value - low_og) / (high_og - low_og)) * (high - low) + low;
	return (remap);
}

#include <stdio.h>
static void	mandelbrot(t_fractol *fract)
{
	int			i;
	double		x_temp;
	double		rem_x;
	double		rem_y;

	i = 0;
	rem_x = remap(fract->x, -2., 2., 0., 700.);
	rem_y = remap(fract->y, 2., -2., 0., 700.);
	fract->zx = 0.0;
	fract->zy = 0.0;
	fract->cx = (rem_x * fract->zoom) + fract->offset_x;
	fract->cy = (rem_y * fract->zoom) + fract->offset_y;
	while (++i < fract->max_iterations)
	{
		x_temp = fract->zx * fract->zx - fract->zy * fract->zy + fract->cx;
		fract->zy = 2. * fract->zx * fract->zy + fract->cy;
		fract->zx = x_temp;
		if (fract->zx * fract->zx + fract->zy * fract->zy >= __DBL_MAX__)
			break ;
	}
	if (i == fract->max_iterations)
		mlx_set_image_pixel(fract->mlx, fract->img, fract->x, fract->y, (mlx_color){.rgba = 0x000000FF});
	else
		mlx_pixel_put(fract->mlx, fract->win, fract->x, fract->y, (mlx_color){.rgba = 0xD896FFFF * i});
}


// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!FPS LIMIT
static void julia(t_fractol *fract)
{
	int			i;
	double		x_temp;
	double		rem_x;
	double		rem_y;

	i = 0;
	rem_x = remap(fract->x, -2., 2., 0., 700.);
	rem_y = remap(fract->y, 2., -2., 0., 700.);
	fract->zx = (rem_x * fract->zoom) + fract->offset_x;
	fract->zy = (rem_y * fract->zoom) + fract->offset_y;
	fract->cx = -0.70176;
	fract->cy = -0.3842;
	while (++i < fract->max_iterations)
	{
		x_temp = fract->zx * fract->zx - fract->zy * fract->zy + fract->cx;
		fract->zy = 2. * fract->zx * fract->zy + fract->cy;
		fract->zx = x_temp;
		if (fract->zx * fract->zx + fract->zy * fract->zy >= __DBL_MAX__)
			break ;
	}
	if (i == fract->max_iterations)
		mlx_set_image_pixel(fract->mlx, fract->img, fract->x, fract->y, (mlx_color){.rgba = 0x000000FF});
	else
		mlx_pixel_put(fract->mlx, fract->win, fract->x, fract->y, (mlx_color){.rgba = 0xD896FFFF * i});

}

void	drawing(t_fractol *fract)
{
	fract->y= 0;
	while (fract->y< fract->win_height)
	{
		fract->x = 0;
		while (fract->x < fract->win_width)
		{
			//mandelbrot(fract);
			julia(fract);
			fract->x++;
		}
		fract->y++;
	}
}

