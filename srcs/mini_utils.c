/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zihirri <zihirri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:16:59 by cjad              #+#    #+#             */
/*   Updated: 2022/11/16 15:47:05 by zihirri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// using the algorithm to draw a line from a point to another

void	player_direction(t_vars *vars, t_point a, t_point b)
{
	double	xinc;
	double	yinc;
	int		steps;
	int		i;

	if (abs((int)(b.x - a.x)) > abs((int)(b.y - a.y)))
		steps = abs((int)(b.x - a.x));
	else
		steps = abs((int)(b.y - a.y));
	i = 1;
	xinc = (int)(b.x - a.x) / (double) steps;
	yinc = (int)(b.y - a.y) / (double) steps;
	while (i < steps)
	{
		my_mlx_pixel_put(&vars->img, a.x, a.y, 0xFF0000);
		a.x += xinc;
		a.y += yinc;
		i++;
	}
}

// using the player angle and finding the angles 
//of the lines i need to draw for my water drop

void	water_drop(t_vars *vars, t_point a)
{
	double	start;
	double	end;
	double	x;
	double	y;

	start = vars->angle - 180 - 20;
	end = vars->angle - 180 + 20;
	while (start <= end)
	{
		x = a.x + (11 * cos(start * M_PI / 180));
		y = a.y + (11 * sin(start * M_PI / 180));
		player_direction(vars, a, new_p(x, y));
		start += 0.1;
	}
}
