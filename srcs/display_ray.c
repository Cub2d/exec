/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:28:15 by cjad              #+#    #+#             */
/*   Updated: 2022/11/08 12:48:34 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	wall_color(t_vars *vars, int j)
{
	if (vars->hor)
	{
		if (vars->rayface > 0)
			my_mlx_pixel_put(&vars->img, vars->i, j, 0x919191);
		else
			my_mlx_pixel_put(&vars->img, vars->i, j, 0xBEBEBE);
	}
	if (vars->vert)
	{
		if (vars->rayside > 0)
			my_mlx_pixel_put(&vars->img, vars->i, j, 0x007cdb);
		else
			my_mlx_pixel_put(&vars->img, vars->i, j, 0x0061ad);
	}
}

void	display_ray(double wallheight, t_vars *vars)
{
	double	j;

	j = 0;
	while (j < WIN_WIDTH)
	{
		if (j < (WIN_WIDTH_2 - wallheight))
			my_mlx_pixel_put(&vars->img, vars->i, j, 0x00008b);
		else if (j >= (WIN_WIDTH_2 - wallheight)
			&& j <= (WIN_WIDTH_2 + wallheight))
			wall_color(vars, j);
		else
			my_mlx_pixel_put(&vars->img, vars->i, j, 0x414141);
		j++;
	}
}
