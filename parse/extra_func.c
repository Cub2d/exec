/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zihirri <zihirri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:55:55 by zihirri           #+#    #+#             */
/*   Updated: 2022/11/16 15:11:12 by zihirri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

char	*skip_whitespace(char *str)
{
	int	n;

	n = 0;
	while (str[n] == '\f' || str[n] == '\n' || str[n] == 32
		|| str[n] == '\r' || str[n] == '\v' || str[n] == '\t')
		n++;
	return (str + n);
}

int	is_a_whitespace(char *str)
{
	int	n;

	n = 0;
	if (str[n] == '\f' || str[n] == '\n' || str[n] == 32
		|| str[n] == '\r' || str[n] == '\v' || str[n] == '\t')
		return (OK);
	return (KO);
}

// Fills the Floor and Ceilling color with its respective value
void	fill_f(char **split, t_txt *text, char *str)
{
	split = ft_split(str, ' ');
	if (text->f == NULL)
	{
		if (split[2] == NULL)
			text->f = split[1];
		else
		{
			ft_error("ERROR check the colors");
			free(split);
		}
	}
	else
		ft_error("ERROR tried to insert floor color twice or more");
}

void	fill_c(char **split, t_txt *text, char *str)
{
	split = ft_split(str, ' ');
	if (text->c == NULL)
	{
		if (split[2] == NULL)
			text->c = split[1];
		else
			ft_error("ERROR check the colors");
	}
	else
		ft_error("ERROR tried to insert ceilling color twice or more");
}

// Prevent the use of more or less than 2 commas in the color section
void	count_commas(char *str)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ',' && str[i + 1] == ',')
			ft_error("Two or more conssicutive commas in the color section");
		else if (str[i] == ',')
			counter++;
		i++;
	}
	if ((counter > 2 || counter < 2) || (str[i - 1] == ',' && str[i] == '\0'))
		ft_error("Wrong input in the color section");
}
