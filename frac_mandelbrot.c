/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krochefo <krochefo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 09:51:32 by krochefo          #+#    #+#             */
/*   Updated: 2022/09/13 06:02:08 by krochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_to_mlx(t_img_data img, int x, int y, int color)
{
	char	*dst;

	dst = img.addr + (y * img.pixel + x * (img.bpp / 8));
	*(unsigned int *)dst = color;
}

int	calculate_mandel(double a, double b, int iter)
{
	int		it;
	double	t;
	double	x;
	double	y;

	it = -1;
	x = 0;
	y = 0;
	while (++it <= iter)
	{
		t = x;
		x = (x * x) - (y * y) + a;
		y = (2 * t * y) + b;
		if ((x * x) + (y * y) > 4)
			break ;
	}
	return (it);
}

void	draw_mandel(t_img_data img)
{
	int		i;
	double	a;
	double	b;

	img.pos_y = -1;
	while (++img.pos_y <= img.max_y - 1)
	{
		img.pos_x = -1;
		b = img.max_val - (img.pos_y / img.size);
		while (++img.pos_x <= img.max_x - 1)
		{
			a = img.min_val + (img.pos_x / img.size);
			i = calculate_mandel(a, b, img.iter);
			color_to_mlx(img, img.pos_x, img.pos_y, ft_color_mandel(i));
		}
	}
}
