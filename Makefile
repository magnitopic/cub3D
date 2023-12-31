# cub3D
NAME				=	cub3D

CUB3D_SRC			=	src/cub3D.c \
						src/utils.c \
						src/event_handler.c \
						src/game/draw.c \
						src/game/raycasting.c \
						src/game/start_game.c \
						src/game/create_textures.c \
						src/parsing/parsing.c \
						src/parsing/read_file.c \
						src/parsing/get_file_values.c \
						src/parsing/check_closed_walls.c \

OBJS				= $(CUB3D_SRC:.c=.o)

# Libft
LIBFT				=	libft.a
LIBFT_SRC			=	./libft/

# Compiler
CC					=	gcc
RM					=	rm -f
CFLAGS				=	-Wall -Werror -Wextra #-g3 -fsanitize=address
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
