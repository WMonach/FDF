/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:38:45 by wmonacho          #+#    #+#             */
/*   Updated: 2022/05/06 16:54:09 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fill_maps(t_fdf	*fdf, char *z_value, int i, int j)
{
	fdf->map[i][j].z = atoi(z_value);
	fdf->map[i][j].x = j - ((fdf->x_max - 1) / 2);
	fdf->map[i][j].y = i - ((fdf->y_max - 1) / 2);
	if (j == 0 && i == 0)
	{
		fdf->z_max = fdf->map[i][j].z;
		fdf->z_min = fdf->map[i][j].z;
	}
	else if (fdf->map[i][j].z > fdf->z_max)
		fdf->z_max = fdf->map[i][j].z;
	else if (fdf->map[i][j].z < fdf->z_min)
		fdf->z_min = fdf->map[i][j].z;
}

void	set_maps(t_fdf *fdf, int fd)
{
	int		i;
	int		j;
	char	*line;
	char	**tab;

	i = -1;
	line = get_next_line(fd);
	while (++i < fdf->y_max && line != NULL)
	{
		j = 0;
		line = ft_strtrim(line, "\n");
		tab = ft_split(line, ' ');
		while (line != NULL && tab[j])
		{
			ft_fill_maps(fdf, tab[j], i, j);
			// printf("map[%d][%d].x=%f\n", i, j, fdf->map[i][j].x);
			// printf("map[%d][%d].y=%f\n", i, j, fdf->map[i][j].y);
			// printf("map[%d][%d].z=%f\n", i, j, fdf->map[i][j].z);
			j++;
		}
		ft_fill_rgb(fdf);
		free(line);
		line = get_next_line(fd);
	}
}

void	ft_malloc_maps(t_fdf *fdf, char *line, int fd)
{
	int			i;
	char		**tab;

	i = 0;
	line = get_next_line(fd);
	line = ft_strtrim(line, "\n");
	tab = ft_split(line, ' ');
	while (tab[i] != NULL)
		i++;
	fdf->x_max = i;
	i = 0;
	fdf->y_max = 0;
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		fdf->y_max++;
	}
	fdf->map = (t_point **)malloc(sizeof(t_point *) * (fdf->y_max));
	while (i < fdf->y_max)
		fdf->map[i++] = (t_point *)malloc(sizeof(t_point) * (fdf->x_max));
	free(line);
}

int	ft_parsing(int size, char **argv, t_fdf *fdf)
{
	int		fd;
	char	*line;

	line = NULL;
	fdf->posy = 540;
	fdf->posx = 960;
	if (size == 0)
		return (0);
	if (argv == NULL)
		return (0);
	fd = open(argv[1], 0, O_RDONLY);
	ft_malloc_maps(fdf, line, fd);
	close(fd);
	fd = open(argv[1], 0, O_RDONLY);
	set_maps(fdf, fd);
	close(fd);
	fdf->distx = (1920) / (fdf->x_max) * 0.75;
	fdf->disty = (1080) / (fdf->y_max) * 0.75;
	fdf->dist = ft_calculate_diff(fdf->distx, fdf->disty);
	return (1);
}

/*
alors je dois remplir mon double tableau avec x y z
*/