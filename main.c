/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:49:11 by wmonacho          #+#    #+#             */
/*   Updated: 2022/05/04 16:37:23 by wmonacho         ###   ########lyon.fr   */
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
		ft_move_down(fdf);
	if (keycode == 126)
		ft_move_up(fdf);
	if (keycode == 124)
		ft_move_left(fdf);
	if (keycode == 123)
		ft_move_right(fdf);
	if (keycode == 83)
	{
		ft_matrix_rx(fdf);
		fdf->rotx++;
	}
	if (keycode == 84)
		ft_calibration_zoom(fdf);
	if (keycode == 85)
	{
		ft_matrix_ry(fdf);
		fdf->roty++;
	}
	if (keycode == 87)
		ft_calibration_dezoom(fdf);
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
