/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: will <will@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:16:24 by wmonacho          #+#    #+#             */
/*   Updated: 2022/05/26 14:34:36 by will             ###   ########lyon.fr   */
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
	// printf("distz=%f\n", fdf->map[i][j].z);
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

// int	ft_gradiant(t_fdf *fdf, int colorx2)
// {
// 	int	str;

// 	printf("ha\n");
// 	str = fdf->colorx;
// 	if (colorx2 > fdf->colorxtemp && fdf->colorxtemp >= 0x00ff00)
// 		return (ft_green_to_red(fdf));
// 	if (fdf->colorxtemp > colorx2 && colorx2 >= 0x00ff00)
// 		return (ft_red_to_green(fdf));
// 	if (fdf->colorxtemp > colorx2 && colorx2 >= 0x0000ff)
// 		return (ft_green_to_blue(fdf));
// 	if (colorx2 > fdf->colorxtemp && fdf->colorxtemp >= 0x0000ff)
// 		return (ft_blue_to_green(fdf));
// 	if (colorx2 > fdf->colorxtemp && fdf->colorxtemp >= 0x0000ff)
// 		return (ft_red_to_blue(fdf));
// 	if (colorx2 > fdf->colorxtemp && fdf->colorxtemp >= 0x0000ff)
// 		return (ft_blue_to_red(fdf));
// 	return (str);
// }

// int	ft_green_to_blue(t_fdf *fdf)
// {
// 	int	ecart;

// 	ecart = (0x00ffff - 0x00ff00) / (fdf->pixel.max / 2);
// 	if (fdf->start == 0)
// 		ecart = (0x00ffff - fdf->colorxtemp) / (fdf->pixel.max / 2);
// 	fdf->start = 1;
// 	if (fdf->pixel.a == 1)
// 	{
// 		if (fdf->colorx >= 0x00ffff)
// 		{
// 			fdf->pixel.a = 2;
// 			return (fdf->colorx);
// 		}
// 		fdf->colorx += ecart;
// 		return (fdf->colorx);
// 	}
// 	ecart = (0x00ffff - 0x0000ff) / (fdf->pixel.max / 2);
// 	if (fdf->pixel.a == 2)
// 	{
// 		if (fdf->colorx <= 0x0000ff)
// 		{
// 			fdf->pixel.a = 3;
// 			return (fdf->colorx);
// 		}
// 		fdf->colorx -= ecart;
// 		return (fdf->colorx);
// 	}
// 	return (fdf->colorx);
// }

// int	ft_blue_to_green(t_fdf *fdf)
// {
// 	int	ecart;

// 	ecart = (0x00ffff - 0x0000ff) / (fdf->pixel.max / 2);
// 	if (fdf->start == 0)
// 		ecart = (0x00ffff - fdf->colorxtemp) / (fdf->pixel.max / 2);
// 	fdf->start = 1;
// 	if (fdf->pixel.a == 1)
// 	{
// 		if (fdf->colorx >= 0x00ffff)
// 		{
// 			fdf->pixel.a = 2;
// 			return (fdf->colorx);
// 		}
// 		fdf->colorx += ecart;
// 		return (fdf->colorx);
// 	}
// 	ecart = (0x00ffff - 0x00ffff) / (fdf->pixel.max / 2);
// 	if (fdf->pixel.a == 2)
// 	{
// 		if (fdf->colorx <= 0x00ff00)
// 		{
// 			fdf->pixel.a = 3;
// 			return (fdf->colorx);
// 		}
// 		fdf->colorx -= ecart;
// 		return (fdf->colorx);
// 	}
// 	return (fdf->colorx);
// }

// int	ft_red_to_green(t_fdf *fdf)
// {
// 	int	ecart;

// 	ecart = (0xffff00 - 0xff0000) / (fdf->pixel.max / 2);
// 	if (fdf->start == 0)
// 		ecart = (0xffff00 - fdf->colorxtemp) / (fdf->pixel.max / 2);
// 	fdf->start = 1;
// 	if (fdf->pixel.a == 1)
// 	{
// 		if (fdf->colorx <= 0xffff00)
// 		{
// 			fdf->pixel.a = 2;
// 			return (fdf->colorx);
// 		}
// 		fdf->colorx += ecart;
// 		return (fdf->colorx);
// 	}
// 	ecart = (0xffff00 - 0x00ff00) / (fdf->pixel.max / 2);
// 	if (fdf->pixel.a == 2)
// 	{
// 		if (fdf->colorx <= 0x00ff00)
// 		{
// 			fdf->pixel.a = 3;
// 			return (fdf->colorx);
// 		}
// 		fdf->colorx -= ecart;
// 		return (fdf->colorx);
// 	}
// 	return (fdf->colorx);
// }

// int	ft_green_to_red(t_fdf *fdf)
// {
// 	int	ecart;

// 	ecart = (0xffff00 - 0x00ff00) / (fdf->pixel.max / 2);
// 	if (fdf->start == 0)
// 		ecart = (0xffff00 - fdf->colorxtemp) / (fdf->pixel.max / 2);
// 	fdf->start = 1;
// 	if (fdf->pixel.a == 1)
// 	{
// 		if (fdf->colorx >= 0xffff00)
// 		{
// 			fdf->pixel.a = 2;
// 			return (fdf->colorx);
// 		}
// 		fdf->colorx += ecart;
// 		return (fdf->colorx);
// 	}
// 	ecart = (0xffff00 - 0xff0000) / (fdf->pixel.max / 2);
// 	if (fdf->pixel.a == 2)
// 	{
// 		if (fdf->colorx <= 0xff0000)
// 		{
// 			fdf->pixel.a = 3;
// 			return (fdf->colorx);
// 		}
// 		fdf->colorx -= ecart;
// 		return (fdf->colorx);
// 	}
// 	return (fdf->colorx);
// }

// int	ft_blue_to_red(t_fdf *fdf)
// {
// 	if (fdf->pixel.b == 1)
// 	{
// 		printf("ha\n");
// 		if (fdf->pixel.a == 3)
// 			fdf->pixel.b = 2;
// 		return (ft_blue_to_green(fdf));
// 	}
// 	if (fdf->pixel.b == 2)
// 	{
// 		return (ft_green_to_red(fdf));
// 	}
// 	return (fdf->colorx);
// }

// int	ft_red_to_blue(t_fdf *fdf)
// {
// 	if (fdf->pixel.b == 1)
// 	{
// 		printf("ha\n");
// 		if (fdf->pixel.a == 3)
// 			fdf->pixel.b = 2;
// 		return (ft_red_to_green(fdf));
// 	}
// 	if (fdf->pixel.b == 2)
// 	{
// 		return (ft_green_to_blue(fdf));
// 	}
// 	return (fdf->colorx);
// }
