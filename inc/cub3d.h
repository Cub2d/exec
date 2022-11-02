/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:03:21 by cjad              #+#    #+#             */
/*   Updated: 2022/11/02 15:31:09 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <math.h>
# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_gnl {
	char	c;
	char	*str;
	int		read_return;
	char	*temp;
}				t_gnl;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_M_PIxel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	int		height;
	int		width;
	int		face;
	int		side;
	char	*av;
	float	x1;
	float	y1;
	int		angle;
	int		s;
	int		f;
	char	**map;
	int		lines;
	t_data	img;
}				t_vars;

typedef struct s_point {
	float	x;
	float	y;
}	t_point;
typedef struct s_dda {
	float	xinc;
	float	yinc;
	int		x;
	int		y;
	int		ix;
	int		iy;
	int		steps;
}				t_dda;

int		keys_hook(int key, t_vars *vars);
void	rays(t_vars *vars);
void	dda(t_vars *vars, t_point a, t_point b);
void	my_mlx_M_PIxel_put(t_data *data, int x, int y, int color);
t_point	new_point(float x, float y);
void	ft_line_counter(t_vars *vars);
void	calculation(t_vars *vars, int left, int right);
void	put_tiles(t_vars *vars, int x, int y, int color);
void	map_maker(t_vars *vars);
void	ft_putstr(char *str);
char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
void	parse_map(t_vars *vars);
#endif