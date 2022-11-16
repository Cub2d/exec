/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zihirri <zihirri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:06:12 by zihirri           #+#    #+#             */
/*   Updated: 2022/11/16 19:18:28 by zihirri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// Initialize the map structure 
t_txt	*init_txt(void)
{
	t_txt	*txt;

	txt = malloc(sizeof(t_txt));
	if (!txt)
		return (NULL);
	txt->spawn_pos = NULL;
	txt->no = NULL;
	txt->so = NULL;
	txt->we = NULL;
	txt->ea = NULL;
	txt->f = NULL;
	txt->c = NULL;
	txt->map = NULL;
	txt->fill = 0;
	txt->counter = 0;
	txt->fcolor = 0;
	txt->ccolor = 0;
	txt->length = 0;
	txt->x = 1;
	txt->y = 0;
	txt->r = 0;
	txt->g = 0;
	txt->b = 0;
	return (txt);
}

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
	printf("%d %d\n", t->x, t->y);
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
