/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 10:46:40 by wmonacho          #+#    #+#             */
/*   Updated: 2022/04/15 15:37:19 by wmonacho         ###   ########lyon.fr   */
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

void	ft_calibration_zoom(t_fdf *fdf, float ratio_x, float ratio_y, float ratio)
{
	int		i;
	int		j;
	float	xl;
	float	yl;

	i = -1;
	xl = 0;
	yl = 0;
	fdf->lgnmax = fdf->lgnmax;
	ratio_x = (fdf->lgnmax) / ((fdf->x_mat) - 1) / 1.5;
	ratio_y = (fdf->latmax) / (fdf->y_mat - 1) / 1.5;
	// printf("ratio=%f\n", ratio_y);
	// printf("ratio=%f\n", ratio_x);
	ratio = ft_calculate_diff(ratio_x, ratio_y);
	// printf("ratio=%f\n", ratio);
	mlx_mouse_get_pos(fdf->vars.win, xl, yl);
	while (++i < fdf->y_max)
	{
		j = -1;
		while (++j < fdf->x_max)
		{
			fdf->map[i][j].x = fdf->map[i][j].x * 1.05 + (xl * (1 - 1.05));
			if (fdf->map[i][j].x > fdf->x_mat)
				fdf->x_mat = fdf->map[i][j].x;
			fdf->map[i][j].y = fdf->map[i][j].y * 1.05 + (yl * (1 - 1.05));
			if (fdf->map[i][j].y > fdf->y_mat)
				fdf->y_mat = fdf->map[i][j].y;
			// printf("map[%d][%d].x=%f\n", i, j, fdf->map[i][j].x);
			// printf("map[%d][%d].y=%f\n", i, j, fdf->map[i][j].y);
			// printf("map[%d][%d].z=%f\n", i, j, fdf->map[i][j].z);
		}
	}
	//ft_set_up_mat(fdf);
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
			j++;
		}
	}
}
