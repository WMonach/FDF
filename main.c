/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:49:11 by wmonacho          #+#    #+#             */
/*   Updated: 2022/03/18 18:25:56 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "fdf.h"


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;	

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_fdf	fdf;
	t_data	img;
	t_pixel	pixel;


	pixel.x1 = 0;
	pixel.x2 = 2000;
	pixel.y2 = 1000;
	pixel.y1 = 0;
	pixel.dy = pixel.y2 - pixel.y1;
	pixel.dx = pixel.x2 - pixel.x1;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	printf("lol\n");
	fdf.maps = ft_parsing(argc, argv, fdf.maps);
	fdf.pixels = pixel;
	bresenham(fdf.pixels, img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
