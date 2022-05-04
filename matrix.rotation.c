/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:53:17 by wmonacho          #+#    #+#             */
/*   Updated: 2022/05/04 16:47:49 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
faire les matrice de rotation sur tout les points et la matrice de projection
puis 
*/

float	ft_calculate_diffinv(float ratio_x, float ratio_y)
{
	if (ratio_x >= ratio_y)
	{
		return (ratio_x);
	}
	if (ratio_x <= ratio_y)
	{
		return (ratio_y);
	}
	return (1);
}

void	ft_calibrate_z(t_fdf *fdf)
{
	float	compare;
	int		i;
	int		j;

	i = -1;
	compare = ft_calculate_diffinv(fdf->x_max, fdf->y_max);
	while (++i < fdf->y_max)
	{
		j = -1;
		while (++j < fdf->x_max)
		{
			if (fdf->map[i][j].z != 0 && fdf->z_max >= compare / 2)
			{
				if (fdf->z_max >= compare * 2)
					fdf->map[i][j].z = fdf->map[i][j].z / ((fdf->z_max / compare) * 4);
				if (fdf->z_max < compare * 2)
					fdf->map[i][j].z = fdf->map[i][j].z / ((compare / fdf->z_max) * 4);
			}
		}
	}
	ft_set_up_mat(fdf);
}

void	ft_matrix(t_fdf *fdf)
{
	ft_calibrate_z(fdf);
	ft_set_data(fdf);
	ft_matrix_rx(fdf);
	ft_matrix_ry(fdf);
	ft_matrix_projection(fdf);
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
			// fdf->map[i][j].z = 0;
			// printf("map[%d][%d].x=%f\n", i, j, fdf->map[i][j].x);
			// printf("map[%d][%d].y=%f\n", i, j, fdf->map[i][j].y);
			j++;
		}
		i++;
	}
}

float	ft_calculate_diff(float ratio_x, float ratio_y)
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

	i = -1;
	ratio_x = (1920) / (fdf->x_max - 1) / 2;
	ratio_y = (1080) / (fdf->y_max - 1) / 2;
	ratio = ft_calculate_diff(ratio_x, ratio_y);
	printf("ratio=%f\n", ratio_y);
	printf("ratio=%f\n", ratio_x);
	// printf("ratio=%f\n", ratio);
	while (++i < fdf->y_max)
	{
		j = -1;
		while (++j < fdf->x_max)
		{
			fdf->map[i][j].x = fdf->map[i][j].x + 960;
			fdf->map[i][j].y = fdf->map[i][j].y + 540;
			fdf->map[i][j].x = fdf->map[i][j].x * ratio + (960 * (1 - ratio));
			fdf->map[i][j].y = fdf->map[i][j].y * ratio + (540 * (1 - ratio));
		}
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
			fdf->map[i][j].y = (fdf->map[i][j].y * cos(TETA * fdf->rotx)) - (fdf->map[i][j].z * sin(TETA * fdf->rotx));
			fdf->map[i][j].z = fdf->map[i][j].y * sin(TETA * fdf->rotx) + fdf->map[i][j].z * cos(TETA * fdf->rotx);
			// printf("map[%d][%d].x=%f\n", i, j, fdf->map[i][j].x);
			// printf("map[%d][%d].y=%f\n", i, j, fdf->map[i][j].y);
			// printf("map[%d][%d].z=%f\n", i, j, fdf->map[i][j].z);
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
	fdf->x_mat = 0;
	while (i < fdf->y_max)
	{
		j = 0;
		while (j < fdf->x_max)
		{
			fdf->map[i][j].x = fdf->map[i][j].x * cos(TETA * fdf->roty)
				+ fdf->map[i][j].z * sin(TETA * fdf->roty);
			if (fdf->map[i][j].x > fdf->x_mat)
				fdf->x_mat = fdf->map[i][j].x;
			fdf->map[i][j].z = -(fdf->map[i][j].x) * sin(TETA * fdf->roty)
				+ fdf->map[i][j].z * cos(TETA * fdf->roty);
			j++;
		}
		i++;
	}
	ft_set_up_mat(fdf);
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
	ft_set_up_mat(fdf);
}

void	ft_move_right(t_fdf *fdf)
{
	int	i;
	int	j;

	i = -1;
	while (++i < fdf->y_max)
	{
		j = -1;
		while (++j < fdf->x_max)
		{
			fdf->map[i][j].x = fdf->map[i][j].x - 30;
		}
	}
	ft_set_up_mat(fdf);
}

void	ft_move_left(t_fdf *fdf)
{
	int	i;
	int	j;

	i = -1;
	while (++i < fdf->y_max)
	{
		j = -1;
		while (++j < fdf->x_max)
		{
			fdf->map[i][j].x = fdf->map[i][j].x + 30;
		}
	}
	ft_set_up_mat(fdf);
}

void	ft_move_down(t_fdf *fdf)
{
	int	i;
	int	j;

	i = -1;
	while (++i < fdf->y_max)
	{
		j = -1;
		while (++j < fdf->x_max)
		{
			fdf->map[i][j].y = fdf->map[i][j].y + 30;
		}
	}
	ft_set_up_mat(fdf);
}

void	ft_move_up(t_fdf *fdf)
{
	int	i;
	int	j;

	i = -1;
	while (++i < fdf->y_max)
	{
		j = -1;
		while (++j < fdf->x_max)
		{
			fdf->map[i][j].y = fdf->map[i][j].y - 30;
		}
	}
	ft_set_up_mat(fdf);
}

void	ft_set_data(t_fdf *fdf)
{
	int	i;
	int	j;

	i = -1;
	fdf->dfault = (t_default **)malloc(sizeof(t_default *) * (fdf->y_max));
	while (i < fdf->y_max)
		fdf->dfault[i++] = (t_default *)malloc(sizeof(t_default) * (fdf->x_max));
	while (++i < fdf->y_max)
	{
		j = -1;
		while (++j < fdf->x_max)
		{
			fdf->dfault[i][j].x = fdf->map[i][j].x;
			fdf->dfault[i][j].y = fdf->map[i][j].y;
			fdf->dfault[i][j].z = fdf->map[i][j].z;
		}
	}
}

