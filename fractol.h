/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krochefo <krochefo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:34:39 by krochefo          #+#    #+#             */
/*   Updated: 2022/09/13 06:02:01 by krochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <mlx.h>
# include<math.h>

enum {
	UP = 126,
	LEFT = 123,
	DOWN = 125,
	RIGHT = 124,
	ESC = 53,
	SCROLLUP = 4,
	SCROLLDOWN = 5,
	WKEY = 13,
	AKEY = 0,
	SKEY = 1,
	DKEY = 2,
};

enum e_set	{mandelbrot, julia};

typedef struct image_var
{
	void			*image;
	char			*addr;
	int				bpp;
	int				pixel;
	int				end;
	int				iter;
	long double		max_x;
	long double		max_y;
	long double		pos_x;
	long double		pos_y;
	long double		x;
	long double		y;
	long double		size;
	long double		max_val;
	long double		min_val;
	long double		offset_x;
	long double		offset_y;
	long double		zoom;
	double			c1;
	double			c2;
}	t_img_data;

typedef struct screen_var
{
	t_img_data		img;
	t_img_data		bgd;
	void			*mlx;
	void			*win;
	int				zoom;
	enum e_set		frac_type;

}	t_screen_data;

void				draw_mandel(t_img_data img);
void				draw_julia(t_screen_data *fract);
void				zoom_value(t_screen_data *fract);
void				update_fract(t_screen_data *fract);
void				draw_fractal(t_screen_data *fract);
void				else_message(t_screen_data *fract);
void				color_to_mlx(t_img_data img, int x, int y, int color);

double				ft_atoi(const char *str);
int					ft_color_julia(int it);
int					ft_color_mandel(int it);
double				ft_atof(const char *str);
int					window_close(t_screen_data *fract);
int					create_trgb(int t, int r, int g, int b);
int					key_event(int key, t_screen_data *fract);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					zoom_event(int mouse, int x, int y, t_screen_data *fract);

unsigned int		get_color(t_img_data *img, int x, int y);

t_screen_data		init_mandel(void);
t_screen_data		init_fractal(void);

#endif
