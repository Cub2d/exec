/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 11:41:20 by cjad              #+#    #+#             */
/*   Updated: 2022/11/07 13:16:34 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	put_tiles(t_vars *vars, int x, int y, int color)
{
	int	n;
	int	m;

	n = x;
	m = y;
	while (n < x + M_SCALE)
	{
		m = y;
		while (m < y + M_SCALE)
		{
			my_mlx_pixel_put(&vars->img, n, m, color);
			m++;
		}
		n++;
	}
}

void	print_minimap(t_vars *vars)
{
	int		a;
	int		b;
	double	x;
	double	y;

	a = 0;
	while (vars->map[a])
	{
		b = 0;
		while (vars->map[a][b])
		{
			if (vars->map[a][b] == '1')
				put_tiles(vars, b * M_SCALE, a * M_SCALE, 0x8E8E8E);
			if (vars->map[a][b] == '0')
				put_tiles(vars, b * M_SCALE, a * M_SCALE, 0x000000);
			b++;
		}
		a++;
	}
	circle_draw(vars, vars->x / 6.4, vars->y / 6.4, 3);
	x = vars->x / 6.4 + (8 * cos(vars->angle * M_PI / 180));
	y = vars->y / 6.4 + (8 * sin(vars->angle * M_PI / 180));
	water_drop(vars, new_p(x, y));
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}
