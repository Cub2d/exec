/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zihirri <zihirri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:03:21 by cjad              #+#    #+#             */
/*   Updated: 2022/11/20 14:45:36 by zihirri          ###   ########.fr       */
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
# define MOUVEMENT 12
# define TILE 64
# define TILE_2 32
# define M_SCALE 10

# define OK 0
# define KO 1

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		height;
	int		width;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_texture
{
	char	*spawn_pos;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	int		fcolor;
	int		ccolor;
	int		r;
	int		g;
	int		b;
	int		counter;
	char	**map;
	int		length;
	int		height;
	int		fill;
	int		x;
	int		y;
}			t_txt;

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
	t_data	img;
	t_data	we;
	t_data	ea;
	t_data	so;
	t_data	no;
	t_txt	*txt;
}				t_vars;

typedef struct s_point {
	double	x;
	double	y;
}	t_point;

t_point	new_p(double x, double y);
t_point	vertical_point(t_vars *vars, double castangle);
t_point	horizontal_point(t_vars *vars, double castangle);
size_t	ft_strlen(char *str);
double	distance_to_point(t_vars *vars, t_point a);
void	display_ray(double wallheight, t_vars *vars, t_point a);
void	water_drop(t_vars *vars, t_point a);
void	rotate_left(t_vars *vars, int speed);
void	rotate_right(t_vars *vars, int speed);
void	move_right(t_vars *vars);
void	move_left(t_vars *vars);
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
void	calculate_wall_height(t_point a, t_vars *vars);
int		keys_hook(int key, t_vars *vars);
int		xin(t_vars *vars, double castangle);
int		yin(t_vars *vars, double castangle);
int		is_not_wall(t_vars *vars, double hx, double hy);
int		esc(void);

// Map Parse
void	fill_no(char **split, t_txt *text, char *str);
void	fill_so(char **split, t_txt *text, char *str);
void	fill_ea(char **split, t_txt *text, char *str);
void	fill_we(char **split, t_txt *text, char *str);
void	get_color(t_txt *text, char *str);
void	checkalpha(char **str);
void	fill_f(char **split, t_txt *text, char *str);
void	fill_c(char **split, t_txt *text, char *str);
void	set_floor_color(t_txt *txt);
void	set_ceilling_color(t_txt *txt);
void	map_filler(t_txt *text, char *str);
void	count_commas(char *str);
void	ft_error(char *str);
void	map_counter(t_txt *txt, char *s);
void	check_map(t_txt *txt);
void	check_set_pos(t_txt *txt);
void	check_zero(t_txt *txt);
void	map(t_txt **txt, char *s);
void	get_colors(t_txt *text, char *str);
void	check_if_filled(t_txt *txt);
void	get_texture(t_txt *text, char *str);
void	check_textures(t_vars *vars);
char	*get_next_line(int fd);
char	*skip_whitespace(char *str);
int		is_a_whitespace(char *str);
int		check_if_filled_v2(t_txt *txt);
int		check_space(char *str);
int		file_extention(char *s);
int		check_if_filled_v2(t_txt *txt);
int		is_not_filled(t_txt *text);
void	get_rgb(t_txt *txt, int i, int convert);
t_txt	*init_txt(void);

// Extra Functions
char	*st_strjoin(char *s1, char c);
char	**ft_split(char *s, char c);
char	*ft_strchr(char *haystack, int needle);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strrchr(char *haystack, int needle);
char	*ft_substr(char *s, unsigned int start, size_t len);
void	*ft_memset(void *pointer, int value, size_t count);
void	ft_bzero(void *s, size_t n);
void	get_rgb(t_txt *txt, int i, int convert);
void	free_all(char **strs);
int		ft_atoi( char *str);
int		ft_isdigit(int c);
int		ft_strncmp(char *str1, char *str2, size_t len);
int		ft_strcmp(char *s1, char *s2);
int		is_playerchar(char c);
int		is_mapchar(char c);
char	*ft_strdup(char *s1);
#endif