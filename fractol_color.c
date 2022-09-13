/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krochefo <krochefo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 09:49:41 by krochefo          #+#    #+#             */
/*   Updated: 2022/09/13 06:02:06 by krochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	ft_color_mandel(int it)
{
	if ((it % 24) == 1 || (it % 24) == 2 || (it % 24) == 3 || (it % 24) == 19)
		return (create_trgb(0, 3, 150, 100));
	if ((it % 24) == 22 || (it % 24) == 5 || (it % 24) == 6 || (it % 24) == 20)
		return (create_trgb(0, 0, (63 + (63 * (it % 24 / 6))), 0));
	if ((it % 24) == 23 || (it % 24) == 8 || (it % 24) == 9 || (it % 24) == 21)
		return (create_trgb(0, 0, 222, 74));
	if ((it % 24) == 10 || (it % 24) == 11 || (it % 24) == 12 || (it % 24) == 4)
		return (create_trgb(0, 231, 242, 19));
	if ((it % 24) == 13 || (it % 24) == 14 || (it % 24) == 15 || (it % 24) == 7)
		return (create_trgb(0, 20, 141, 168));
	if ((it % 24) == 16 || (it % 24) == 17)
		return (create_trgb(0, 224, 139, 34));
	if ((it % 24) == 18 || (it % 24) == 0)
		return (create_trgb(0, 70, 12, 133));
	return (0);
}

int	ft_color_julia(int it)
{
	if ((it % 12) == 0 || (it % 12) == 6)
		return (create_trgb(0, 207, 19, 19));
	if ((it % 12) == 1 || (it % 12) == 7)
		return (create_trgb(0, 0, 0, 0));
	if ((it % 12) == 2 || (it % 12) == 8)
		return (create_trgb(0, 255, 166, 0));
	if ((it % 12) == 3 || (it % 12) == 9)
		return (create_trgb(0, 140, 140, 140));
	if ((it % 12) == 4 || (it % 12) == 10)
		return (create_trgb(0, 255, 0, 0));
	if ((it % 12) == 5 || (it % 12) == 11)
		return (create_trgb(0, 255, 255, 255));
	return (0);
}

unsigned int	get_color(t_img_data *img, int x, int y)
{
	char	*color;

	color = img->addr + (y * img->pixel + x * (img->bpp / 8));
	return (*(unsigned int *) color);
}
