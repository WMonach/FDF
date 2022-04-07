/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:53:17 by wmonacho          #+#    #+#             */
/*   Updated: 2022/04/07 16:45:47 by wmonacho         ###   ########lyon.fr   */
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
	ft_matrix_ry(fdf);
	ft_matrix_projection(fdf);
	//ft_matrix_rz(fdf);
	ft_calibration(fdf, 0, 0, 0);
}

void	ft_matrix_projection(t_fdf *fdf)
{
	int		i;
	int		j;

	i = 0;
	while (i < fdf->y_max)
	{
		j = 0;
		while (j < fdf->x_max)
		{
			fdf->map[i][j].z = 0;
			j++;
		}
		i++;
	}
}

float	ft_calculate_ratio(float ratio_x, float ratio_y)
{
	if (ratio_x >= ratio_y)
	{
		return (ratio_y);
	}
	if (ratio_x <= ratio_y)
	{
		return (ratio_x);
	}
	return (1);
}

void	ft_calibration(t_fdf *fdf, float ratio_x, float ratio_y, float ratio)
{
	int		i;
	int		j;
	float	x;
	float	y;

	i = -1;
	ratio_x = (1919) / ((fdf->x_max) - 1);
	ratio_y = (1079) / (fdf->y_max - 1);
	// printf("ratio=%f\n", ratio_y);
	// printf("ratio=%f\n", ratio_x);
	printf("fdf->x_max=%f\n", fdf->x_max);
	printf("fdf->y_max=%f\n", fdf->y_max);
	ratio = ft_calculate_ratio(ratio_x, ratio_y);
	// printf("ratio=%f\n", ratio);
	while (++i < fdf->y_max)
	{
		j = -1;
		while (++j < fdf->x_max)
		{
			x = fdf->map[i][j].x;
			y = fdf->map[i][j].y;
			fdf->map[i][j].x = x * ratio;
			fdf->map[i][j].y = y * ratio;
			// printf("map[%d][%d].x=%f\n", i, j, fdf->map[i][j].x);
			// printf("map[%d][%d].y=%f\n", i, j, fdf->map[i][j].y);
			// printf("map[%d][%d].z=%f\n", i, j, fdf->map[i][j].z);
		}
	}
}

void	ft_zoom(t_fdf *fdf, int zoom)
{
	int		i;
	int		j;

	i = 0;
	while (i < fdf->y_max)
	{
		j = 0;
		while (j < fdf->x_max)
		{
			fdf->map[i][j].x = fdf->map[i][j].x * zoom;
			fdf->map[i][j].y = fdf->map[i][j].y * zoom;
			fdf->map[i][j].z = fdf->map[i][j].z * zoom;
			j++;
		}
		i++;
	}
}

void	ft_matrix_rx(t_fdf *fdf)
{
	int		i;
	int		j;

	i = 0;
	while (i < fdf->y_max)
	{
		j = 0;
		while (j < fdf->x_max)
		{
			fdf->map[i][j].y = fdf->map[i][j].y * cos(TETA)
				- fdf->map[i][j].z * sin(TETA);
			fdf->map[i][j].z = fdf->map[i][j].y * sin(TETA)
				+ fdf->map[i][j].z * cos(TETA);
			j++;
		}
		i++;
	}
}

void	ft_matrix_ry(t_fdf *fdf)
{
	int		i;
	int		j;

	i = 0;
	while (i < fdf->y_max)
	{
		j = 0;
		while (j < fdf->x_max)
		{
			fdf->map[i][j].x = fdf->map[i][j].x * cos(TETA)
				+ fdf->map[i][j].z * sin(TETA);
			fdf->map[i][j].z = -(fdf->map[i][j].x) * sin(TETA)
				+ fdf->map[i][j].z * cos(TETA);
			j++;
		}
		i++;
	}
}

void	ft_matrix_rz(t_fdf *fdf)
{
	int		i;
	int		j;

	i = 0;
	while (i < fdf->y_max)
	{
		j = 0;
		while (j < fdf->x_max)
		{
			fdf->map[i][j].x = fdf->map[i][j].x * cos(TETA)
				- fdf->map[i][j].y * sin(TETA);
			fdf->map[i][j].y = fdf->map[i][j].x * sin(TETA)
				+ fdf->map[i][j].y * cos(TETA);
			j++;
		}
		i++;
	}
}
