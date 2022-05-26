/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: will <will@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:40:52 by wmonacho          #+#    #+#             */
/*   Updated: 2022/05/26 13:22:36 by will             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "mlx/mlx.h"

typedef struct s_default
{
	float	x;
	float	y;
	float	z;
	float	**dfault;
}				t_default;

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	int		colorx;
	int		colory;
}	t_point;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_pixel
{
	float	dx;
	float	dy;
	float	x1;
	float	x2;
	float	y1;
	float	y2;
	float	ex;
	float	ey;
	float	max;
	int		a;
	int		b;
}				t_pixel;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_fdf
{
	t_data		data;
	t_default	**dfault;
	t_pixel		pixel;
	t_pixel		temp;
	t_point		**map;
	t_vars		vars;
	float		x_max;
	float		y_max;
	float		z_max;
	float		z_min;
	float		x_mat;
	float		y_mat;
	float		z_mat;
	float		dist;
	float		distx;
	float		disty;
	float		distz;
	float		posx;
	float		posy;
	int			colorx;
	int			colorxtemp;
	int			colorx2;
	int			start;
}	t_fdf;

int		ft_parsing(int argc, char **argv, t_fdf *fdf);
void	ft_print_tab(t_point *tab, int size);
void	set_map(t_point **map);
int		main(int argc, char **argv);
void	ft_draw(t_data *img, t_fdf *fdf);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_matrix(t_fdf *fdf, float teta, float delta);
float	ft_calculate_diff(float ratio_x, float ratio_y);
void	ft_calibration(t_fdf *fdf);
void	ft_matrix_ry(t_fdf *fdf, float delta);
void	ft_matrix_rx(t_fdf *fdf, float teta);
void	ft_matrix_rz(t_fdf *fdf);
void	ft_formal_calculation(t_fdf *fdf, int i, int j, int mode);
void	ft_rounded(float number1, float number2, t_fdf	*fdf);
float	ft_max(float max1, float max2);
void	ft_calibrate_z(t_fdf *fdf);
void	ft_calibration_zoom(t_fdf *fdf);
void	ft_set_up_mat(t_fdf *fdf);
void	ft_calibration_dezoom(t_fdf *fdf);
void	ft_move_right(t_fdf *fdf);
void	ft_move_up(t_fdf *fdf);
void	ft_move_down(t_fdf *fdf);
void	ft_move_left(t_fdf *fdf);
void	ft_set_data(t_fdf *fdf);
void	ft_calibration_mat(t_fdf *fdf);
void	ft_set_invdata(t_fdf *fdf);
float	ft_calculate_diffinv(float ratio_x, float ratio_y);
void	ft_keyhook_translation(int keycode, t_fdf *fdf);
void	ft_keyhook_zoom(int keycode, t_fdf *fdf);
void	ft_keyhook_rotate(int keycode, t_fdf *fdf);
void	ft_rgb(t_fdf *fdf, int i, int j);
void	ft_fill_rgb(t_fdf *fdf);
int		ft_gradiant(t_fdf *fdf, int colorx2);
int		ft_green_to_blue(t_fdf *fdf);
int		ft_red_to_green(t_fdf *fdf);
int		ft_red_to_blue(t_fdf *fdf);
int		ft_blue_to_red(t_fdf *fdf);
int		ft_green_to_red(t_fdf *fdf);
int		ft_blue_to_green(t_fdf *fdf);
void	ft_free_all(t_fdf *fdf);
float	ft_max(float max1, float max2);
void	ft_free_map(t_fdf *fdf);
int		ft_free_line(char *line);
int		ft_destroy_image(t_fdf *fdf);
void	ft_malloc_mapsbis(t_fdf *fdf);
void	ft_malloc_dfault(t_fdf *fdf);
void	ft_malloc_maps(t_fdf *fdf, int fd);
int		ft_check_read(char **argv);
# define BUFFER 100

#endif