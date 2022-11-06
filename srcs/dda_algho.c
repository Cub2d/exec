/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algho.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:54:00 by cjad              #+#    #+#             */
/*   Updated: 2022/11/06 15:28:45 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	calculate_wall_height(t_point a, t_vars *vars)
{
	double	distance;
	double	plandist;
	double	wallheight;

	distance = sqrt((a.x - vars->x) * (a.x - vars->x)
			+ (a.y - vars->y) * (a.y - vars->y));
	distance = distance * cos(vars->rayangle * M_PI / 180);
	plandist = WIN_WIDTH_2 / tan(30 * M_PI / 180);
	wallheight = (32 / distance) * plandist;
	if (!distance || wallheight > WIN_WIDTH || wallheight < 0)
		wallheight = WIN_WIDTH;
	display_ray(wallheight / 2, vars);
}

t_point	horizontal_point(t_vars *vars, float castangle)
{
	double	xstep;
	double	ystep;
	double	hx;
	double	hy;
	int		y;

	hy = floor(vars->y / 32) * 32;
	y = 0;
	if (yin(vars, castangle) > 0)
		hy += 32;
	hx = vars->x + (hy - vars->y) / tan(castangle * M_PI / 180);
	ystep = 32 * yin(vars, castangle);
	xstep = 32 / tan(castangle * M_PI / 180);
	if ((xstep > 0 && xin(vars, castangle) < 0)
		|| (xstep < 0 && xin(vars, castangle) > 0))
		xstep *= -1;
	if (yin(vars, castangle) < 0)
		y = 1;
	while (is_not_wall(vars, hx, hy - y))
	{
		hx += xstep;
		hy += ystep;
	}
	return (new_point(hx, hy));
}

t_point	vertical_point(t_vars *vars, double castangle)
{
	double	xstep;
	double	ystep;
	double	hx;
	double	hy;
	int		x;

	hx = floor(vars->x / 32) * 32;
	x = 0;
	if (xin(vars, castangle) > 0)
		hx += 32;
	hy = vars->y + (hx - vars->x) * tan(castangle * M_PI / 180);
	xstep = 32 * xin(vars, castangle);
	ystep = 32 * tan(castangle * M_PI / 180);
	if ((ystep > 0 && yin(vars, castangle) < 0)
		|| (ystep < 0 && yin(vars, castangle) > 0))
		ystep *= -1;
	if (xin(vars, castangle) < 0)
		x = 1;
	while (is_not_wall(vars, hx - x, hy))
	{
		hx += xstep;
		hy += ystep;
	}
	return (new_point(hx, hy));
}

double	distance_to_point(t_vars *vars, t_point a)
{
	double	distance;

	distance = sqrt((vars->x - a.x) * (vars->x - a.x)
			+ (vars->y - a.y) * (vars->y - a.y));
	return (distance);
}
