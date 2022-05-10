/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:16:24 by wmonacho          #+#    #+#             */
/*   Updated: 2022/05/10 13:56:37 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fill_rgb(t_fdf *fdf)
{
	int		i;
	int		j;

	i = 0;
	fdf->distz = fdf->z_max - fdf->z_min;
	while (i < fdf->y_max)
	{
		j = 0;
		while (j < fdf->x_max)
		{
			ft_rgb(fdf, i, j);
			j++;
		}
		i++;
	}
}

void	ft_rgb(t_fdf *fdf, int i, int j)
{
	if (fdf->map[i][j].z <= fdf->distz / 3)
	{
		fdf->map[i][j].colorx = 0x0000ff;
		fdf->map[i][j].colory = 0x0000ff;
	}
	if (fdf->map[i][j].z > fdf->distz / 3
		&& fdf->map[i][j].z <= (fdf->distz / 3) * 2)
	{
		fdf->map[i][j].colorx = 0x00ff00;
		fdf->map[i][j].colory = 0x00ff00;
	}
	if (fdf->map[i][j].z > (fdf->distz / 3) * 2
		&& fdf->map[i][j].z <= fdf->distz)
	{
		fdf->map[i][j].colorx = 0xff0000;
		fdf->map[i][j].colory = 0xff0000;
	}
}

int	ft_gradiant(t_fdf *fdf, int colorx2)
{
	int	str;

	str = fdf->colorx;
	// if (colorx2 > colorx && colorx >= 0x00ff00)
	// 	return (ft_green_to_red(fdf));
	// if (fdf->colorx > colorx2 && colorx2 >= 0x00ff00)
	// 	return (ft_red_to_green(fdf));
	// if (fdf->colorx > colorx2 && colorx2 >= 0x0000ff)
	// 	return (ft_green_to_blue(fdf));
	// if (colorx2 > colorx && colorx >= 0x0000ff)
	// 	return (ft_blue_to_green(fdf));
	if (colorx2 > fdf->colorx && fdf->colorx >= 0x0000ff)
		return (ft_red_to_blue(fdf));
	// if (colorx2 > colorx && colorx >= 0x0000ff)
	// 	return (ft_blue_to_red(fdf));
	return (str);
}

int	ft_green_to_blue(t_fdf *fdf)
{
	int	ecart;

	ecart = 0x0000ff / (fdf->pixel.max / 2);
	if (fdf->pixel.a == 1)
	{
		if (fdf->colorx >= 0x00ffff)
			fdf->pixel.a = 2;
		fdf->colorx += ecart;
		return (fdf->colorx);
	}
	ecart = 0x00ff00 / (fdf->pixel.max / 2);
	if (fdf->pixel.a == 2)
	{
		fdf->colorx -= ecart;
		return (fdf->colorx);
	}
	return (fdf->colorx);
}

// int	ft_blue_to_green(t_fdf *fdf, int colorx2, int colorx)
// {
// }

int	ft_red_to_green(t_fdf *fdf)
{
	int	ecart;

	ecart = 0x00ff00 / (fdf->pixel.max / 2);
	printf("%d\n", ecart);
	if (fdf->pixel.a == 1)
	{
		if (fdf->colorx >= 0xffff00)
			fdf->pixel.a = 2;
		fdf->colorx += ecart;
		return (fdf->colorx);
	}
	ecart = 0xff0000 / (fdf->pixel.max / 2);
	if (fdf->pixel.a == 2)
	{
		fdf->colorx -= ecart;
		if (fdf->colorx <= 0x00ff00)
			fdf->pixel.a = 2;
		return (fdf->colorx);
	}
	return (fdf->colorx);
}

// int	ft_green_to_red(t_fdf *fdf, int colorx2, int colorx)
// {
// }

// int	ft_blue_to_red(t_fdf *fdf, int colorx2, int colorx)
// {
// }

int	ft_red_to_blue(t_fdf *fdf)
{
	// if (fdf->pixel.b == 1)
	// {
	// 	if (fdf->colorx <= 0x00ff00)
	// 		fdf->pixel.b = 2;
	// 	return (ft_red_to_green(fdf));
	// }
	// if (fdf->pixel.b == 2)
	// {
	// 	return (ft_green_to_blue(fdf));
	// }
	// return (fdf->colorx);
	return (ft_red_to_green(fdf));
}
// /*
// la il me faut un truc qui selon le point x1 et x2 je change de couleur 
// */