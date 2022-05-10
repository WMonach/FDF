/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:29:41 by wmonacho          #+#    #+#             */
/*   Updated: 2022/05/10 13:54:09 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rounded(float number1, float number2, t_fdf	*fdf)
{
	float	comma;
	int		temp;
	int		rounded_down;

	comma = 0.5;
	rounded_down = number1;
	temp = comma + number1;
	if (temp > rounded_down)
		fdf->temp.x1 = temp;
	else
		fdf->temp.x1 = rounded_down;
	rounded_down = number2;
	temp = comma + number2;
	if (temp > rounded_down)
		fdf->temp.y1 = temp;
	else
		fdf->temp.y1 = rounded_down;
}

float	ft_max(float max1, float max2)
{
	if (max1 > max2)
		return (max1);
	if (max1 < max2)
		return (max2);
	return (max1);
}

void	ft_bresenham(t_data *img, t_fdf *fdf, int colorx2)
{
	int	i;

	i = 0;
	while (i < fdf->pixel.max)
	{
		fdf->temp.x1 = fdf->pixel.x1 + (fdf->pixel.dx * i / fdf->pixel.max);
		fdf->temp.y1 = fdf->pixel.y1 + (fdf->pixel.dy * i / fdf->pixel.max);
		if (fdf->temp.x1 < 1919 && fdf->temp.y1 < 1079
			&& fdf->temp.x1 >= 0 && fdf->temp.y1 >= 0)
		{
			ft_rounded(fdf->temp.x1, fdf->temp.y1, fdf);
			my_mlx_pixel_put(img, (int)fdf->temp.x1,
				(int)fdf->temp.y1, ft_gradiant(fdf, colorx2));
		}
		i++;
	}
	fdf->pixel.a = 1;
	fdf->pixel.b = 1;
}

void	ft_name(t_data *img, t_fdf *fdf, int i, int j)
{
	fdf->colorx = fdf->map[i][j].colorx;
	if (j + 1 < fdf->x_max && i + 1 < fdf->y_max)
	{
		ft_formal_calculation(fdf, i, j, 1);
		ft_bresenham(img, fdf, fdf->map[i][j + 1].colorx);
		ft_formal_calculation(fdf, i, j, 2);
		ft_bresenham(img, fdf, fdf->map[i + 1][j].colorx);
	}
	if (j + 1 < fdf->x_max && i + 1 >= fdf->y_max)
	{
		ft_formal_calculation(fdf, i, j, 1);
		ft_bresenham(img, fdf, fdf->map[i][j + 1].colorx);
	}
	if (i + 1 < fdf->y_max && j + 1 >= fdf->x_max)
	{
		ft_formal_calculation(fdf, i, j, 2);
		ft_bresenham(img, fdf, fdf->map[i + 1][j].colorx);
	}
}

void	ft_formal_calculation(t_fdf *fdf, int i, int j, int mode)
{
	if (mode == 1)
	{
		fdf->pixel.x1 = fdf->dfault[i][j].x;
		fdf->pixel.x2 = fdf->dfault[i][j + 1].x;
		fdf->pixel.y2 = fdf->dfault[i][j + 1].y;
		fdf->pixel.y1 = fdf->dfault[i][j].y;
	}
	if (mode == 2)
	{
		fdf->pixel.x1 = fdf->dfault[i][j].x;
		fdf->pixel.x2 = fdf->dfault[i + 1][j].x;
		fdf->pixel.y2 = fdf->dfault[i + 1][j].y;
		fdf->pixel.y1 = fdf->dfault[i][j].y;
		// printf("fdf->pixel.x1 =%f\n", fdf->pixel.x1);
		// printf("fdf->pixel.x2 =%f\n", fdf->pixel.x2);
		// printf("fdf->pixel.y2 = %f\n", fdf->pixel.y2);
		// printf("fdf->pixel.y1 = %f\n", fdf->pixel.y1);
	}
	fdf->pixel.dx = (fdf->pixel.x2 - fdf->pixel.x1);
	fdf->pixel.dy = (fdf->pixel.y2 - fdf->pixel.y1);
	fdf->pixel.max = ft_max(fabsf(fdf->pixel.dx), fabsf(fdf->pixel.dy));
}

void	ft_draw(t_data *img, t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->y_max)
	{
		j = 0;
		while (j < fdf->x_max)
		{
			ft_name(img, fdf, i, j);
			j++;
		}
		i++;
	}
}
