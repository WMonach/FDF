/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:40:52 by wmonacho          #+#    #+#             */
/*   Updated: 2022/05/04 16:48:09 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
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
	float	**data;
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
	float		x_mat;
	float		y_mat;
	float		z_mat;
	float		lgnmax;
	float		latmax;
	int			rotx;
	int			roty;
}	t_fdf;

int		ft_parsing(int argc, char **argv, t_fdf *fdf);
void	ft_print_tab(t_point *tab, int size);
void	set_map(t_point **map);
int		main(int argc, char **argv);
void	ft_draw(t_data *img, t_fdf *fdf);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_matrix(t_fdf *fdf);
void	ft_zoom(t_fdf *fdf);
void	ft_matrix_projection(t_fdf *fdf);
float	ft_calculate_diff(float ratio_x, float ratio_y);
void	ft_calibration(t_fdf *fdf, float ratio_x, float ratio_y, float ratio);
void	ft_matrix_ry(t_fdf *fdf);
void	ft_matrix_rx(t_fdf *fdf);
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

# define BUFFER 100
# define TETA 0.61540309

#endif