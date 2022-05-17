/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:23:17 by wmonacho          #+#    #+#             */
/*   Updated: 2022/05/17 13:23:17 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_keyhook_translation(int keycode, t_fdf *fdf)
{
	if (keycode == 125)
	{
		fdf->posy += 15;
		ft_matrix(fdf, 0, 0);
	}
	if (keycode == 126)
	{
		fdf->posy -= 15;
		ft_matrix(fdf, 0, 0);
	}
	if (keycode == 124)
	{
		fdf->posx -= 15;
		ft_matrix(fdf, 0, 0);
	}
	if (keycode == 123)
	{
		fdf->posx += 15;
		ft_matrix(fdf, 0, 0);
	}
}

void	ft_keyhook_zoom(int keycode, t_fdf *fdf)
{
	if (keycode == 84)
	{
		fdf->dist *= 2;
		ft_matrix(fdf, 0.00001, 0.00001);
	}
	if (keycode == 87)
	{
		fdf->dist /= 2;
		ft_matrix(fdf, 0.00001, 0.00001);
	}
}

void	ft_keyhook_rotate(int keycode, t_fdf *fdf)
{
	if (keycode == 85)
	{
		ft_matrix(fdf, 0.2, 0);
	}
	if (keycode == 83)
	{
		ft_matrix(fdf, 0, 0.2);
	}
}
