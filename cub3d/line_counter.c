/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_counter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:40:27 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/10/18 15:11:34 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	map_maker(t_vars *vars)
{
	int	b;
	int i;
	int j;
	int a;

	a = 0;
	j = 0;
	while (vars->map[a])
	{
		b = 0;
		i = 0;
		while (vars->map[a][b])
		{
			if (vars->map[a][b] == '1')
				DrawSquare(vars, i, j, 0x8E8E8E);
			else if (vars->map[a][b] == '0')
				DrawSquare(vars, i, j, 0x000000);
			else if (vars->map[a][b] == 'E')
			{
				vars->map[a][b] = '0';
				//vars->x1 = j;
				//vars->y1 = i;
				DrawSquare(vars, i, j, 0x000000);
			}
			b++;
			i += 32;
		}
		a++;
		j += 32;
	}
}

void	ft_line_counter(t_vars *vars)
{
	char	*str;

	vars->mapa.fd = open(vars->mapa.av, O_RDONLY);
	vars->mapa.i[0] = 0;
	if (vars->mapa.fd < 0)
	{
		ft_putstr("Error\nmap name is unacceptable\n");
		exit(1);
	}
	str = get_next_line(vars->mapa.fd);
	if (str)
		vars->mapa.i[1] = ft_strlen(str);
	else
	{
		printf("Error 404\n");
		free(str);
		exit(1);
	}
	while (str)
	{
		vars->mapa.height++;
		free (str);
		vars->mapa.i[0] += 50;
		str = get_next_line(vars->mapa.fd);
	}
	free(str);
	close(vars->mapa.fd);
}

void ft_fill_map(t_vars *vars)
{
	int i;
	int fd;

	fd = open(vars->mapa.av, O_RDONLY);
	i = 0;
	while (i < vars->mapa.height)
	{
		vars->map[i] = get_next_line(fd);
		i++;
	}
	vars->map[vars->mapa.height] = NULL;
}

void	Show_Map(t_vars *vars)
{
	vars->mapa.height = 0;
	ft_line_counter(vars);
	vars->map = malloc (sizeof(char *) * (vars->mapa.height + 1));
	ft_fill_map(vars);
	map_maker(vars);
}