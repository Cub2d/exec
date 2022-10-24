/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:40:48 by cjad              #+#    #+#             */
/*   Updated: 2022/10/24 12:39:01 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	salam(void)
{
	exit(1);
	return (0);
}

t_point	new_point(float x, float y)
{
	t_point	a;

	a.x = x;
	a.y = y;
	return (a);
}

void	rays(t_vars *vars)
{
	int	right;
	int	left;

	if (vars->angle + 30 > 360)
		right = 30 - (360 - vars->angle);
	else
		right = vars->angle + 30;
	if (vars->angle - 30 < 0)
		left = 360 - (30 - vars->angle);
	else
		left = vars->angle - 30;
	map_maker(vars);
	calculation(vars, left, right);
}

int	main(int ac, char **av)
{
	t_vars	vars;
	t_data	img;

	(void)ac;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1024, 352, "cub3d");
	img.img = mlx_new_image(vars.mlx, 1024, 352);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	vars.angle = 180;
	vars.img = img;
	vars.av = av[1];
	parse_map(&vars);
	rays(&vars);
	mlx_hook(vars.win, 17, 0, salam, &vars);
	mlx_hook(vars.win, 2, 0, keys_hook, &vars);
	mlx_loop(vars.mlx);
}
