/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_circle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 11:59:56 by cjad              #+#    #+#             */
/*   Updated: 2022/11/06 13:29:56 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	linehorizontal(t_vars *vars, int x1, int x2, int y)
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
		my_mlx_pixel_put(&vars->img, min, y, 0xFF0000);
		min++;
	}
}

void	circle_draw(t_vars *vars, int x_centre, int y_centre, int x)
{
	int	y;
	int	p;

	y = 0;
	p = 1 - x;
	linehorizontal(vars, -x + x_centre, x + x_centre, y + y_centre);
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
		linehorizontal(vars, -x + x_centre, x + x_centre, y + y_centre);
		linehorizontal(vars, -x + x_centre, x + x_centre, -y + y_centre);
		if (x != y)
		{
			linehorizontal(vars, -y + x_centre, y + x_centre, x + y_centre);
			linehorizontal(vars, -y + x_centre, y + x_centre, -x + y_centre);
		}
	}
}
