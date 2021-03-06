/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: will <will@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:38:45 by wmonacho          #+#    #+#             */
/*   Updated: 2022/05/26 14:37:53 by will             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_check_read(char **argv)
{
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
		return (0);
	return (1);
}

void	ft_fill_maps(t_fdf	*fdf, char *z_value, int i, int j)
{
	fdf->map[i][j].z = ft_atoi(z_value);
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
	char	*trim;

	i = -1;
	line = get_next_line(fd);
	while (++i < fdf->y_max && line != NULL)
	{
		j = -1;
		trim = ft_strtrim(line, "\n");
		free (line);
		tab = ft_split(trim, ' ');
		while (trim != NULL && tab[++j])
			ft_fill_maps(fdf, tab[j], i, j);
		free(trim);
		j = 0;
		line = get_next_line(fd);
		while (tab[j] != NULL)
			free(tab[j++]);
		free(tab);
	}
	ft_fill_rgb(fdf);
	free(line);
}

int	ft_parsing(int size, char **argv, t_fdf *fdf)
{
	int		fd;

	fdf->posy = 540;
	fdf->posx = 960;
	fdf->y_max = 0;
	if (size == 0)
		return (0);
	fd = open(argv[1], 0, O_RDONLY);
	ft_malloc_maps(fdf, fd);
	close(fd);
	fdf->distx = (1920) / (fdf->x_max) * 0.75;
	fdf->disty = (1080) / (fdf->y_max) * 0.75;
	fdf->dist = ft_calculate_diff(fdf->distx, fdf->disty);
	fd = open(argv[1], 0, O_RDONLY);
	set_maps(fdf, fd);
	close(fd);
	return (1);
}
