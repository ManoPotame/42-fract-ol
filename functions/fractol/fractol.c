/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrenn <mcrenn@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 09:17:04 by mcrenn            #+#    #+#             */
/*   Updated: 2026/03/12 16:49:58 by mcrenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fractol.h"

/**
 * @brief Function that adapt the size of fractol (-2, 2)
 * to the size of window (700 * 700).
 *
 * @param value The value of x or y.
 * @param low The smallest size of fractal dimesion.
 * @param high The highest size of fractal dimension.
 * @return double
 */
static double	remap(int value, double low, double high)
{
	double	remap;
	double	low_og;
	double	high_og;

	low_og = 0.;
	high_og = 700.;
	remap = ((value - low_og) / (high_og - low_og)) * (high - low) + low;
	return (remap);
}

/**
 * @brief Function that coloring the a pixel of the window depending on
 * those iterations and the index.
 *
 * @param i The sended index.
 * @param color The sended color.
 * @param fract The structure of fractol.
 */
static void	coloring(int i, uint32_t color, t_fractol *fract)
{
	if (i == fract->max_iterations)
		mlx_set_image_pixel(fract->mlx, fract->img, fract->x, fract->y,
			(mlx_color){.rgba = 0x000000FF});
	else
		mlx_set_image_pixel(fract->mlx, fract->img, fract->x, fract->y,
			(mlx_color){.rgba = color * i});
}

/**
 * @brief Function that calculate the mandelbrot fractal
 * and apply the coloration for the current pixel.
 *
 * @param fract The structure of fractol.
 */
static void	mandelbrot(t_fractol *fract)
{
	int			i;
	double		x_temp;
	double		rem_x;
	double		rem_y;

	i = 0;
	rem_x = remap(fract->x, -2., 2.);
	rem_y = remap(fract->y, 2., -2.);
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
	coloring(i, 0xD896FFFF, fract);
}

/**
 * @brief Function that calculate the julia fractal and apply the coloration
 * fir the current pixel.
 *
 * @param fract The structure of fractol.
 */
static void	julia(t_fractol *fract)
{
	int			i;
	double		x_temp;
	double		rem_x;
	double		rem_y;

	i = 0;
	rem_x = remap(fract->x, -2., 2.);
	rem_y = remap(fract->y, 2., -2.);
	fract->zx = (rem_x * fract->zoom) + fract->offset_x;
	fract->zy = (rem_y * fract->zoom) + fract->offset_y;
	while (++i < fract->max_iterations)
	{
		x_temp = fract->zx * fract->zx - fract->zy * fract->zy + fract->cx;
		fract->zy = 2. * fract->zx * fract->zy + fract->cy;
		fract->zx = x_temp;
		if (fract->zx * fract->zx + fract->zy * fract->zy >= __DBL_MAX__)
			break ;
	}
	coloring(i, 0xD896FFFF, fract);
}

/**
 * @brief Function which call mandelbrot or julia for every pixel of the window.
 *
 * @param fract The structure of fractol.
 */
void	drawing(t_fractol *fract)
{
	fract->y = 0;
	while (fract->y < fract->win_height)
	{
		fract->x = 0;
		while (fract->x < fract->win_width)
		{
			if (fract->fract_id == 0)
				mandelbrot(fract);
			else
				julia(fract);
			fract->x++;
		}
		fract->y++;
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);
}
