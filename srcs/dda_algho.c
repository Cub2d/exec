/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algho.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:54:00 by cjad              #+#    #+#             */
/*   Updated: 2022/11/02 18:03:48 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	position_check(t_vars *vars, t_dda dda, t_point	a)
{
	int	x;
	int	y;
	int	xin;
	int	yin;

	x = a.x / 32;
	y = a.y / 32;
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
			return (1);
	}
	return (0);
}

void	display_ray(int wallheight, t_vars *vars)
{
	static int i;
	int j;
	
	j = 0;
	while (j < 480)
	{
		if (j < (240 - wallheight))
			my_mlx_M_PIxel_put(&vars->img, i, j, 0x0000FF);
		else if (j >= (240 - wallheight) && j <= (240 + wallheight))
			my_mlx_M_PIxel_put(&vars->img, i, j, 0xFF0000);
		else 
			my_mlx_M_PIxel_put(&vars->img, i, j, 0x964B00);
		j++;
	}
	i++;
	if(i == 480)
		i = 0;

}

void	calculate_wall_height(t_dda dda, t_point a, t_vars *vars)
{
	float	distance;
	float	plandist;
	int		wallheight;
	
	a.x -= dda.xinc;
	a.y -= dda.yinc;
	distance = sqrt((a.x - dda.ix) * (a.x - dda.ix) + (a.y - dda.iy) * (a.y - dda.iy));
	plandist = 240 / tan(30 * M_PI / 180);
	wallheight = (32 / distance) * plandist;
	if (!distance || wallheight > 480)
		wallheight = 480;
	display_ray(wallheight / 2, vars);
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
	dda.xinc = (int)(b.x - a.x) / (float) dda.steps;
	dda.yinc = (int)(b.y - a.y) / (float) dda.steps;
	while (vars->map[dda.y][dda.x] != '1')
	{
		//my_mlx_M_PIxel_put(&vars->img, a.x, a.y, 0xFF0000);
		a.x += dda.xinc;
		a.y += dda.yinc;
		if (position_check(vars, dda, a))
			return ;
		dda.x = a.x / 32;
		dda.y = a.y / 32;
	}
	calculate_wall_height(dda, a, vars);
}
