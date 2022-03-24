/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:38:45 by wmonacho          #+#    #+#             */
/*   Updated: 2022/03/24 16:49:30 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fill_maps(t_point **maps, char *z_value, int i, int j)
{
	(*maps)->x = j;
	(*maps)->y = i;
	(*maps)->z = ft_atoi(z_value);
	printf("%f\n", (*maps)->x);
	printf("%f\n", (*maps)->y);
	printf("%f\n", (*maps)->z);
	printf("\n");
	(*maps)++;
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

void	set_maps(t_fdf *fdf, int fd)
{
	int		i;
	int		j;
	char	*line;
	char	**tab;
	t_point	*tmp;

	tmp = fdf->maps;
	i = -1;
	line = get_next_line(fd);
	while (++i < tmp->y_max && line != NULL)
	{
		j = 0;
		line = ft_strtrim(line, "\n");
		tab = ft_split(line, ' ');
		while (line != NULL && tab[j])
		{
			ft_fill_maps(&(fdf->maps), tab[j], i, j);
			j++;
		}
		free(line);
		line = get_next_line(fd);
	}
	printf("%d\n", i);
	fdf->maps = tmp;
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
	fdf->maps = (t_point *)malloc(sizeof(t_point) * (y));
	fdf->maps->x_max = x;
	(fdf)->maps[0].y_max = y;
	free(line);
}

t_point	*ft_parsing(int size, char **argv, t_fdf *fdf)
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
	set_maps(fdf, fd);
	close(fd);
	return (fdf->maps);
}

/*
je remplis maps et pour faire ca je cree une ft fill_maps.
le souci c'est que mon gnl va le lire en plusieurs fois?
faut que je remplise maps mais line par line, 
*/