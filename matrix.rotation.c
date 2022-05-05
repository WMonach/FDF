/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:53:17 by wmonacho          #+#    #+#             */
/*   Updated: 2022/05/05 17:15:43 by wmonacho         ###   ########lyon.fr   */
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
	i = 0;
	fdf->dfault = (t_default **)malloc(sizeof(t_default *) * (fdf->y_max));
	while (i < fdf->y_max)
		fdf->dfault[i++] = (t_default *)malloc(sizeof(t_default) * (fdf->x_max));
}

void	ft_matrix(t_fdf *fdf, teta , delta)
{
	//ft_calibrate_z(fdf);
	ft_matrix_rx(fdf);
	ft_matrix_ry(fdf);
	ft_set_data(fdf);
	ft_calibration(fdf, 0, 0, 0);
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
	//ratio_x = (1920) / (fdf->x_max - 1) / 2;
	//ratio_y = (1080) / (fdf->y_max - 1) / 2;
	//ratio = ft_calculate_diff(ratio_x, ratio_y);
	// printf("ratio=%f\n", ratio_y);
	// printf("ratio=%f\n", ratio_x);
	// printf("ratio=%f\n", ratio);
	while (++i < fdf->y_max)
	{
		j = -1;
		while (++j < fdf->x_max)
		{
			fdf->dfault[i][j].x = fdf->dfault[i][j].x * fdf->dist;
			fdf->dfault[i][j].y = fdf->dfault[i][j].y * fdf->dist;
			fdf->dfault[i][j].x = fdf->dfault[i][j].x += fdf->posx;
			fdf->dfault[i][j].y = fdf->dfault[i][j].y += fdf->posy;
			// printf("calibration[%d][%d].x=%f\n", i, j, fdf->map[i][j].x);
			// printf("calibration[%d][%d].y=%f\n", i, j, fdf->map[i][j].y);
			// printf("calibration[%d][%d].z=%f\n", i, j, fdf->map[i][j].z);
		}
	}
}

void	ft_matrix_rx(t_fdf *fdf)
{
	int		i;
	int		j;
	t_point	save;

	i = 0;
	while (i < fdf->y_max)
	{
		j = 0;
		while (j < fdf->x_max)
		{
			save.y = fdf->map[i][j].y;
			save.z = fdf->map[i][j].z;
			fdf->map[i][j].y = save.y * cos(TETA) - save.z * sin(TETA);
			fdf->map[i][j].z = save.y * sin(TETA) + save.z * cos(TETA);
			// printf("map[%d][%d].x=%f\n", i, j, fdf->map[i][j].x);
			// printf("map[%d][%d].y=%f\n", i, j, fdf->map[i][j].y);
			// printf("map[%d][%d].z=%f\n", i, j, fdf->map[i][j].z);
			/**/
			j++;
		}
		i++;
	}
}

void	ft_matrix_ry(t_fdf *fdf)
{
	int		i;
	int		j;
	t_point	save;

	i = 0;
	fdf->x_mat = 0;
	while (i < fdf->y_max)
	{
		j = 0;
		while (j < fdf->x_max)
		{
			save.x = fdf->map[i][j].x;
			save.z = fdf->map[i][j].z;
			fdf->map[i][j].x = save.x * cos(TETA) + save.z * sin(TETA);
			fdf->map[i][j].z = -(save.x) * sin(TETA) + save.z * cos(TETA);
			j++;
		}
		i++;
	}
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
}

void	ft_set_data(t_fdf *fdf)
{
	int	i;
	int	j;

	i = -1;
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

void	ft_set_invdata(t_fdf *fdf)
{
	int	i;
	int	j;

	i = -1;
	while (++i < fdf->y_max)
	{
		j = -1;
		while (++j < fdf->x_max)
		{
			fdf->map[i][j].x = fdf->dfault[i][j].x;
			fdf->map[i][j].y = fdf->dfault[i][j].y;
			fdf->map[i][j].z = fdf->dfault[i][j].z;
		}
	}
}
