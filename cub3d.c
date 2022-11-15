/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zihirri <zihirri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:40:48 by cjad              #+#    #+#             */
/*   Updated: 2022/11/15 15:58:57 by zihirri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/cub3d.h"

int	esc(void)
{
	exit(1);
	return (0);
}

t_point	new_p(double x, double y)
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

	right = vars->angle + 30;
	left = vars->angle - 30;
	calculation(vars, left, right);
}

int	mouse_rotate(int x, int y, t_vars *vars)
{
	(void) y;
	if (!vars->mouse)
		vars->mouse = x;
	if (x > vars->mouse)
		rotate_right(vars, x - vars->mouse);
	else if (x < vars->mouse)
		rotate_left(vars, vars->mouse - x);
	vars->mouse = x;
	return (0);
}

void	init_textures(t_vars *vars)
{
	vars->so.img = mlx_xpm_file_to_image(vars->mlx, vars->txt->so,
			&vars->so.height, &vars->so.width);
	vars->so.addr = mlx_get_data_addr(vars->so.img, &vars->so.bpp,
			&vars->so.line_length, &vars->so.endian);
	vars->we.img = mlx_xpm_file_to_image(vars->mlx, vars->txt->we,
			&vars->we.height, &vars->we.width);
	vars->we.addr = mlx_get_data_addr(vars->we.img, &vars->we.bpp,
			&vars->we.line_length, &vars->we.endian);
	vars->no.img = mlx_xpm_file_to_image(vars->mlx, vars->txt->no,
			&vars->no.height, &vars->no.width);
	vars->no.addr = mlx_get_data_addr(vars->no.img, &vars->no.bpp,
			&vars->no.line_length, &vars->no.endian);
	vars->ea.img = mlx_xpm_file_to_image(vars->mlx, vars->txt->ea,
			&vars->ea.height, &vars->ea.width);
	vars->ea.addr = mlx_get_data_addr(vars->ea.img, &vars->ea.bpp,
			&vars->ea.line_length, &vars->ea.endian);
}

void	initialization(t_vars *vars, char **av)
{
	vars->txt = init_txt();
	map(&vars->txt, av[1]);
	check_map(vars->txt);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIN_WIDTH, WIN_WIDTH, "cub3d");
	vars->img.img = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_WIDTH);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bpp,
			&vars->img.line_length, &vars->img.endian);
	init_textures(vars);
	vars->mouse = 0;
	vars->av = av[1];
	map_maker(vars);
	if (vars->height * M_SCALE > WIN_WIDTH || vars->width * M_SCALE > WIN_WIDTH)
	{
		write(1, "Cannot show mini map due to large map scaling\n", 47);
		vars->mini = 0;
	}
	else
		vars->mini = 1;
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac == 2)
	{
		initialization(&vars, av);
		rays(&vars);
		mlx_hook(vars.win, 17, 0, esc, &vars);
		mlx_hook(vars.win, 6, 0, mouse_rotate, &vars);
		mlx_hook(vars.win, 2, 0, keys_hook, &vars);
		mlx_loop(vars.mlx);
	}
}
