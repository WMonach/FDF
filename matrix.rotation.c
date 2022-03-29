/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:53:17 by wmonacho          #+#    #+#             */
/*   Updated: 2022/03/29 18:12:23 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
faire les matrice de rotation sur tout les points et la matrice de projection
puis 
*/
void	ft_matrix(t_fdf *fdf)
{
	ft_matrix_rx(fdf);
	// ft_matrix_ry(fdf);
	// ft_matrix_rz(fdf);
	ft_matrix_projection(fdf);
}

void	ft_matrix_projection(t_fdf *fdf)
{
	int		i;
	int		j;
	float	x;
	float	y;
	float	z;

	i = 0;
	while (i < fdf->map[0]->y_max)
	{
		i++;
		j = 0;
		while (j < fdf->map[0]->x_max)
		{
			fdf->map[i][j].x = x;
			fdf->map[i][j].y = y;
			fdf->map[i][j].z = z;
			x = x;
			y = y;
			z = 0;
			j++;
		}
	}
}

int	ft_calculate_ratio(int ratio, int ratio_x, int ratio_y, t_fdf *fdf)
{
	if (ratio_x >= ratio_y)
	{
		if (ratio_y >= ratio)
			return (ratio);
		else
			return (ratio_y);
	}
	if (ratio_x <= ratio_y)
	{
		if (ratio_x >= ratio)
			return (ratio);
		else
			return (ratio_x);
	}
	return (ratio);
}

void	ft_calibration(t_fdf *fdf, int ratio_x, int ratio_y, int ratio)
{
	int		i;
	int		j;
	float	x;
	float	y;
	float	z;

	i = -1;
	ratio_x = 1920 / fdf->map[0]->x_max;
	ratio_y = 1080 / fdf->map[0]->y_max;
	ratio = 1080 / fdf->map[0]->z_max;
	ratio = ft_calculate_ratio(ratio, ratio_x, ratio_y, fdf);
	while (++i < fdf->map[0]->y_max)
	{
		j = -1;
		while (++j < fdf->map[0]->x_max)
		{
			fdf->map[i][j].x = x;
			fdf->map[i][j].y = y;
			fdf->map[i][j].z = z;
			x = x * ratio;
			y = y * ratio;
			z = z * ratio;
		}
	}
}

void	ft_zoom(t_fdf *fdf, int zoom)
{
	int		i;
	int		j;
	float	x;
	float	y;
	float	z;

	i = 0;
	while (i < fdf->map[0]->y_max)
	{
		i++;
		j = 0;
		while (j < fdf->map[0]->x_max)
		{
			fdf->map[i][j].x = x;
			fdf->map[i][j].y = y;
			fdf->map[i][j].z = z;
			x = x * zoom;
			y = y * zoom;
			z = z * zoom;
			j++;
		}
	}
}

void	ft_matrix_rx(t_fdf *fdf)
{
	int		i;
	int		j;
	float	y;
	float	z;

	i = 0;
	while (i < fdf->map[0]->y_max)
	{
		i++;
		j = 0;
		while (j < fdf->map[0]->x_max)
		{
			fdf->map[i][j].y = y;
			fdf->map[i][j].z = z;
			y = y * cos(TETA) - y * sin(TETA);
			z = z * sin(TETA) + z * cos(TETA);
			j++;
		}
	}
}

void	ft_matrix_ry(t_fdf *fdf)
{
	int		i;
	int		j;
	float	x;
	float	z;

	i = 0;
	while (i < fdf->map[0]->y_max)
	{
		i++;
		j = 0;
		while (j < fdf->map[0]->x_max)
		{
			fdf->map[i][j].x = x;
			fdf->map[i][j].z = z;
			x = x * cos(TETA) + x * sin(TETA);
			z = -z * sin(TETA) + z * cos(TETA);
			j++;
		}
	}
}

void	ft_matrix_rz(t_fdf *fdf)
{
	int		i;
	int		j;
	float	x;
	float	y;

	i = 0;
	while (i < fdf->map[0]->y_max)
	{
		i++;
		j = 0;
		while (j < fdf->map[0]->x_max)
		{
			fdf->map[i][j].y = y;
			fdf->map[i][j].x = x;
			x = x * cos(TETA) - x * sin(TETA);
			y = y * sin(TETA) + y * cos(TETA);
			j++;
		}
	}
}
