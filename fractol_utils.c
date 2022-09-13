/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krochefo <krochefo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 20:42:46 by krochefo          #+#    #+#             */
/*   Updated: 2022/09/13 06:02:04 by krochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	window_close(t_screen_data *fract)
{
	mlx_destroy_image(fract->mlx, fract->img.image);
	mlx_destroy_window(fract->mlx, fract->win);
	exit(0);
}

void	else_message(t_screen_data *fract)
{
	printf("Available fractals:\n- Mandelbrot\n- Julia\n");
	window_close(fract);
}