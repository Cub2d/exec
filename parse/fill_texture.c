/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:17:35 by zihirri           #+#    #+#             */
/*   Updated: 2022/11/15 16:59:17 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// Fills every texture with its value
void	fill_no(char **split, t_txt *text, char *str)
{
	split = ft_split(str, ' ');
	if (split[2] == NULL)
	{
		if (text->no == NULL)
			text->no = split[1];
		else
			ft_error("Tried to fill NO twice or more");
	}
	else
		ft_error("Check the texture paths");
}

void	fill_so(char **split, t_txt *text, char *str)
{
	split = ft_split(str, ' ');
	if (split[2] == NULL)
	{
		if (text->so == NULL)
			text->so = split[1];
		else
			ft_error("Tried to fill SO twice or more");
	}
	else
		ft_error("Check the texture paths");
}

void	fill_ea(char **split, t_txt *text, char *str)
{
	split = ft_split(str, ' ');
	if (split[2] == NULL)
	{
		if (text->ea == NULL)
			text->ea = split[1];
		else
			ft_error("Tried to fill EA twice or more");
	}
	else
		ft_error("Check the texture paths");
}

void	fill_we(char **split, t_txt *text, char *str)
{
	split = ft_split(str, ' ');
	if (split[2] == NULL)
	{
		if (text->we == NULL)
			text->we = split[1];
		else
			ft_error("Tried to fill WE twice or more");
	}
	else
		ft_error("Check the texture paths");
}
