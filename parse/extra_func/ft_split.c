/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zihirri <zihirri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:02:12 by zihirri           #+#    #+#             */
/*   Updated: 2022/11/15 15:48:18 by zihirri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	calculate_len(char  *s, char c)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			len++;
		i++;
	}
	if (s[i - 1] == c)
		len--;
	if (s[0] != c)
		len++;
	return (len);
}

static char	*getstring(char  *str, char c)
{
	int		i;
	char	*mystr;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	mystr = (char *) malloc(sizeof(char) * (i + 1));
	if (mystr == NULL)
		return (NULL);
	i = 0;
	while (str[i] != c && str[i] != '\0')
	{
		mystr[i] = str[i];
		i++;
	}
	mystr[i] = '\0';
	return (mystr);
}

static int	process(char **strs, char  *s, char c)
{
	int		i;
	int		k;
	char	*str;

	i = 0;
	k = 0;
	while (s[i])
	{
		if ((s[i] != c && i == 0) || (i > 0 && s[i] != c && s[i - 1] == c))
		{
			str = getstring(s + i, c);
			if (str == NULL)
				return (0);
			strs[k++] = str;
		}
		i++;
	}
	strs[k] = 0;
	return (1);
}

void	free_all(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

char	**ft_split(char  *s, char c)
{
	char	**strs;
	int		len;
	int		res;

	res = 0;
	if (!s)
		return (NULL);
	len = calculate_len(s, c);
	strs = (char **) malloc(sizeof(char *) * (len + 1));
	if (!strs)
		return (NULL);
	res = process(strs, s, c);
	if (res)
		return (strs);
	free_all(strs);
	strs = NULL;
	return (NULL);
}
