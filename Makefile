CC = @cc


CFLAGS = -Wall -Werror -Wextra -lmlx -framework OpenGL -framework AppKit #-fsanitize=address -g3

FILES = cub3d.c \
		./srcs/dda_algho.c\
		./srcs/utils.c\
		./srcs/mouvements.c \
		./srcs/show_map.c \
		./srcs/drawing_circle.c \
		./srcs/mini_map.c \
		./srcs/display_ray.c \
		./srcs/mini_utils.c \
		./srcs/get_next_line.c \
		./parse/extra_func.c \
		./parse/fill_texture.c \
		./parse/floor_ceilling.c \
		./parse/map_checker_2.c \
		./parse/map_checker.c \
		./parse/map_parse.c	\
		./parse/extra_func/ft_atoi.c \
		./parse/extra_func/ft_bzero.c \
		./parse/extra_func/ft_isdigit.c \
		./parse/extra_func/ft_memset.c \
		./parse/extra_func/ft_split.c \
		./parse/extra_func/ft_strrchr.c \
		./parse/extra_func/ft_strchr.c \
		./parse/extra_func/ft_strjoin.c \
		./parse/extra_func/ft_substr.c \


NAME = cub3d

C_RED = \033[1;31m
C_GREEN = \033[1;32m
C_L_BLUE = \033[1;34m
C_RES = \033[0m

all : $(NAME)

$(NAME) : $(FILES)
		$(CC) $(CFLAGS) $(FILES) -o $(NAME)
		@echo "$(C_GREEN)["cub3d" CREATED]$(C_RES)"

clean :
	@rm -f $(NAME)
	@echo "$(C_RED)["cub3d" REMOVED]$(C_RES)"

fclean : clean

re : fclean all