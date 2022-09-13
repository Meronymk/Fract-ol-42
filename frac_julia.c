/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krochefo <krochefo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 09:51:18 by krochefo          #+#    #+#             */
/*   Updated: 2022/09/13 05:59:50 by krochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calculate_julia(double x, double y, t_screen_data *fract)
{
	int		it;
	double	t;

	it = -1;
	while (++it <= fract->img.iter)
	{
		t = x;
		x = (x * x) - (y * y) + fract->img.c1;
		y = (2 * t * y) + fract->img.c2;
		if ((x * x) + (y * y) > 4)
			break ;
	}
	return (it);
}

void	draw_julia(t_screen_data *fract)
{
	int		i;
	double	a;
	double	b;

	fract->img.pos_y = -1;
	while (++fract->img.pos_y <= fract->img.max_y - 1)
	{
		fract->img.pos_x = -1;
		b = fract->img.max_val - (fract->img.pos_y / fract->img.size);
		while (++fract->img.pos_x <= fract->img.max_x - 1)
		{
			a = fract->img.min_val + (fract->img.pos_x / fract->img.size);
			i = calculate_julia(a, b, fract);
			color_to_mlx(fract->img, fract->img.pos_x, fract->img.pos_y,
				ft_color_julia(i));
		}
	}
}
