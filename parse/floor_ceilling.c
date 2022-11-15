/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceilling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:45:49 by zihirri           #+#    #+#             */
/*   Updated: 2022/11/15 17:01:42 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	get_color(t_txt *text, char *str)
{
	char	**split;

	split = NULL;
	count_commas(str);
	if (ft_strncmp(str, "F ", 2) == 0)
		fill_f(split, text, str);
	else if (ft_strncmp(str, "C ", 2) == 0)
		fill_c(split, text, str);
	if (text->f != NULL)
		set_floor_color(text);
	if (text->c != NULL)
		set_ceilling_color(text);
}

void	check_alpha(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i][j])
		{
			if (ft_isdigit(str[i][j]) != 1)
			{
				printf("Error\nNaN\n");
				exit(1);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	set_floor_color(t_txt *txt)
{
	char	**split;
	int		convert;
	int		i;
	int		clr;

	clr = 0;
	i = 0;
	split = ft_split(txt->f, ',');
	check_alpha(split);
	while (split[i])
	{
		convert = ft_atoi(split[i]);
		if (convert > 255 || convert < 0)
		{
			printf("Error\nColor is out of Range\n");
			exit(1);
		}
		else
		{
			if (i == 0)
				txt->r = convert;
			else if (i == 2)
				txt->g = convert;
			else
				txt->b = convert;
		}
		i++;
	}
	txt->fcolor = (txt->r << 16 | txt->g << 8 | txt->b);
}

void	set_ceilling_color(t_txt *txt)
{
	char	**split;
	int		convert;
	int		i;

	i = 0;
	split = ft_split(txt->c, ',');
	check_alpha(split);
	while (split[i])
	{
		convert = ft_atoi(split[i]);
		if (convert > 255 || convert < 0)
		{
			printf("Error\nColor is out of Range\n");
			exit(1);
		}
		else
		{
			if (i == 0)
				txt->r = convert;
			else if (i == 2)
				txt->g = convert;
			else
				txt->b = convert;
		}
		i++;
	}
	txt->ccolor = (txt->r << 16 | txt->g << 8 | txt->b);
}
