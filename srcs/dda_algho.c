/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algho.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:54:00 by cjad              #+#    #+#             */
/*   Updated: 2022/10/24 12:39:01 by cjad             ###   ########.fr       */
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
		my_mlx_pixel_put(img, min, y, 0xFF0000);
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

void	dda(t_vars *vars, t_point a, t_point b)
{
	float	xinc;
	float	yinc;
	int		steps;
	int		x;
	int		y;

	x = a.x / 32;
	y = a.y / 32;
	circle_draw(&vars->img, a.x, a.y, 5);
	if (abs((int)(b.x - a.x)) > abs((int)(b.y - a.y)))
		steps = abs((int)(b.x - a.x));
	else
		steps = abs((int)(b.y - a.y));
	xinc = (int)(b.x - a.x) / (float) steps;
	yinc = (int)(b.y - a.y) / (float) steps;
	while (vars->map[y][x] != '1')
	{
		my_mlx_pixel_put(&vars->img, a.x, a.y, 0xFF0000);
		a.x += xinc;
		a.y += yinc;
		x = a.x / 32;
		y = a.y / 32;
	}
}
