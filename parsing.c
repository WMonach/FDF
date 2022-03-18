/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:38:45 by wmonacho          #+#    #+#             */
/*   Updated: 2022/03/18 18:27:41 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	**set_maps(t_point **maps, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = x;
	maps = (t_point **)malloc(sizeof(t_point *) * (2));
	while (i < 2)
	{
		maps[i] = (t_point *)malloc(sizeof(t_point) * (x));
		ft_bzero(maps[i], x);
		i++;
		x = y;
	}
	ft_print_tab(maps[1], j);
	return (maps);
}

t_point	**ft_parsing(int size, char **argv, t_point **maps)
{
	int		fd;
	char	*line;
	int		x;
	int		y;

	if (size == 0)
		return (NULL);
	if (argv == NULL)
		return (NULL);
	fd = open("txt.txt", 1, O_RDONLY);
	line = get_next_line(fd);
	x = strlen(line);
	y = 1;
	while (line != NULL)
	{
		printf("lol\n");
		line = get_next_line(fd);
		printf("mo\n");
		y++;
	}
	printf("lol\n");
	close(fd);
	maps = set_maps(maps, x, y);
	return (maps);
}
