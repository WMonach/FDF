/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:40:52 by wmonacho          #+#    #+#             */
/*   Updated: 2022/03/18 18:21:29 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "mlx/mlx.h"

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
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
	void	*pixel;
	float	dx;
	float	dy;
	int		x1;
	int		x2;
	int		y1;
	int		y2;
	int		x;
	int		y;
	float	pente;
}				t_pixel;

typedef struct s_fdf
{
	t_data	data;
	t_pixel	pixels;
	t_point	**maps;
}	t_fdf;


t_point	**ft_parsing(int argc, char **argv, t_point **maps);
void	ft_print_tab(t_point *tab, int size);
t_point	**set_map(t_point **maps, int x, int y);
int		main(int argc, char **argv);
void	bresenham(t_pixel pixel, t_data img);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

# define BUFFER 100

#endif