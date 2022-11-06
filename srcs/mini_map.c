/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 11:41:20 by cjad              #+#    #+#             */
/*   Updated: 2022/11/06 15:26:09 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	put_tiles(t_vars *vars, int x, int y, int color)
{
	int	n;
	int	m;

	n = x;
	m = y;
	while (n < x + 8)
	{
		m = y;
		while (m < y + 8)
		{
			my_mlx_pixel_put(&vars->img, n, m, color);
			m++;
		}
		n++;
	}
}

void	print_minimap(t_vars *vars)
{
	int	a;
	int	b;

	a = 0;
	while (vars->map[a])
	{
		b = 0;
		while (vars->map[a][b])
		{
			if (vars->map[a][b] == '1')
				put_tiles(vars, b * 8, a * 8, 0x8E8E8E);
			if (vars->map[a][b] == '0')
				put_tiles(vars, b * 8, a * 8, 0x000000);
			b++;
		}
		a++;
	}
	circle_draw(vars, vars->x / 4, vars->y / 4, 1);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}
