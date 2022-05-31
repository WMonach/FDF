/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 15:10:35 by wmonacho          #+#    #+#             */
/*   Updated: 2022/05/17 15:35:27 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42000000
# endif
# include <stdlib.h>
# include <unistd.h>

typedef struct s_StructBuffer
{
	size_t	redlight;
	size_t	index;
	char	buf[BUFFER_SIZE];
}	t_StructBuffer;

char	*get_next_line(int fd);
char	*ft_free(char *freestr);
char	*ft_strchrr(char *string, int searchedChar);
int		ft_strcharlen_mode(char *str, char c, int mode);
int		ft_strlan(char *str);
int		ft_strlenn(char *str);
void	f_bzero(void *s, size_t n);
#endif