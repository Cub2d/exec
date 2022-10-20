#include "cub3d.h"

int	salam(void)
{
	exit(1);
	return (0);
}

void	move_up(t_vars *vars)
{
	static const double PI = 3.1415926535;
	int x;
	int y;
	x = (vars->x1 +  (8 * cos(vars->angle * PI / 180))) / 32;
	y = (vars->y1 +  (8 * sin(vars->angle * PI / 180))) / 32;
	if(vars->map[y][x] != '1')
	{
		vars->x1 = vars->x1 +  (8 * cos(vars->angle * PI / 180));
		vars->y1 = vars->y1 +  (8 * sin(vars->angle * PI / 180));
	}
}

void	move_down(t_vars *vars)
{
	static const double PI = 3.1415926535;
	int x;
	int y;
	
	y = (vars->x1 -  (8 * cos(vars->angle * PI / 180))) / 32;
	x = (vars->y1 -  (8 * sin(vars->angle * PI / 180))) / 32;
	if(vars->map[x][y] != '1')
	{
		vars->x1 = vars->x1 -  (8 * cos(vars->angle * PI / 180));
		vars->y1 = vars->y1 -  (8 * sin(vars->angle * PI / 180));
	}
}

int	keys_hook(int key, t_vars *vars)
{
	if (key == 53)
		exit(1);
	if (key == 13 || key == 126)
		move_up(vars);
	if (key == 1 || key == 125)
		move_down(vars);
	if (key == 124)
		vars->angle += 6;
	if (key == 123)
		vars->angle -= 6;
	DrawCircle(100, vars);
	return (0);
}



void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	(void)color;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

t_point	new_point(float x, float y)
{
	t_point a;
	
	a.x = x;
	a.y = y;
	return (a);
}

void	calculation(t_vars *vars, int left, int right, int r)
{
	static const double PI = 3.1415926535;

	vars->x2 = vars->x1 +  (r * cos(right * PI / 180));
	vars->y2 = vars->y1 +  (r * sin(right * PI / 180));
	dda(vars, new_point(vars->x1, vars->y1), new_point(vars->x2, vars->y2));
	vars->x3 = vars->x1 +  (r * cos(left * PI / 180));
	vars->y3 = vars->y1 +  (r * sin(left * PI / 180));
	dda(vars, new_point(vars->x1, vars->y1), new_point(vars->x3, vars->y3));
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

void DrawCircle(int r, t_vars *vars)
{
	int right;
	int left;

	if (vars->angle + 30 > 360)
		right = 30 - (360 - vars->angle);
	else
		right = vars->angle + 30;
	if (vars->angle - 30 < 0)
		left = 360 - (30 - vars->angle);
	else
		left = vars->angle - 30;
	map_maker(vars);
	calculation(vars, left, right, r);
}

int	main(int ac, char **av)
{
	(void)ac;
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	// vars.lines = i[0];
	vars.win = mlx_new_window(vars.mlx, 1024, 352, "cub3d");
	img.img = mlx_new_image(vars.mlx, 1024, 352);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	vars.angle = 270; 
	vars.img = img;
	vars.mapa.av = av[1];
	vars.x1 = 480;
	vars.y1 = 160;
	Show_Map(&vars);
	DrawCircle(100, &vars);
	// ft_line_counter(i, av[1], &vars);
	// new_win(&vars, i[0], fd);
	mlx_hook(vars.win, 17, 0, salam, &vars);
	mlx_hook(vars.win, 2, 0, keys_hook, &vars);
	mlx_loop(vars.mlx);
}
