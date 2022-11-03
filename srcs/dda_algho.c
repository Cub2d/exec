/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algho.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:54:00 by cjad              #+#    #+#             */
/*   Updated: 2022/11/03 17:26:08 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	position_check(t_vars *vars, t_dda dda, t_point	*a)
{
	int	x;
	int	y;
	int	xin;
	int	yin;

	x = a->x / 32;
	y = a->y / 32;
	if (dda.xinc > 0)
		xin = 1;
	else
		xin = -1;
	if (dda.yinc > 0)
		yin = 1;
	else
		yin = -1;
	if (vars->map[dda.y + yin][dda.x] == '1'
		&& vars->map[dda.y][dda.x + xin] == '1')
	{
		if (x != dda.y && y != dda.y)
		{
			return(1);
		}
	}
	return (0);
}

void	display_ray(float wallheight, t_vars *vars)
{
	int	j;

	j = 0;
	while (j < WIN_WIDTH)
	{
		if (j < (400 - wallheight))
			my_mlx_M_PIxel_put(&vars->img, vars->i, j, 0x0000FF);
		else if (j >= (400 - wallheight) && j <= (400 + wallheight))
			my_mlx_M_PIxel_put(&vars->img, vars->i, j, 0xFF0000);
		else
			my_mlx_M_PIxel_put(&vars->img, vars->i, j, 0x964B00);
		j++;
	}
}

void	calculate_wall_height(t_dda dda, t_point a, t_vars *vars)
{
	float	distance;
	float	plandist;
	float	wallheight;
	
	//a.x -= dda.xinc;
	//a.y -= dda.yinc;
	distance = sqrt((a.x - dda.ix) * (a.x - dda.ix)
			+ (a.y - dda.iy) * (a.y - dda.iy));
	distance = distance * cos(vars->rayangle * M_PI / 180);
	plandist = 400 / tan(30 * M_PI / 180);
	wallheight = (32 / distance) * plandist;
	if (!distance || wallheight > WIN_WIDTH || wallheight < 0)
		wallheight = WIN_WIDTH;
	display_ray(wallheight / 2, vars);
}

void	calculate_intersection(t_vars *vars, t_point *a, t_dda dda)
{
	int	xin;
	int	yin;

	if (dda.xinc > 0)
		xin = 1;
	else
		xin = -1;
	if (dda.yinc > 0)
		yin = 1;
	else
		yin = -1;
	a->x -= dda.xinc;
	a->y -= dda.yinc;
	dda.x = a->x / 32;
	dda.y = a->y / 32;
	if(vars->map[dda.y + yin][dda.x] == '1' && vars->map[dda.y][dda.x + xin] == 1)
		return;
	else if(vars->map[dda.y + yin][dda.x] == '1')
	{
		a->x = vars->x1;
		a->y = a->y + (abs(vars->y1 - dda.y * 32)) * tan(vars->rayangle * M_PI / 180);
	}
	else if (vars->map[dda.y][dda.x + xin] == '1')
	{
		a->y = vars->y;
		a->x = a->x + (abs(vars->x1 - dda.x * 32)) * tan(vars->rayangle * M_PI / 180);
	}
}

void	dda(t_vars *vars, t_point a, t_point b)
{
	t_dda	dda;

	dda.x = a.x / 32;
	dda.ix = a.x;
	dda.y = a.y / 32;
	dda.iy = a.y;
	if (abs((int)(b.x - a.x)) > abs((int)(b.y - a.y)))
		dda.steps = abs((int)(b.x - a.x));
	else
		dda.steps = abs((int)(b.y - a.y));
	dda.yinc = (int)(b.y - a.y) / (float) dda.steps;
	dda.xinc = (int)(b.x - a.x) / (float) dda.steps;
	while (vars->map[dda.y][dda.x] != '1')
	{
		a.x += dda.xinc;
		a.y += dda.yinc;
		//if (position_check(vars, dda, &a))
		//	return ;
		dda.x = a.x / 32;
		dda.y = a.y / 32;
	}
	calculate_wall_height(dda, a, vars);
}
