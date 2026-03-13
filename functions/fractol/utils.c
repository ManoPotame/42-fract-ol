/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrenn <mcrenn@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 21:04:49 by mcrenn            #+#    #+#             */
/*   Updated: 2026/03/12 16:28:36 by mcrenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fractol.h"

/**
 * @brief The second part of atof that take the dot and the number after.
 *
 * @param i The sended index.
 * @param num The string used to be floated.
 * @param result The actual state of float.
 * @param fract The structure of fractol.
 */
static void	dot_add(int i, char *num, double *result, t_fractol *fract)
{
	int	j;

	j = 1;
	while (num[i])
	{
		if (ft_isdigit(num[i]) == 0)
			error_manager(4, "Bad argument after fractal.", fract);
		*result += (num[i++] - '0') / pow(10, j++);
	}
}

/**
 * @brief Function that convert ascii characters to float.
 *
 * @param complex_num The string used to be floated.
 * @param fract The structure of fractol.
 * @return double
 */
double	ft_atof(char *complex_num, t_fractol *fract)
{
	int		i;
	double	sign;
	double	result;

	i = 0;
	sign = 1.;
	result = 0.;
	if ((complex_num[i] && complex_num[i] == '-') || complex_num[i] == '+')
		sign = ((complex_num[i++] % 43) * -1.) + 1.;
	while (complex_num[i] && complex_num[i] != '.')
	{
		if (result > (__DBL_MAX__ - (complex_num[i] - '0')) / 10.)
			error_manager(3, "Argument bigger than double max.", fract);
		if (ft_isdigit(complex_num[i]) == 0)
			error_manager(4, "Bad argument after fractal.", fract);
		result = (result * 10) + complex_num[i++] - '0';
	}
	if (complex_num[i] != '.' || !complex_num[i])
		return (result * sign);
	i++;
	dot_add(i, complex_num, &result, fract);
	return (result * sign);
}
