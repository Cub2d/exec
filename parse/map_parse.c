/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:51:28 by zihirri           #+#    #+#             */
/*   Updated: 2022/11/15 17:08:52 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	get_texture(t_txt *text, char *str)
{
	char	**split;

	split = NULL;
	if (text->no == NULL || text->so == NULL
		|| text->ea == NULL || text->we == NULL
		|| text->c == NULL || text->f == NULL || text->map[0] == NULL)
				str = skip_whitespace(str);
	if (ft_strncmp(str, "NO ", 3) == 0)
		fill_no(split, text, str);
	else if (ft_strncmp(str, "SO ", 3) == 0)
		fill_so(split, text, str);
	else if (ft_strncmp(str, "WE ", 3) == 0)
		fill_we(split, text, str);
	else if (ft_strncmp(str, "EA ", 3) == 0)
		fill_ea(split, text, str);
	else if (ft_strncmp(str, "F ", 2) == 0 || ft_strncmp(str, "C ", 2) == 0)
		get_color(text, str);
	else if (str[0] == '\0' && text->map[0] == NULL)
		return ;
	else if (str[0] == '1' || check_space(str) == OK)
	{
		text->map[text->fill] = str;
		text->fill++;
	}
	else if (str[0] == ' ')
		return ;
	else if (text->fill == text->counter)
		return ;
	else
		ft_error("Invalid Map Here");
}

void	check_if_filled(t_txt *txt)
{
	if (txt->no == NULL || txt->so == NULL
		|| txt->ea == NULL || txt->we == NULL
		|| txt->c == NULL || txt->f == NULL)
		ft_error("Missing texture or color!");
	else
		return ;
}

// Checks if all the attributes were filled
int	check_if_filled_v2(t_txt *txt)
{
	if (txt->no == NULL || txt->so == NULL
		|| txt->ea == NULL || txt->we == NULL
		|| txt->c == NULL || txt->f == NULL)
		return (KO);
	else
		return (OK);
}

// Checks if the input files ends the .cub extention
int	file_extention(char *s)
{
	char	*point;

	point = ft_strrchr(s, '.');
	if (point != NULL)
	{
		if (ft_strcmp(point, ".cub") != 0)
			ft_error("Check the file's path");
	}
	return (0);
}

// GO!
void	map(t_txt **txt , char *s)
{
	int		fd;
	char	*str;

	file_extention(s);
	map_counter(*txt, s);
	fd = open(s, O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		get_texture(*txt, str);
		str = get_next_line(fd);
	}
	check_if_filled(*txt);
	free(str);
}

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

// int main(int ac, char **av){
// 	t_txt	*txt;

// 	txt = init_txt();
// 	if (ac == 2)
// 	{
// 		map(&txt, av[1]);
// 		check_map(txt);
// 	}
// 	else
// 	{
// 		printf("Error\nCheck your arguments !");
// 		free(txt);
// 	}
// 	free(txt);
// 	return (0);
// }