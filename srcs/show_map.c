/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:44:54 by cjad              #+#    #+#             */
/*   Updated: 2022/10/29 17:08:18 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	put_tiles(t_vars *vars, int x, int y, int color)
{
	int	n;
	int	m;

	n = x;
	m = y;
	while (n < x + 32)
	{
		m = y;
		while (m < y + 32)
		{
			my_mlx_M_PIxel_put(&vars->img, n, m, color);
			m++;
		}
		n++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

void	my_mlx_M_PIxel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	(void)color;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_M_PIxel / 8));
	*(unsigned int *)dst = color;
}

void	calculation(t_vars *vars, int left, int right)
{

	float			x;
	float			y;
	float			start;
	float			end;

	start = left;
	end = right;
	circle_draw(&vars->img, vars->x1, vars->y1, 5);
	while (start <= left + 60)
	{
		x = vars->x1 + (100 * cos(start * M_PI / 180));
		y = vars->y1 + (100 * sin(start * M_PI / 180));
		dda(vars, new_point(vars->x1, vars->y1), new_point(x, y));
		start += 0.125;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

void	map_maker(t_vars *vars)
{
	int	b;
	int	a;

	a = 0;
	while (vars->map[a])
	{
		b = 0;
		while (vars->map[a][b])
		{
			if (vars->map[a][b] == '1')
				put_tiles(vars, b * 32, a * 32, 0x8E8E8E);
			else if (vars->map[a][b] == '0')
				put_tiles(vars, b * 32, a * 32, 0x000000);
			else if (vars->map[a][b] == 'E')
			{
				vars->map[a][b] = '0';
				vars->x1 = b * 32 + 16;
				vars->y1 = a * 32 + 16;
				put_tiles(vars, b * 32, a * 32, 0x000000);
			}
			b++;
		}
		a++;
	}
}
