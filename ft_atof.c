/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krochefo <krochefo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 13:53:43 by jgagnon           #+#    #+#             */
/*   Updated: 2022/08/31 06:26:40 by krochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

double	ft_atoi(const char *str)
{
	double			nb;
	int				i;
	int				signe;

	nb = 0;
	i = 0;
	signe = 1;
	while ((str[i] >= 0x09 && str[i] <= 0x0d) || str[i] == 0x20)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (str[i] == '-' || str[i] == '+')
			return (0);
		nb = (nb * 10) + (str[i] - 0x30);
		i++;
	}
	return (nb * signe);
}

double	ft_atof(const char *str)
{
	double	res;
	double	res2;
	char	*c;
	int		len;

	c = (char *)str;
	res = (double)ft_atoi(c);
	while (*c && *c != '.')
		c++;
	if (*c == '.')
		c++;
	res2 = (double)ft_atoi(c);
	len = ft_strlen(c);
	while (len--)
		res2 /= 10;
	if (res < 0 || res == -0)
		res2 *= -1;
	return (res + res2);
}
