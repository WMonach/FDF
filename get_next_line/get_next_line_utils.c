/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:34:12 by wmonacho          #+#    #+#             */
/*   Updated: 2022/03/23 10:16:40 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlenn(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		return (i + 1);
	return (i);
}

int	ft_strlan(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_free(char *freestr)
{
	if (freestr)
		free(freestr);
	return (NULL);
}

void	f_bzero(void *s, size_t n)
{
	size_t	count;

	count = 0;
	while (count < n)
	{
		((char *)s)[count] = '\0';
		count++;
	}
}

char	*ft_strchrr(char *string, int searchedChar)
{
	int	count;

	count = 0;
	if (!string)
		return (NULL);
	while (string[count] != '\0')
	{
		if (string[count] == (char)searchedChar)
			return ((char *)string + count);
		count++;
	}
	if (string[count] == (char)searchedChar)
		return ((char *)string + count);
	return (NULL);
}
