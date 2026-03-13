/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrenn <mcrenn@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:34:24 by mcrenn            #+#    #+#             */
/*   Updated: 2026/03/12 16:32:12 by mcrenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fractol.h"

/**
 * @brief Function that free the structure of fractol if it's needed, send to
 * to terminal an error and his description.
 *
 * @param code The code of error.
 * @param message The message to be displayed in terminal.
 * @param fract The structure of fractol.
 * @return int
 */
int	error_manager(int code, char *message, t_fractol *fract)
{
	if (fract)
		free(fract);
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(message, 2);
	ft_putchar_fd('\n', 2);
	exit(code);
}
