/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:38:45 by wmonacho          #+#    #+#             */
/*   Updated: 2022/03/29 16:30:45 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fill_maps(t_point **map, char *z_value, int i, int j)
{
	map[i][j].x = j;
	map[i][j].y = i;
	map[i][j].z = atoi(z_value);
	if (j == 0 && i == 0)
		map[0]->z_max = map[i][j].z;
	else if (map[i][j].z > map[0]->z_max)
		map[0]->z_max = map[i][j].z;
	printf("%f\n", map[i][j].x);
	printf("%f\n", map[i][j].y);
	printf("%f\n", map[i][j].z);
	printf("z_max =%f\n", map[0]->z_max);
	printf("\n");
}

void	set_maps(t_fdf *fdf, int fd)
{
	int		i;
	int		j;
	char	*line;
	char	**tab;

	i = -1;
	line = get_next_line(fd);
	while (++i < fdf->map[0]->y_max && line != NULL)
	{
		j = 0;
		line = ft_strtrim(line, "\n");
		tab = ft_split(line, ' ');
		while (line != NULL && tab[j])
		{
			ft_fill_maps((fdf->map), tab[j], i, j);
			j++;
		}
		free(line);
		line = get_next_line(fd);
	}
	printf("%d\n", i);
}

void	ft_malloc_maps(t_fdf *fdf, char *line, int fd)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	line = get_next_line(fd);
	x = ft_strlen(line) / 2;
	y = 0;
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		y++;
	}
	fdf->map = (t_point **)malloc(sizeof(t_point *) * (y));
	while (i < y)
	{
		fdf->map[i] = (t_point *)malloc(sizeof(t_point) * (x));
		i++;
	}
	fdf->map[0]->x_max = x;
	fdf->map[0]->y_max = y;
	free(line);
}

int	ft_parsing(int size, char **argv, t_fdf *fdf)
{
	int		fd;
	char	*line;

	line = NULL;
	if (size == 0)
		return (0);
	if (argv == NULL)
		return (0);
	fd = open("txt.txt", 0, O_RDONLY);
	ft_malloc_maps(fdf, line, fd);
	close(fd);
	fd = open("txt.txt", 0, O_RDONLY);
	set_maps(fdf, fd);
	close(fd);
	return (1);
}

/*
alors je dois remplir mon double tableau avec x y z
*/