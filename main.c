/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krochefo <krochefo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 09:28:01 by krochefo          #+#    #+#             */
/*   Updated: 2022/09/13 06:01:56 by krochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_screen_data	init_fractal(void)
{
	t_screen_data	fractal;

	fractal.img.pos_x = -1;
	fractal.img.pos_y = -1;
	fractal.img.size = 250;
	fractal.img.iter = 50;
	fractal.img.min_val = -2.5;
	fractal.img.max_val = 2.5;
	fractal.img.max_x = 1080;
	fractal.img.max_y = 720;
	fractal.img.offset_x = 0;
	fractal.img.offset_y = 0;
	fractal.img.zoom = 0.1;
	fractal.img.c1 = 0.45;
	fractal.img.c2 = 0.1428;
	fractal.mlx = mlx_init();
	fractal.win = mlx_new_window(fractal.mlx, 1080, 720, "Fractal");
	fractal.img.image = mlx_new_image(fractal.mlx, fractal.img.max_x,
			fractal.img.max_y);
	fractal.img.addr = mlx_get_data_addr(fractal.img.image, &fractal.img.bpp,
			&fractal.img.pixel, &fractal.img.end);
	return (fractal);
}

void	draw_fractal(t_screen_data *fract)
{
	if (fract->frac_type == mandelbrot)
		draw_mandel(fract->img);
	else if (fract->frac_type == julia)
		draw_julia(fract);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*r_s1;
	unsigned char	*r_s2;
	size_t			i;

	r_s1 = (unsigned char *) s1;
	r_s2 = (unsigned char *) s2;
	i = 0;
	while (n > 0 && (r_s1[i] != '\0' || r_s2[i] != '\0'))
	{
		if (r_s1[i] != r_s2[i])
			return (r_s1[i] - r_s2[i]);
		n--;
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_screen_data	fract;

	fract = init_fractal();
	if (argc == 2 && (ft_strncmp(argv[1], "Mandelbrot", 11) == 0))
		fract.frac_type = mandelbrot;
	else if (argc == 2 && (ft_strncmp(argv[1], "Julia", 6) == 0))
		fract.frac_type = julia;
	else if (argc == 4)
	{
		fract.img.c1 = ft_atof(argv[2]);
		fract.img.c2 = ft_atof(argv[3]);
	}
	else
		else_message(&fract);
	draw_fractal(&fract);
	mlx_put_image_to_window(fract.mlx, fract.win,
		fract.img.image, 0 + fract.img.offset_x, 0 + fract.img.offset_y);
	mlx_hook(fract.win, 17, 0, window_close, &fract);
	mlx_key_hook(fract.win, key_event, &fract);
	mlx_mouse_hook(fract.win, zoom_event, &fract);
	mlx_loop(fract.mlx);
}
