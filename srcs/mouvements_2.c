/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 12:41:12 by cjad              #+#    #+#             */
/*   Updated: 2022/11/20 12:46:24 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	move_left(t_vars *vars)
{
	int	x;
	int	y;
	int	cx;
	int	cy;

	x = (vars->x + (MOUVEMENT * cos((vars->angle - 90) * M_PI / 180))) / TILE;
	cx = vars->x / TILE;
	y = (vars->y + (MOUVEMENT * sin((vars->angle - 90) * M_PI / 180))) / TILE;
	cy = vars->y / TILE;
	if (vars->txt->map[cy - vars->face][cx] == '1'
		&& vars->txt->map[cy][cx - vars->side] == '1')
	{
		if (x != cx && y != cy)
			return ;
	}
	if (vars->txt->map[y][x] != '1')
	{
		vars->x = vars->x + (MOUVEMENT * cos((vars->angle - 90) * M_PI / 180));
		vars->y = vars->y + (MOUVEMENT * sin((vars->angle - 90) * M_PI / 180));
		rays(vars);
	}
}

void	move_right(t_vars *vars)
{
	int	x;
	int	y;
	int	cx;
	int	cy;

	x = (vars->x + (MOUVEMENT * cos((vars->angle + 90) * M_PI / 180))) / TILE;
	cx = vars->x / TILE;
	y = (vars->y + (MOUVEMENT * sin((vars->angle + 90) * M_PI / 180))) / TILE;
	cy = vars->y / TILE;
	if (vars->txt->map[cy - vars->face][cx] == '1'
		&& vars->txt->map[cy][cx - vars->side] == '1')
	{
		if (x != cx && y != cy)
			return ;
	}
	if (vars->txt->map[y][x] != '1')
	{
		vars->x = vars->x + (MOUVEMENT * cos((vars->angle + 90) * M_PI / 180));
		vars->y = vars->y + (MOUVEMENT * sin((vars->angle + 90) * M_PI / 180));
		rays(vars);
	}
}
