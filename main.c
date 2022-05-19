/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:49:11 by wmonacho          #+#    #+#             */
/*   Updated: 2022/05/19 16:24:48 by wmonacho         ###   ########lyon.fr   */
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
	mlx_destroy_image(fdf->vars.mlx, fdf->data.img);
	fdf->data.img = mlx_new_image(fdf->vars.mlx, 1920, 1080);
	fdf->data.addr = mlx_get_data_addr(fdf->data.img,
			&fdf->data.bits_per_pixel, &fdf->data.line_length,
			&fdf->data.endian);
	ft_keyhook_translation(keycode, fdf);
	ft_keyhook_zoom(keycode, fdf);
	ft_keyhook_rotate(keycode, fdf);
	if (keycode == 53)
	{
		ft_free_all(fdf);
		exit (0);
	}
	ft_draw(&fdf->data, fdf);
	mlx_put_image_to_window(fdf->vars.mlx, fdf->vars.win, fdf->data.img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;
	int		fd;
	char	*line;
	int		i;

	i = 0;
	line = malloc(sizeof(char) * 1);
	fd = open(argv[1], 0, O_RDONLY);
	i = read(fd, line, sizeof(char) * 1);
	close(fd);
	free(line);
	if (i < 0)
		return (1);
	fdf = malloc(sizeof(t_fdf));
	if (ft_parsing(argc, argv, fdf) == 0)
	{
		free(fdf);
		return (1);
	}
	fdf->vars.mlx = mlx_init();
	fdf->vars.win = mlx_new_window(fdf->vars.mlx, 1920, 1080, "Viens ici que j'te bute enculé!");
	fdf->data.img = mlx_new_image(fdf->vars.mlx, 1920, 1080);
	fdf->data.addr = mlx_get_data_addr((fdf->data.img),
			&(fdf->data.bits_per_pixel), &(fdf->data.line_length),
			&(fdf->data.endian));
	ft_calibrate_z(fdf);
	ft_matrix(fdf, 0.61, 0.61);
	mlx_key_hook(fdf->vars.win, key_hook, fdf);
	ft_draw(&(fdf->data), fdf);
	mlx_put_image_to_window(fdf->vars.mlx, fdf->vars.win, fdf->data.img, 0, 0);
	mlx_loop(fdf->vars.mlx);
	ft_free_all(fdf);
}

void	ft_free_all(t_fdf *fdf)
{
	int	i;

	i = -1;
	printf("%p\n", fdf->vars.win);
	while (++i < fdf->y_max)
		free(fdf->map[i]);
	free(fdf->map);
	i = -1;
	while (++i < fdf->y_max)
		free(fdf->dfault[i]);
	free(fdf->dfault);
	mlx_destroy_image(fdf->vars.mlx, fdf->data.img);
	mlx_destroy_window(fdf->vars.mlx, fdf->vars.win);
	free(fdf);
	exit (0);
}

void	ft_free_map(t_fdf *fdf)
{
	int	i;

	i = -1;
	while (++i < fdf->y_max)
		free(fdf->map[i]);
	free(fdf->map);
	free(fdf);
	exit (0);
}

int	ft_destroy_image(t_fdf *fdf)
{
	fdf->y_mat += 0;
	printf("%p\n", fdf->vars.win);
	mlx_destroy_image((fdf->vars.mlx), (fdf->data.img));
	mlx_destroy_window((fdf->vars.mlx), (fdf->vars.win));
	free(fdf->vars.mlx);
	free(fdf);
	return (1);
}
