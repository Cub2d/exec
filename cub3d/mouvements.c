/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:23:07 by cjad              #+#    #+#             */
/*   Updated: 2022/10/22 14:53:43 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_up(t_vars *vars)
{
	static double	pi;
	int				x;
	int				y;

	pi = 3.1415926535;
	x = (vars->x1 + (8 * cos(vars->angle * pi / 180))) / 32;
	y = (vars->y1 + (8 * sin(vars->angle * pi / 180))) / 32;
	if (vars->map[y][x] != '1')
	{
		vars->x1 = vars->x1 + (8 * cos(vars->angle * pi / 180));
		vars->y1 = vars->y1 + (8 * sin(vars->angle * pi / 180));
	}
}

void	move_down(t_vars *vars)
{
	static double	pi;
	int				x;
	int				y;

	pi = 3.1415926535;
	y = (vars->x1 - (8 * cos(vars->angle * pi / 180))) / 32;
	x = (vars->y1 - (8 * sin(vars->angle * pi / 180))) / 32;
	if (vars->map[x][y] != '1')
	{
		vars->x1 = vars->x1 - (8 * cos(vars->angle * pi / 180));
		vars->y1 = vars->y1 - (8 * sin(vars->angle * pi / 180));
	}
}

int	keys_hook(int key, t_vars *vars)
{
	if (key == 53)
		exit(1);
	if (key == 13 || key == 126)
		move_up(vars);
	if (key == 1 || key == 125)
		move_down(vars);
	if (key == 124)
		vars->angle += 3;
	if (key == 123)
		vars->angle -= 3;
	rays(vars);
	return (0);
}
