/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:38:45 by wmonacho          #+#    #+#             */
/*   Updated: 2022/03/11 16:46:29 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_parsing(int size, char **argv)
{
	int		fd;
	char	*line;
	int		x;
	int		y;
	int		z;

	line = NULL;
	fd = open(argv[1], BUFFER, O_RDONLY);
	line = get_next_line(fd);
	x = ft_strlen(line);
	y = 1;
	while (line != NULL)
	{
		line = get_next_line(fd);
		y++;
	}
	close(fd);
	fd = open(argv[1], BUFFER, O_RDONLY);
	
	close(fd);
	return ;
}
