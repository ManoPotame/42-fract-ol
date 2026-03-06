/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrenn <mcrenn@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 13:17:12 by mcrenn            #+#    #+#             */
/*   Updated: 2026/03/06 18:35:14 by mcrenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../functions/macrolibx/includes/mlx.h"
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

typedef struct s_fractol
{
	mlx_context	mlx;
	mlx_window	win;
	mlx_image	img;
	double		cx;
	double		cy;
	double		zx;
	double		zy;
	double		offset_x;
	double		offset_y;
	int			x;
	int			y;
	int			zoom;
	int			win_width;
	int			win_height;
	int			max_iterations;
	int			color;
}	t_fractol;


void	make_window(t_fractol *fract);
void	drawing(t_fractol *fract);
