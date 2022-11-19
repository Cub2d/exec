/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:06:39 by zihirri           #+#    #+#             */
/*   Updated: 2022/11/19 13:31:58 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	esc(void)
{
	exit(1);
	return (0);
}

void	check_textures2(t_vars *vars)
{
	int	fd;

	fd = open(vars->txt->no, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		ft_error("north texture file doesn't exist");
	}
	close(fd);
	fd = open(vars->txt->so, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		ft_error("south texture file doesn't exist");
	}
	close(fd);
}

void	check_textures(t_vars *vars)
{
	int	fd;

	fd = open(vars->txt->ea, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		ft_error("east texture file doesn't exist");
	}
	close(fd);
	fd = open(vars->txt->we, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		ft_error("west texture file doesn't exist");
	}
	close(fd);
	check_textures2(vars);
}

t_point	new_p(double x, double y)
{
	t_point	a;

	a.x = x;
	a.y = y;
	return (a);
}
