/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrenn <mcrenn@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:16:42 by mcrenn            #+#    #+#             */
/*   Updated: 2026/03/07 22:14:26 by mcrenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/header.h"

/*Fonction appelée si key est pressée*/
void	key_hook(int key, void *param)
{
	if (key == 41)
	{
		mlx_loop_end((mlx_context)param);
	}
}
#include <stdio.h>
void	win_hook(int key, void *param)
{
	if (key == 0)
		mlx_loop_end((mlx_context)param);
}

void	make_window(t_fractol *fract)
{
	drawing(fract);

	mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);

	mlx_on_event(fract->mlx, fract->win, MLX_KEYDOWN, key_hook, fract->mlx);

	mlx_on_event(fract->mlx, fract->win, MLX_WINDOW_EVENT, win_hook, fract->mlx);
	mlx_loop(fract->mlx);
}
