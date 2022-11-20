/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_func_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zihirri <zihirri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:10:52 by zihirri           #+#    #+#             */
/*   Updated: 2022/11/20 12:22:05 by zihirri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	check_space(char *str)
{
	int	n;

	n = 0;
	while (str[n] == ' ')
		n++;
	if (str[n] == '1')
		return (OK);
	else
		return (KO);
	return (OK);
}

void	ft_error(char *str)
{
	printf("Error\n%s\n", str);
	exit(-1);
}

void	get_rgb(t_txt *txt, int i, int convert)
{
	if (i == 0)
		txt->r = convert;
	else if (i == 2)
		txt->g = convert;
	else
		txt->b = convert;
}

int	is_not_filled(t_txt *text)
{
	if (text->no == NULL || text->so == NULL
		|| text->ea == NULL || text->we == NULL
		|| text->c == NULL || text->f == NULL || text->map[0] == NULL)
		return (OK);
	else
		return (KO);
}

void	map_filler(t_txt *text, char *str)
{
	text->map[text->fill] = ft_strdup(str);
	text->fill++;
}
