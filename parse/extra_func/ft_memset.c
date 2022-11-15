/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zihirri <zihirri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:19:36 by zihirri           #+#    #+#             */
/*   Updated: 2022/11/14 13:51:26 by zihirri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	size_t			i;
	unsigned char	chr;
	char			*result;

	chr = value;
	result = pointer;
	i = 0;
	while (i < count)
	{
		result[i] = chr;
		i++;
	}
	return (pointer);
}
