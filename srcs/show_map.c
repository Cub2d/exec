/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:44:54 by cjad              #+#    #+#             */
/*   Updated: 2022/11/03 13:00:38 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// void	put_tiles(t_vars *vars, int x, int y, int color)
// {
// 	int	n;
// 	int	m;

// 	n = x;
// 	m = y;
// 	(void) color; 
// 	while (n < x + 32)
// 	{
// 		m = y;
// 		while (m < y + 32)
// 		{
// 			//my_mlx_M_PIxel_put(&vars->img, n, m, color);
// 			m++;
// 		}
// 		n++;
// 	}
// }

void	calculation(t_vars *vars, int left, int right)
{
	float			x;
	float			y;
	float			start;
	float			end;

	start = left;
	end = right;
	vars->i = 0;
	mlx_clear_window(vars->mlx, vars->win);
	while (start < right)
	{
		x = vars->x1 + (4800 * cos(start * M_PI / 180));
		y = vars->y1 + (4800 * sin(start * M_PI / 180));
		vars->rayangle = fabs(vars->angle - start);
		dda(vars, new_point(vars->x1, vars->y1), new_point(x, y));
		start += 0.125;
		vars->i++;
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
			//if (vars->map[a][b] == '1')
			// put_tiles(vars, b * 32, a * 32, 0x8E8E8E);
			//else if (vars->map[a][b] == '0')
			//	put_tiles(vars, b * 32, a * 32, 0x000000);
			if (vars->map[a][b] == 'E')
			{
				vars->map[a][b] = '0';
				vars->x1 = b * 32 + 16;
				vars->y1 = a * 32 + 16;
			//	put_tiles(vars, b * 32, a * 32, 0x000000);
			}
			b++;
		}
		a++;
	}
}
