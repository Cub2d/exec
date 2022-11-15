/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zihirri <zihirri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:42:42 by zihirri           #+#    #+#             */
/*   Updated: 2022/11/15 15:53:49 by zihirri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	ft_strncmp(char *str1, char *str2, size_t len)
{
	size_t	i;

	i = 0;
	if (str1 == str2 || len == 0)
		return (0);
	while (i < len)
	{
		if (str1[i] != str2[i] || str1[i] == '\0' || str2[i] == '\0')
			return (((unsigned char *)str1)[i] - ((unsigned char *)str2)[i]);
		i++;
	}
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
