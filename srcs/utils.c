/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:49:06 by cjad              #+#    #+#             */
/*   Updated: 2022/11/06 13:31:05 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

int	xin(t_vars *vars, double castangle)
{
	if (castangle > 360)
		castangle -= 360;
	if (castangle < 0)
		castangle += 360;
	if (castangle >= 90 && castangle <= 270)
	{
		vars->rayside = -1;
		return (-1);
	}
	else
	{
		vars->rayside = 1;
		return (1);
	}
}

int	yin(t_vars *vars, double castangle)
{
	if (castangle > 360)
		castangle -= 360;
	if (castangle < 0)
		castangle += 360;
	if (castangle >= 0 && castangle <= 180)
	{
		vars->rayface = 1;
		return (1);
	}
	else
	{
		vars->rayface = -1;
		return (-1);
	}
}

int	is_not_wall(t_vars *vars, double hx, double hy)
{
	int	x;
	int	y;

	x = hx / 32;
	y = hy / 32;
	if (y >= 0 && y < vars->height)
	{
		if (x >= 0 && x < (int)ft_strlen(vars->map[y]))
		{
			if (vars->map[y][x] != '1')
				return (1);
		}
	}
	return (0);
}
