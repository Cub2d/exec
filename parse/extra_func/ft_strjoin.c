/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zihirri <zihirri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:53:34 by zihirri           #+#    #+#             */
/*   Updated: 2022/11/16 15:43:37 by zihirri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	ft_strcat(char *s1, char *s2)
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

char	*ft_strjoin(char *s1, char *s2)
{
	int		s1l;
	int		s2l;
	char	*s;

	if (!s1 || !s2)
		return (NULL);
	s1l = ft_strlen(s1);
	s2l = ft_strlen(s2);
	s = (char *) malloc (sizeof (char) * (s1l + s2l + 1));
	if (!s)
		return (NULL);
	s[0] = '\0';
	ft_strcat(s, s1);
	ft_strcat(s, s2);
	return (s);
}

char	*st_strjoin(char *s1, char c)
{
	int		s1l;
	char	*s;

	if (!s1)
		return (NULL);
	s1l = ft_strlen(s1);
	s = (char *)malloc(sizeof(char) * (s1l + 2));
	if (!s)
		return (NULL);
	s[0] = '\0';
	ft_strcat(s, s1);
	if (c == '\n')
	{
		s[s1l] = '\0';
		free(s1);
		return (s);
	}
	s[s1l] = c;
	s[s1l + 1] = '\0';
	free(s1);
	return (s);
}
