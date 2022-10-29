/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algho.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:54:00 by cjad              #+#    #+#             */
/*   Updated: 2022/10/29 17:06:28 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	linehorizontal(t_data	*img, int x1, int x2, int y)
{
	int	min;
	int	max;

	if (x1 > x2)
	{
		min = x2;
		max = x1;
	}
	else
	{
		min = x1;
		max = x2;
	}
	while (min <= max)
	{
		my_mlx_M_PIxel_put(img, min, y, 0xFF0000);
		min++;
	}
}

void	circle_draw(t_data *img, int x_centre, int y_centre, int x)
{
	int	y;
	int	p;

	y = 0;
	p = -9;
	linehorizontal(img, -x + x_centre, x + x_centre, y + y_centre);
	while (x > y)
	{
		y++;
		if (p <= 0)
			p = p + 2 * y + 1;
		else
		{
			x--;
			p = p + 2 * y - 2 * x + 1;
		}
		linehorizontal(img, -x + x_centre, x + x_centre, y + y_centre);
		linehorizontal(img, -x + x_centre, x + x_centre, -y + y_centre);
		if (x != y)
		{
			linehorizontal(img, -y + x_centre, y + x_centre, x + y_centre);
			linehorizontal(img, -y + x_centre, y + x_centre, -x + y_centre);
		}
	}
}

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

void	dda(t_vars *vars, t_point a, t_point b)
{
	t_dda	dda;

	dda.x = a.x / 32;
	dda.y = a.y / 32;
	if (abs((int)(b.x - a.x)) > abs((int)(b.y - a.y)))
		dda.steps = abs((int)(b.x - a.x));
	else
		dda.steps = abs((int)(b.y - a.y));
	dda.xinc = (int)(b.x - a.x) / (float) dda.steps;
	dda.yinc = (int)(b.y - a.y) / (float) dda.steps;
	while (vars->map[dda.y][dda.x] != '1')
	{
		my_mlx_M_PIxel_put(&vars->img, a.x, a.y, 0xFF0000);
		a.x += dda.xinc;
		a.y += dda.yinc;
		if (position_check(vars, dda, a))
			return ;
		dda.x = a.x / 32;
		dda.y = a.y / 32;
	}
}
