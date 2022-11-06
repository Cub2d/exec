/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:16:59 by cjad              #+#    #+#             */
/*   Updated: 2022/11/06 18:28:12 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	player_direction(t_vars *vars, t_point a, t_point b)
{
	double	xinc;
	double	yinc;
	int		steps;
	int		i;

	if (abs((int)(b.x - a.x)) > abs((int)(b.y - a.y)))
		steps = abs((int)(b.x - a.x));
	else
		steps = abs((int)(b.y - a.y));
	i = 1;
	xinc = (int)(b.x - a.x) / (float) steps;
	yinc = (int)(b.y - a.y) / (float) steps;
	while (i < steps)
	{
		my_mlx_pixel_put(&vars->img, a.x, a.y, 0xFF0000);
		a.x += xinc;
		a.y += yinc;
		i++;
	}
}
