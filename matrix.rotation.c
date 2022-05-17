/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:53:17 by wmonacho          #+#    #+#             */
/*   Updated: 2022/05/17 16:01:20 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
faire les matrice de rotation sur tout les points et la matrice de projection
puis 
*/

void	ft_matrix(t_fdf *fdf, float teta, float delta)
{
	ft_matrix_rx(fdf, teta);
	ft_matrix_ry(fdf, delta);
	ft_set_data(fdf);
	ft_calibration(fdf);
}

void	ft_matrix_rx(t_fdf *fdf, float teta)
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
			fdf->map[i][j].y = save.y * cos(teta) - save.z * sin(teta);
			fdf->map[i][j].z = save.y * sin(teta) + save.z * cos(teta);
			j++;
		}
		i++;
	}
}

void	ft_matrix_ry(t_fdf *fdf, float delta)
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
			save.x = fdf->map[i][j].x;
			save.z = fdf->map[i][j].z;
			fdf->map[i][j].x = save.x * cos(delta) + save.z * sin(delta);
			fdf->map[i][j].z = -(save.x) * sin(delta) + save.z * cos(delta);
			j++;
		}
		i++;
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
