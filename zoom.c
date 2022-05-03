/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 10:46:40 by wmonacho          #+#    #+#             */
/*   Updated: 2022/05/03 16:10:17 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	ft_zoom_nw(t_fdf *fdf, int i, int j)
// {
// 	fdf->map[i][j].x = fdf->map[i][j].x * 0.95;
// 	fdf->map[i][j].y = fdf->map[i][j].y * 0.95;
// }

// void	ft_zoom_ne(t_fdf *fdf, int i, int j)
// {
// 	fdf->map[i][j].x = fdf->map[i][j].x * 1.05;
// 	fdf->map[i][j].y = fdf->map[i][j].y * 0.95;
// }

// void	ft_zoom_sw(t_fdf *fdf, int i, int j)
// {
// 	fdf->map[i][j].x = fdf->map[i][j].x * 0.95;
// 	fdf->map[i][j].y = fdf->map[i][j].y * 1.05;
// }

// void	ft_zoom_se(t_fdf *fdf, int i, int j)
// {
// 	fdf->map[i][j].x = fdf->map[i][j].x * 1.05;
// 	fdf->map[i][j].y = fdf->map[i][j].y * 1.05;
// }

// void	ft_zoom(t_fdf *fdf)
// {
// 	int		i;
// 	int		j;

// 	i = 0;
// 	while (i < fdf->y_max)
// 	{
// 		j = 0;
// 		while (j < fdf->x_max)
// 		{
// 			if (fdf->map[i][j].x < 1920 / 2 && fdf->map[i][j].y < 1080 / 2)
// 				ft_zoom_nw(fdf, i, j);
// 			else if (fdf->map[i][j].x > 1920 / 2 && fdf->map[i][j].y < 1080 / 2)
// 				ft_zoom_ne(fdf, i, j);
// 			else if (fdf->map[i][j].x < 1920 / 2 && fdf->map[i][j].y > 1080 / 2)
// 				ft_zoom_sw(fdf, i, j);
// 			else if (fdf->map[i][j].x > 1920 / 2 && fdf->map[i][j].y > 1080 / 2)
// 				ft_zoom_se(fdf, i, j);
// 			j++;
// 		}
// 		i++;
// 	}
// }

void	ft_calibration_zoom(t_fdf *fdf)
{
	int		i;
	int		j;
	float	xl;
	float	yl;
	float	zl;

	i = -1;
	xl = fdf->x_mat / 2.00;
	yl = fdf->y_mat / 2.00;
	zl = fdf->z_max / 2.00;
	while (++i < fdf->y_max)
	{
		j = -1;
		while (++j < fdf->x_max)
		{
			fdf->map[i][j].x = fdf->map[i][j].x * 1.05 + (xl * (1 - 1.05));
			fdf->map[i][j].y = fdf->map[i][j].y * 1.05 + (yl * (1 - 1.05));
			fdf->map[i][j].z = fdf->map[i][j].z * 1.05 + (zl * (1 - 1.05));
			// printf("map[%d][%d].x=%f\n", i, j, fdf->map[i][j].x);
			// printf("map[%d][%d].y=%f\n", i, j, fdf->map[i][j].y);
			// printf("map[%d][%d].z=%f\n", i, j, fdf->map[i][j].z);
		}
	}
	ft_set_up_mat(fdf);
}

void	ft_calibration_dezoom(t_fdf *fdf)
{
	int		i;
	int		j;
	float	xl;
	float	yl;
	float	zl;

	i = -1;
	xl = fdf->x_mat / 2.00;
	yl = fdf->y_mat / 2.00;
	zl = fdf->z_max / 2.00;
	while (++i < fdf->y_max)
	{
		j = -1;
		while (++j < fdf->x_max)
		{
			fdf->map[i][j].x = fdf->map[i][j].x * 0.95 + (xl * (1 - 0.95));
			fdf->map[i][j].y = fdf->map[i][j].y * 0.95 + (yl * (1 - 0.95));
			fdf->map[i][j].z = fdf->map[i][j].z * 0.95 + (zl * (1 - 0.95));
			// printf("map[%d][%d].x=%f\n", i, j, fdf->map[i][j].x);
			// printf("map[%d][%d].y=%f\n", i, j, fdf->map[i][j].y);
			// printf("map[%d][%d].z=%f\n", i, j, fdf->map[i][j].z);
		}
	}
	ft_set_up_mat(fdf);
}

void	ft_set_up_mat(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->y_max)
	{
		j = 0;
		while (j < fdf->x_max)
		{
			if (fdf->map[i][j].x > fdf->x_mat)
				fdf->x_mat = fdf->map[i][j].x;
			if (fdf->map[i][j].y > fdf->y_mat)
				fdf->y_mat = fdf->map[i][j].y;
			if (fdf->map[i][j].z > fdf->z_max)
				fdf->z_max = fdf->map[i][j].z;
			j++;
		}
		i++;
	}
}
