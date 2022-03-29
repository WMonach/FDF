/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:29:41 by wmonacho          #+#    #+#             */
/*   Updated: 2022/03/29 14:42:24 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham(t_pixel pixel, t_data img)
{	
	pixel.pente = pixel.dy / pixel.dx;
	pixel.x = 0;
	while (pixel.x < pixel.x2 - pixel.x1)
	{
		pixel.x++;
		pixel.y = (pixel.pente * pixel.x) + pixel.y1;
		if (pixel.x + pixel.x1 > 0 && pixel.y > 0 &&
			pixel.x + pixel.x1 < 1920 && pixel.y < 1080)
		{
			my_mlx_pixel_put(&img, pixel.x + pixel.x1, pixel.y, 0x00FF0000);
		}
	}
}
