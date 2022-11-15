/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:28:15 by cjad              #+#    #+#             */
/*   Updated: 2022/11/15 16:47:31 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	put_texture(t_vars *vars, t_data *tex, int j, int x)
{
	int	*color;
	int	imgy;
	int	imgx;

	imgy = j + (vars->wallheight / 2) - WIN_WIDTH_2;
	imgy *= (tex->height / vars->wallheight);
	imgx = x % tex->width;
	color = (int *)(tex->addr
			+ (imgy * tex->line_length + imgx * (tex->bpp / 8)));
	my_mlx_pixel_put(&vars->img, vars->i, j, *color);
}

void	wall_color(t_vars *vars, int j, t_point a)
{
	if (vars->hor)
	{
		if (vars->rayface > 0)
			put_texture(vars, &vars->so, j, a.x);
		else
			put_texture(vars, &vars->no, j, a.x);
	}
	if (vars->vert)
	{
		if (vars->rayside > 0)
			put_texture(vars, &vars->ea, j, a.y);
		else
			put_texture(vars, &vars->we, j, a.y);
	}
}

void	display_ray(double wallheight, t_vars *vars, t_point a)
{
	int	j;

	j = 0;
	while (j < WIN_WIDTH)
	{
		if (j < (WIN_WIDTH_2 - wallheight))
			my_mlx_pixel_put(&vars->img, vars->i, j, vars->txt->ccolor);
		else if (j >= (WIN_WIDTH_2 - wallheight)
			&& j <= (WIN_WIDTH_2 + wallheight))
			wall_color(vars, j, a);
		else
			my_mlx_pixel_put(&vars->img, vars->i, j, vars->txt->fcolor);
		j++;
	}
}
