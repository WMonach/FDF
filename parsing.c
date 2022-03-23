/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:38:45 by wmonacho          #+#    #+#             */
/*   Updated: 2022/03/23 17:22:00 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fill_maps(t_point **maps, char *z_value, int i, int j)
{
	maps[i][j].x = j;
	maps[i][j].y = i;
	maps[i][j].z = ft_atoi(z_value);
}

void	ft_set_zero(t_point *s, int n)
{
	int	count;

	count = 0;
	while (count < n)
	{
		s[count].x = 0;
		count++;
	}
}

t_point	**set_maps(t_fdf *fdf, int fd)
{
	int		i;
	int		j;
	char	*line;
	char	**tab;

	i = 0;
	line = get_next_line(fd);
	while (i < fdf->maps[0]->y_max && line != NULL)
	{
		j = 0;
		line = get_next_line(fd);
		line = ft_strtrim(line, "\n");
		tab = ft_split(line, ' ');
		while (j < fdf->maps[0]->x_max && line != NULL)
		{
			ft_fill_maps(fdf->maps, tab[j], i, j);
			j++;
		}
		i++;
	}
	return (fdf->maps);
}

void	ft_malloc_maps(t_fdf *fdf, char *line, int fd)
{
	int	i;

	i = 0;
	line = get_next_line(fd);
	(fdf)->maps[0]->x_max = strlen(line) / 2;
	(fdf)->maps[0]->y_max = 1;
	while (line != NULL)
	{
		line = get_next_line(fd);
		(*fdf).maps[0]->y_max++;
	}
	fdf->maps = (t_point **)malloc(sizeof(t_point *) * (fdf->maps[0]->y_max));
	while (i < fdf->maps[0]->y_max)
	{
		fdf->maps[i] = (t_point *)
			malloc(sizeof(t_point) * (fdf->maps[0]->x_max));
		i++;
	}
}

t_point	**ft_parsing(int size, char **argv, t_fdf *fdf)
{
	int		fd;
	char	*line;

	line = NULL;
	if (size == 0)
		return (NULL);
	if (argv == NULL)
		return (NULL);
	fd = open("txt.txt", 0, O_RDONLY);
	ft_malloc_maps(fdf, line, fd);
	close(fd);
	fd = open("txt.txt", 0, O_RDONLY);
	(*fdf).maps = set_maps(fdf, fd);
	close(fd);
	return (fdf->maps);
}

/*
je remplis maps et pour faire ca je cree une ft fill_maps.
le souci c'est que mon gnl va le lire en plusieurs fois?
faut que je remplise maps mais line par line, 
*/