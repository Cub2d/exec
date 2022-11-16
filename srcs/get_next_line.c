/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zihirri <zihirri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:19:18 by zihirri           #+#    #+#             */
/*   Updated: 2022/11/16 15:43:32 by zihirri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

size_t	ft_strlen(char *c)
{
	int	i;

	i = 0;
	while (c && c[i])
	{
		i++;
	}
	return (i);
}

void	ft_strcat(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
	{
		s1[i + j] = s2[j];
		j++;
	}
	s1[i + j] = '\0';
}

static void	ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
}

char	*ft_strdup( char *s1)
{
	int		i;
	char	*scpy;

	i = ft_strlen(s1);
	scpy = (char *)malloc(sizeof(char) * (i + 1));
	if (!scpy)
		return (NULL);
	ft_strcpy(scpy, s1);
	return (scpy);
}

char	*get_next_line(int fd)
{
	char	*str;
	char	buff;
	int		r;

	r = read(fd, &buff, 1);
	str = ft_strdup("");
	while (r > 0)
	{
		str = st_strjoin(str, buff);
		if (buff == '\n')
			break ;
		r = read(fd, &buff, 1);
	}
	if (r < 0)
	{
		free(str);
		return (NULL);
	}
	if (r == 0 && str[0] == '\0')
	{
		free(str);
		return (NULL);
	}
	return (str);
}
