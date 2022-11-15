/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:02:36 by cjad              #+#    #+#             */
/*   Updated: 2022/11/15 17:05:06 by cjad             ###   ########.fr       */
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
		str = get_next_line(fd);
	}
	txt->map = (char **)malloc(sizeof(char **) * (txt->counter + 1));
	txt->map[0] = NULL;
	txt->map[txt->counter] = NULL;
	txt->height = txt->counter;
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

void	check_map(t_txt *txt)
{
	int	size;

	size = txt->counter;
	check_first_last(txt);
	while (txt->x < size - 1)
	{
		while (txt->map[txt->x][txt->y])
		{
			if (txt->map[txt->x][txt->y] == 'N' || txt->map[txt->x][txt->y] == 'S'
				|| txt->map[txt->x][txt->y] == 'E' || txt->map[txt->x][txt->y] == 'W'
				|| txt->map[txt->x][txt->y] == '1' || txt->map[txt->x][txt->y] == '0'
				|| txt->map[txt->x][txt->y] == ' ')
			{
				if (txt->map[txt->x][txt->y] == 'N' || txt->map[txt->x][txt->y] == 'S'
					|| txt->map[txt->x][txt->y] == 'E' || txt->map[txt->x][txt->y] == 'W')
					check_set_pos(txt);
				if (txt->map[txt->x][txt->y] == '0')
					check_zero(txt);
				txt->y++;
			}
			else
				ft_error("incorrect element");
		}
		txt->x++;
		if (txt->y > txt->length)
			txt->length = txt->y;
		txt->y = 0;
	}
	if (txt->spawn_pos == NULL)
		ft_error("There is no starting point");
}
