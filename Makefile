NAME	=	so_long

SRC	=	main.c \
		parsing/map_parser.c \
		parsing/get_map.c \
		parsing/arg_parser.c \
		parsing/items_parser.c \
		parsing/init_struct.c \
		parsing/pathfinding.c \
		utils/ft_error.c \
		graphics/init_mlx.c \
		graphics/init_player.c \
		graphics/init_items.c \
		graphics/display_imgs.c \
		graphics/clear_imgs.c \
		graphics/mouvement.c \
		graphics/event.c \

SRCS = $(addprefix $(SRC_DIR)/, $(SRC))

OBJS =	$(SRCS:.c=.o)

LIBFT = make -C ./src/libft
MLX = make -C ./src/mlx_linux

INC_DIR = include
SRC_DIR = src


CFLAGS = -Wall -Wextra -Werror

CC	=	gcc

RM	=	@rm -rf

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME): 	$(OBJS) 
	$(LIBFT)
	$(MLX)
	$(CC) $(CFLAGS) -Isrc/libft -Isrc/mlx_linux -I $(INC_DIR) -o $(NAME) $(OBJS) -Lsrc/libft -lft -lXext -lX11 -lm -lz -Lsrc/mlx_linux -lmlx

clean:
	$(RM) $(OBJS)
	make -C ./src/libft clean
	make -C ./src/mlx_linux clean

fclean:	clean
	$(RM) $(NAME)
	make -C ./src/libft fclean
	make -C ./src/mlx_linux fclean

re:	fclean all 

.PHONY:	all re clean fclean