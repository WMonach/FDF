/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:16:24 by wmonacho          #+#    #+#             */
/*   Updated: 2022/05/06 16:59:29 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_fill_rgb(t_fdf *fdf)
{
	int		str;
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
	}
	str = 0xff00ff;
	return (str);
}

int	ft_rgb(t_fdf *fdf, int i, int j)
{
	int		str;

	if (fdf->map[i][j].z < fdf->distz / 4)
	{
		fdf->map[i][j].colorx = 0xff00ff;
		fdf->map[i][j].colory = 0xff00ff;
	}
	fdf->x_max += 0;
	str = 0xff00ff;
	return (str);
}
