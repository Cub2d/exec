/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:23:07 by cjad              #+#    #+#             */
/*   Updated: 2022/10/29 16:48:35 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	move_up(t_vars *vars)
{
	int				x;
	int				y;
	int				cx;
	int				cy;

	x = (vars->x1 + (8 * cos(vars->angle * M_PI / 180))) / 32;
	cx = vars->x1 / 32;
	y = (vars->y1 + (8 * sin(vars->angle * M_PI / 180))) / 32;
	cy = vars->y1 / 32;
	if (vars->map[cy + vars->face][cx] == '1'
		&& vars->map[cy][cx + vars->side] == '1')
	{
		if (x != cx && y != cy)
			return ;
	}
	if (vars->map[y][x] != '1')
	{
		vars->x1 = vars->x1 + (8 * cos(vars->angle * M_PI / 180));
		vars->y1 = vars->y1 + (8 * sin(vars->angle * M_PI / 180));
	}
}

void	move_down(t_vars *vars)
{
	int				x;
	int				y;
	int				cx;
	int				cy;

	x = (vars->x1 - (8 * cos(vars->angle * M_PI / 180))) / 32;
	cx = vars->x1 / 32;
	y = (vars->y1 - (8 * sin(vars->angle * M_PI / 180))) / 32;
	cy = vars->y1 / 32;
	if (vars->map[cy - vars->face][cx] == '1'
		&& vars->map[cy][cx - vars->side] == '1')
	{
		if (x != cx && y != cy)
			return ;
	}
	if (vars->map[y][x] != '1')
	{
		vars->x1 = vars->x1 - (8 * cos(vars->angle * M_PI / 180));
		vars->y1 = vars->y1 - (8 * sin(vars->angle * M_PI / 180));
	}
}

void	rotate_right(t_vars *vars)
{
	vars->angle += 3;
	if (vars->angle > 360)
		vars->angle -= 360;
	if (vars->angle >= 0 && vars->angle <= 180)
		vars->face = 1;
	else
		vars->face = -1;
	if (vars->angle >= 90 && vars->angle <= 270)
		vars->side = -1;
	else
		vars->side = 1;
}

void	rotate_left(t_vars *vars)
{
	vars->angle -= 3;
	if (vars->angle < 0)
		vars->angle += 360;
	if (vars->angle >= 0 && vars->angle <= 180)
		vars->face = 1;
	else
		vars->face = -1;
	if (vars->angle >= 90 && vars->angle <= 270)
		vars->side = -1;
	else
		vars->side = 1;
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
		rotate_right(vars);
	if (key == 123)
		rotate_left(vars);
	rays(vars);
	return (0);
}
