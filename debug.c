/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:01:02 by wmonacho          #+#    #+#             */
/*   Updated: 2022/03/18 18:19:22 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_tab(t_point *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("tab=%d,\n", ((int *)tab)[i]);
		i++;
	}
}
