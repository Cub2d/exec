CC = @cc


CFLAGS = -Wall -Werror -Wextra -lmlx -framework OpenGL -framework AppKit

FILES = srcs/cub3d.c \
		srcs/dda_algho.c\
		srcs/utils.c\
		srcs/mouvements.c \
		srcs/parse_map.c\
		srcs/show_map.c\
		srcs/get_next_line.c \

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