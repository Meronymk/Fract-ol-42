/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krochefo <krochefo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 09:50:31 by krochefo          #+#    #+#             */
/*   Updated: 2022/09/13 06:01:56 by krochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_event(int key, t_screen_data *fract)
{
	if (key == AKEY || key == LEFT)
		fract->img.min_val -= fract->img.zoom;
	if (key == DKEY || key == RIGHT)
		fract->img.min_val += fract->img.zoom;
	if (key == WKEY || key == UP)
		fract->img.max_val += fract->img.zoom;
	if (key == SKEY || key == DOWN)
		fract->img.max_val -= fract->img.zoom;
	if (key == ESC)
		window_close(fract);
	if (key || key == 0)
	{
		update_fract(fract);
		draw_fractal(fract);
		mlx_put_image_to_window(fract->mlx, fract->win, fract->img.image,
			0 + fract->img.offset_x, 0 + fract->img.offset_y);
	}
	return (0);
}

void	scroll_event(int x, int y, t_screen_data *fract)
{
	if (x <= (fract->img.max_x / 2))
		fract->img.min_val -= fract->img.zoom * 0.5;
	else
		fract->img.min_val += fract->img.zoom * 1.5;
	if (y <= (fract->img.max_y / 2))
		fract->img.max_val += fract->img.zoom * 0.5;
	else
		fract->img.max_val -= fract->img.zoom * 1.5;
}

int	zoom_event(int mouse, int x, int y, t_screen_data *fract)
{
	long double	zoom;

	zoom = 20;
	if (mouse == SCROLLUP)
	{
		fract->img.size *= 1.1;
		scroll_event(x, y, fract);
		update_fract(fract);
		draw_fractal(fract);
	}
	if (mouse == SCROLLDOWN)
	{
		fract->img.size *= 0.9;
		scroll_event(x, y, fract);
		update_fract(fract);
		draw_fractal(fract);
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img.image,
		0 + fract->img.offset_x, 0 + fract->img.offset_y);
	return (0);
}

void	zoom_value(t_screen_data *fract)
{
	int	z;

	z = fract->img.size / 5000;
	if (z > 0 && z < 10)
		while (z-- > 0)
			fract->img.zoom = ((long double)1 / 250);
	else if (z >= 10 && z < 100)
		while (z-- > 0)
			fract->img.zoom = ((long double)1 / 1000);
	else if (z >= 100 && z < 1000)
		while (z-- > 0)
			fract->img.zoom = ((long double)1 / 50000);
	else if (z >= 1000 && z < 10000)
		while (z-- > 0)
			fract->img.zoom = ((long double)1 / 500000);
	else if (z >= 10000 && z < 100000)
		while (z-- > 0)
			fract->img.zoom = ((long double)1 / 5000000);
	else if (z >= 100000)
		while (z-- > 0)
			fract->img.zoom = ((long double)1 / 50000000);
}

void	update_fract(t_screen_data *fract)
{
	zoom_value(fract);
	mlx_destroy_image(fract->mlx, fract->img.image);
	fract->img.image = mlx_new_image(fract->mlx, fract->img.max_x,
			fract->img.max_y);
	fract->img.addr = mlx_get_data_addr(fract->img.image, &fract->img.bpp,
			&fract->img.pixel, &fract->img.end);
}
