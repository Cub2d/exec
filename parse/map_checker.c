/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zihirri <zihirri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:02:36 by cjad              #+#    #+#             */
/*   Updated: 2022/11/18 20:14:38 by zihirri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// Counts the map lines then allocate memortxt->y to it
void	map_counter(t_txt *txt, char *s)
{
	int		fd;
	char	*str;

	fd = open(s, O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		if ((str[0] == '1' || check_space(str) == OK))
			txt->counter++;
		free(str);
		str = get_next_line(fd);
	}
	txt->map = (char **)malloc(sizeof(char **) * (txt->counter + 1));
	if (!(txt->map))
		return ;
	txt->map[0] = NULL;
	txt->map[txt->counter] = NULL;
	txt->height = txt->counter;
	close(fd);
	free(str);
}

void	check_first_last(t_txt *txt)
{
	int	i;
	int	size;

	size = txt->counter - 1;
	i = 0;
	while (txt->map[0][i])
	{
		if (txt->map[0][i] != '1' && txt->map[0][i] != ' ')
			ft_error("Please check your map again");
		i++;
	}
	txt->length = i;
	i = 0;
	while (txt->map[size][i])
	{
		if (txt->map[size][i] != '1' && txt->map[size][i] != ' ')
			ft_error("Please check your map again");
		i++;
	}
	if (i > txt->length)
		txt->length = i;
}

void	check_map_start(t_txt *txt)
{
	if (is_mapchar(txt->map[txt->x][txt->y]))
	{
		if (is_playerchar(txt->map[txt->x][txt->y]))
			check_set_pos(txt);
		if (txt->map[txt->x][txt->y] == '0')
			check_zero(txt);
		txt->y++;
	}
	else
		ft_error("Incorrect element");
}

void	check_map(t_txt *txt)
{
	int	size;

	size = txt->counter;
	check_first_last(txt);
	while (txt->x < size - 1)
	{
		while (txt->map[txt->x][txt->y])
			check_map_start(txt);
		txt->x++;
		if (txt->y > txt->length)
			txt->length = txt->y;
		txt->y = 0;
	}
	if (txt->spawn_pos == NULL)
		ft_error("There is no starting point");
}
