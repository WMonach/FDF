/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: will <will@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:23:17 by wmonacho          #+#    #+#             */
/*   Updated: 2022/05/26 13:38:03 by will             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_keyhook_translation(int keycode, t_fdf *fdf)
{
	if (keycode == 115)
	{
		fdf->posy += 15;
		ft_matrix(fdf, 0, 0);
	}
	if (keycode == 119)
	{
		fdf->posy -= 15;
		ft_matrix(fdf, 0, 0);
	}
	if (keycode == 97)
	{
		fdf->posx -= 15;
		ft_matrix(fdf, 0, 0);
	}
	if (keycode == 100)
	{
		fdf->posx += 15;
		ft_matrix(fdf, 0, 0);
	}
}

void	ft_keyhook_zoom(int keycode, t_fdf *fdf)
{
	if (keycode == 65364)
	{
		fdf->dist *= 2;
		ft_matrix(fdf, 0.00001, 0.00001);
	}
	if (keycode == 65362)
	{
		fdf->dist /= 2;
		ft_matrix(fdf, 0.00001, 0.00001);
	}
}

void	ft_keyhook_rotate(int keycode, t_fdf *fdf)
{
	if (keycode == 65361)
	{
		ft_matrix(fdf, 0.2, 0);
	}
	if (keycode == 65363)
	{
		ft_matrix(fdf, 0, 0.2);
	}
}
