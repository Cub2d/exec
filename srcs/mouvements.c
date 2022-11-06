/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:23:07 by cjad              #+#    #+#             */
/*   Updated: 2022/11/05 15:31:17 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	move_up(t_vars *vars)
{
	int				x;
	int				y;
	int				cx;
	int				cy;

	x = (vars->x + (MOUVEMENT_SPEED * cos(vars->angle * M_PI / 180))) / 32;
	cx = vars->x / 32;
	y = (vars->y + (MOUVEMENT_SPEED * sin(vars->angle * M_PI / 180))) / 32;
	cy = vars->y / 32;
	if (vars->map[cy + vars->face][cx] == '1'
		&& vars->map[cy][cx + vars->side] == '1')
	{
		if (x != cx && y != cy)
			return ;
	}
	if (vars->map[y][x] != '1')
	{
		vars->x = vars->x + (MOUVEMENT_SPEED * cos(vars->angle * M_PI / 180));
		vars->y = vars->y + (MOUVEMENT_SPEED * sin(vars->angle * M_PI / 180));
		rays(vars);
	}
}

void	move_down(t_vars *vars)
{
	int				x;
	int				y;
	int				cx;
	int				cy;

	x = (vars->x - (MOUVEMENT_SPEED * cos(vars->angle * M_PI / 180))) / 32;
	cx = vars->x / 32;
	y = (vars->y - (MOUVEMENT_SPEED * sin(vars->angle * M_PI / 180))) / 32;
	cy = vars->y / 32;
	if (vars->map[cy - vars->face][cx] == '1'
		&& vars->map[cy][cx - vars->side] == '1')
	{
		if (x != cx && y != cy)
			return ;
	}
	if (vars->map[y][x] != '1')
	{
		vars->x = vars->x - (MOUVEMENT_SPEED * cos(vars->angle * M_PI / 180));
		vars->y = vars->y - (MOUVEMENT_SPEED * sin(vars->angle * M_PI / 180));
		rays(vars);
	}
}

void	rotate_right(t_vars *vars)
{
	vars->angle += ROTATE_SPEED;
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
	rays(vars);
}

void	rotate_left(t_vars *vars)
{
	vars->angle -= ROTATE_SPEED;
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
	rays(vars);
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
	return (0);
}
