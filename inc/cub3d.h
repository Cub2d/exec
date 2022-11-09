/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:03:21 by cjad              #+#    #+#             */
/*   Updated: 2022/11/09 15:08:02 by cjad             ###   ########.fr       */
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
# define WIN_WIDTH 1200
# define WIN_WIDTH_2 600
# define ROTATE_SPEED 3
# define MOUVEMENT_SPEED 8
# define TILE 64
# define TILE_2 32
# define M_SCALE 10

typedef struct s_gnl {
	char	c;
	char	*str;
	int		read_return;
	char	*temp;
}				t_gnl;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		height;
	int 	width;
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
	int		vert;
	int		hor;
	int		rayface;
	int		rayside;
	int		angle;
	int		i;
	int		mouse;
	int		s;
	int		f;
	int		mini;
	int		lines;
	char	*av;
	char	**map;
	double	x;
	double	y;
	double	rayangle;
	double	castangle;
	double	wallheight;
	t_data	*img;
	t_data	*we;
	t_data	*ea;
	t_data	*so;
	t_data	*no;
}				t_vars;

typedef struct s_point {
	double	x;
	double	y;
}	t_point;
typedef struct s_dda {
	double	xinc;
	double	yinc;
	int		x;
	int		y;
	int		ix;
	int		iy;
	int		steps;
}				t_dda;

int		keys_hook(int key, t_vars *vars);
int		xin(t_vars *vars, double castangle);
int		yin(t_vars *vars, double castangle);
int		is_not_wall(t_vars *vars, double hx, double hy);
char	*get_next_line(int fd);
void	display_ray(double wallheight, t_vars *vars, t_point a);
void	water_drop(t_vars *vars, t_point a);
void	rotate_left(t_vars *vars, int speed);
void	rotate_right(t_vars *vars, int speed);
void	ft_line_counter(t_vars *vars);
void	player_direction(t_vars *vars, t_point a, t_point b);
void	print_minimap(t_vars *vars);
void	circle_draw(t_vars *vars, int x_centre, int y_centre, int x);
void	calculation(t_vars *vars, int left, int right);
void	put_tiles(t_vars *vars, int x, int y, int color);
void	map_maker(t_vars *vars);
void	ft_putstr(char *str);
void	rays(t_vars *vars);
void	dda(t_vars *vars, t_point a, t_point b);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	parse_map(t_vars *vars);
void	calculate_wall_height(t_point a, t_vars *vars);
double	distance_to_point(t_vars *vars, t_point a);
t_point	new_p(double x, double y);
t_point	vertical_point(t_vars *vars, double castangle);
t_point	horizontal_point(t_vars *vars, double castangle);
size_t	ft_strlen(char *str);

#endif