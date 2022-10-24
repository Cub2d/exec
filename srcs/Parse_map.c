/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:50:41 by cjad              #+#    #+#             */
/*   Updated: 2022/10/24 12:39:01 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_strcmp(char *str)
{
	char	*s1;
	char	*s2;
	int		i;

	s1 = &str[ft_strlen(str) - 4];
	s2 = ".ber";
	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	ft_line_counter(t_vars *vars)
{
	char	*str;
	int		fd;
	int		height;

	fd = open(vars->av, O_RDONLY);
	height = 0;
	str = get_next_line(fd);
	if (str)
		vars->width = ft_strlen(str);
	else
	{
		printf("Error 404\n");
		free(str);
		exit(1);
	}
	while (str)
	{
		vars->height++;
		free (str);
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
}

void	ft_fill_map(t_vars *vars)
{
	int	i;
	int	fd;

	fd = open(vars->av, O_RDONLY);
	i = 0;
	while (i < vars->height)
	{
		vars->map[i] = get_next_line(fd);
		i++;
	}
	vars->map[i] = NULL;
}

void	parse_map(t_vars *vars)
{
	vars->height = 0;
	ft_line_counter(vars);
	vars->map = malloc (sizeof(char *) * (vars->height + 1));
	ft_fill_map(vars);
	map_maker(vars);
}
