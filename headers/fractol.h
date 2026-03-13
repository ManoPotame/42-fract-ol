/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrenn <mcrenn@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 13:17:12 by mcrenn            #+#    #+#             */
/*   Updated: 2026/03/13 11:16:49 by mcrenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../functions/macrolibx/includes/mlx.h"
# include "../functions/libft/libft.h"
# include <stdbool.h>
# include <stdlib.h>
# include <math.h>

# define HEIGH_WIN 700
# define WIDTH_WIN 700

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
	double		zoom;
	int			win_width;
	int			win_height;
	int			max_iterations;
	int			color;
	int			fract_id;
}	t_fractol;

void	make_window(t_fractol *fract);
void	drawing(t_fractol *fract);

double	ft_atof(char *complex_num, t_fractol *fract);

int		error_manager(int code, char *message, t_fractol *fract);

#endif
