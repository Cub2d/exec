/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zihirri <zihirri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:06:12 by zihirri           #+#    #+#             */
/*   Updated: 2022/11/15 15:20:40 by zihirri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	check_set_pos(t_txt *t)
{
	if ((t->map[t->x][t->y + 1] != '0' && t->map[t->x][t->y + 1] != '1' )
		|| (t->map[t->x][t->y + 1] != '0' && t->map[t->x][t->y + 1] != '1')
		|| (t->map[t->x - 1][t->y] != '0' && t->map[t->x - 1][t->y] != '1')
		|| (t->map[t->x + 1][t->y] != '0' && t->map[t->x + 1][t->y] != '1'))
		ft_error("Player's position is wrong");
	else if (t->spawn_pos == NULL)
		t->spawn_pos = &t->map[t->x][t->y];
	else
		ft_error("No more than 1 spawn position");
}

void	check_zero(t_txt *t)
{
	if ((t->map[t->x][t->y + 1] != '0' && t->map[t->x][t->y + 1] != '1'
		&& t->map[t->x][t->y + 1] != 'N' && t->map[t->x][t->y + 1] != 'S'
		&& t->map[t->x][t->y + 1] != 'W' && t->map[t->x][t->y + 1] != 'E')
		|| (t->map[t->x][t->y - 1] != '0' && t->map[t->x][t->y - 1] != '1'
		&& t->map[t->x][t->y - 1] != 'N' && t->map[t->x][t->y - 1] != 'S'
		&& t->map[t->x][t->y - 1] != 'W' && t->map[t->x][t->y - 1] != 'E')
		|| (t->map[t->x - 1][t->y] != '0' && t->map[t->x - 1][t->y] != '1'
		&& t->map[t->x - 1][t->y] != 'N' && t->map[t->x - 1][t->y] != 'S'
		&& t->map[t->x - 1][t->y] != 'W' && t->map[t->x - 1][t->y] != 'E')
		|| (t->map[t->x + 1][t->y] != '0' && t->map[t->x + 1][t->y] != '1'
		&& t->map[t->x + 1][t->y] != 'N' && t->map[t->x + 1][t->y] != 'S'
		&& t->map[t->x + 1][t->y] != 'W' && t->map[t->x + 1][t->y] != 'E'))
		ft_error("MAP INCOHERENCE");
}
