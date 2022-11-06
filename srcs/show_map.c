/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:44:54 by cjad              #+#    #+#             */
/*   Updated: 2022/11/06 17:36:22 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

t_point	closest_wall(t_vars *vars, double castangle)
{
	t_point	hd;
	t_point	vd;

	hd = horizontal_point(vars, castangle);
	vd = vertical_point(vars, castangle);
	if (distance_to_point(vars, hd) > distance_to_point(vars, vd))
	{
		vars->vert = 1;
		return (vd);
	}
	else
	{
		vars->hor = 1;
		return (hd);
	}
}

void	calculation(t_vars *vars, int left, int right)
{
	double		castangle;
	double		end;

	castangle = left;
	end = right;
	vars->i = 0;
	mlx_clear_window(vars->mlx, vars->win);
	while (castangle < right && vars->i < WIN_WIDTH)
	{
		vars->hor = 0;
		vars->vert = 0;
		vars->rayangle = fabs(vars->angle - castangle);
		calculate_wall_height(closest_wall(vars, castangle), vars);
		vars->castangle = castangle;
		castangle += 0.05;
		vars->i++;
	}
	if (vars->mini)
		print_minimap(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

void	check_player_position(t_vars *vars, int a, int b)
{
	char	c;

	c = vars->map[a][b];
	if (c == 'E' || c == 'N' || c == 'W' || c == 'S')
	{
		if (c == 'E')
			vars->angle = 180;
		if (c == 'N')
			vars->angle = 270;
		if (c == 'W')
			vars->angle = 0;
		if (c == 'S')
			vars->angle = 90;
		vars->map[a][b] = '0';
		vars->x = b * TILE + TILE_2;
		vars->y = a * TILE + TILE_2;
	}
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
			check_player_position(vars, a, b);
			b++;
		}
		a++;
	}
	if (vars->angle >= 0 && vars->angle <= 180)
		vars->face = 1;
	else
		vars->face = -1;
	if (vars->angle >= 90 && vars->angle <= 270)
		vars->side = -1;
	else
		vars->side = 1;
}
