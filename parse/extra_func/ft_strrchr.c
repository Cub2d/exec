/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zihirri <zihirri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:41:55 by zihirri           #+#    #+#             */
/*   Updated: 2022/11/15 15:48:18 by zihirri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

char	*ft_strrchr( char *haystack, int needle)
{
	int		i;
	char	*str;

	str = (char *)haystack;
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == (unsigned char)needle)
			return (str + i);
		i--;
	}
	return (NULL);
}
