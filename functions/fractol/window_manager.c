/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrenn <mcrenn@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:16:42 by mcrenn            #+#    #+#             */
/*   Updated: 2026/03/12 16:40:12 by mcrenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fractol.h"

/**
 * @brief Function that close the window if ESC is pressed.
 *
 * @param key The value of keycaps.
 * @param param The structure of fractol.
 */
void	key_hook(int key, void *param)
{
	t_fractol	*fract;

	fract = (t_fractol *)param;
	if (key == 41)
	{
		mlx_loop_end(fract->mlx);
	}
}

/**
 * @brief Function that close the window if the close button is pressed.
 *
 * @param key The input on window.
 * @param param The structure of fractol.
 */
void	win_hook(int key, void *param)
{
	t_fractol	*fract;

	fract = (t_fractol *)param;
	if (key == 0)
		mlx_loop_end(fract->mlx);
}

/**
 * @brief Function that zoom on the window if the scroll input is triggered.
 *
 * @param key The input on window.
 * @param param The structure of fractol.
 */
void	zooming(int key, void *param)
{
	t_fractol	*fract;

	fract = (t_fractol *)param;
	if (key == 1)
	{
		fract->zoom /= 1.1;
	}
	if (key == 2)
	{
		fract->zoom *= 1.1;
	}
	mlx_clear_window(fract->mlx, fract->win, (mlx_color){.rgba = 0x000000FF});
	drawing(fract);
}

/**
 * @brief Function that make the window, draw on it the fractal and listen the
 * inputs on the window to trigger an event.
 *
 * @param fract The structure of fractol.
 */
void	make_window(t_fractol *fract)
{
	mlx_set_fps_goal(fract->mlx, 30);
	drawing(fract);
	mlx_on_event(fract->mlx, fract->win, MLX_KEYDOWN, key_hook, fract);
	mlx_on_event(fract->mlx, fract->win, MLX_WINDOW_EVENT, win_hook, fract);
	mlx_on_event(fract->mlx, fract->win, MLX_MOUSEWHEEL, zooming, fract);
	mlx_loop(fract->mlx);
}
