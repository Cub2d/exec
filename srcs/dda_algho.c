/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algho.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:54:00 by cjad              #+#    #+#             */
/*   Updated: 2022/11/20 13:39:56 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/* the algorithm to calculate the wall height on my 
screen relying on the distance to it */

void	calculate_wall_height(t_point a, t_vars *vars)
{
	double	distance;
	double	plane_dist;

	distance = sqrt((a.x - vars->x) * (a.x - vars->x)
			+ (a.y - vars->y) * (a.y - vars->y));
	distance = distance * cos(vars->rayangle * M_PI / 180);
	plane_dist = WIN_WIDTH_2 / tan(30 * M_PI / 180);
	vars->wallheight = (TILE / distance) * plane_dist;
	if (!distance || vars->wallheight < 0)
		vars->wallheight = WIN_WIDTH;
	display_ray(vars->wallheight / 2, vars, a);
}

/* the algorithm to finding the first horizontal intersection
of my ray with the wall */

t_point	horizontal_point(t_vars *vars, double castangle)
{
	double	xstep;
	double	ystep;
	double	hx;
	double	hy;
	int		y;

	hy = floor(vars->y / TILE) * TILE;
	y = 0;
	if (yin(vars, castangle) > 0)
		hy += TILE;
	hx = vars->x + (hy - vars->y) / tan(castangle * M_PI / 180);
	ystep = TILE * yin(vars, castangle);
	xstep = TILE / tan(castangle * M_PI / 180);
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
	return (new_p(hx, hy));
}

/*the algorithm to finding the first 
vertical intersection of my ray with the wall*/

t_point	vertical_point(t_vars *vars, double castangle)
{
	double	xstep;
	double	ystep;
	double	hx;
	double	hy;
	int		x;

	hx = floor(vars->x / TILE) * TILE;
	x = 0;
	if (xin(vars, castangle) > 0)
		hx += TILE;
	hy = vars->y + (hx - vars->x) * tan(castangle * M_PI / 180);
	xstep = TILE * xin(vars, castangle);
	ystep = TILE * tan(castangle * M_PI / 180);
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
	return (new_p(hx, hy));
}

double	distance_to_point(t_vars *vars, t_point a)
{
	double	distance;

	distance = sqrt((vars->x - a.x) * (vars->x - a.x)
			+ (vars->y - a.y) * (vars->y - a.y));
	return (distance);
}
