# cub3D
NAME				=	cub3D

CUB3D_SRC			=	src/draw.c \
						src/cub3D.c \
						src/utils.c \
						src/run_display.c \
						src/event_handler.c \
						src/game/game.c \
						src/game/minimap.c \
						src/game/raycasting.c \
						src/game/raycasting2.c \
						src/game/raycasting_utils.c \
						src/parsing/parsing.c \
						src/parsing/read_file.c \
						src/parsing/check_chars.c \
						src/parsing/check_walls.c \
						src/parsing/check_config.c \
						src/parsing/get_file_values.c \

OBJS				= $(CUB3D_SRC:.c=.o)

# Libft
LIBFT				=	libft.a
LIBFT_SRC			=	./libft/

# Compiler
CC					=	gcc
RM					=	rm -f
CFLAGS				=	-Wall -Werror -Wextra -g3 -fsanitize=address
LIBX_FLAGS			=	-Imlx -lmlx -framework OpenGL -framework AppKit

# Colours
RED					=	\033[0;31m
GREEN				=	\033[0;32m
YELLOW				=	\033[0;33m
BLUE				=	\033[0;34m
PURPLE				=	\033[0;35m
CYAN				=	\033[0;36m
WHITE				=	\033[0;37m
RESET				=	\033[0m

# Rules
all:		$(LIBFT) $(NAME)
			@printf "$(BLUE)==> $(CYAN)cub3D compiled ✅\n\n$(RESET)"

$(LIBFT):
			@make -C libft bonus

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) $(LIBX_FLAGS) $(OBJS) $(LIBFT_SRC)$(LIBFT) -o $(NAME)

clean:
			@make -C libft fclean
			@$(RM) $(OBJS)
			@printf "\n$(BLUE)==> $(RED)Removed cub3D 🗑️\n$(RESET)"

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all
			@printf "$(BLUE)==> $(CYAN)cub3D recompiled 🔄\n$(RESET)"

.PHONY:		all clean fclean re
