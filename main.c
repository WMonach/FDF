/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:49:11 by wmonacho          #+#    #+#             */
/*   Updated: 2022/04/14 14:28:53 by wmonacho         ###   ########lyon.fr   */
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

int	key_hook(int keycode, t_fdf *fdf)
{
	printf("Hello from key_hook!, %d\n", keycode);
	mlx_destroy_image(fdf->vars.mlx, fdf->data.img);
	fdf->data.img = mlx_new_image(fdf->vars.mlx, 1920, 1080);
	fdf->data.addr = mlx_get_data_addr(fdf->data.img, &fdf->data.bits_per_pixel, &fdf->data.line_length,
			&fdf->data.endian);
	if (keycode == 125)
		ft_zoom(fdf, 1.1);
	if (keycode == 124)
	{
		ft_matrix_rx(fdf);
		ft_matrix_projection(fdf);
		ft_calibration(fdf, 0, 0, 0);
	}
	if (keycode == 123)
	{
		ft_matrix_ry(fdf);
		ft_matrix_projection(fdf);
		ft_calibration(fdf, 0, 0, 0);
	}
	ft_draw(&fdf->data, fdf);
	mlx_put_image_to_window(fdf->vars.mlx, fdf->vars.win, fdf->data.img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	fdf.vars = vars;
	fdf.data.img = mlx_new_image(vars.mlx, 1920, 1080);
	fdf.data.addr = mlx_get_data_addr(fdf.data.img, &fdf.data.bits_per_pixel, &fdf.data.line_length,
			&fdf.data.endian);
	ft_parsing(argc, argv, &fdf);
	ft_matrix(&fdf);
	// mlx_destroy_image(mlx_ptr_t *mlx_ptr, mlx_img_list_t *img_todel);
	mlx_key_hook(fdf.vars.win, key_hook, &fdf);
	ft_draw(&(fdf.data), &fdf);
	mlx_put_image_to_window(fdf.vars.mlx, fdf.vars.win, fdf.data.img, 0, 0);
	mlx_loop(fdf.vars.mlx);
}
 