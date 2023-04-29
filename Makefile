NAME	=	so_long

SRC	=	main.c \
		parsing/map_parser.c \
		parsing/init_struct.c \
		utils/ft_error.c \

SRCS = $(addprefix $(SRC_DIR)/, $(SRC))

OBJS =	$(SRCS:.c=.o)

LIBFT = make -C ./src/libft
# MLX = make -C mlx

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
	$(CC) $(CFLAGS) -Isrc/libft -I $(INC_DIR) -o $(NAME) $(OBJS) -Lsrc/libft -lft

clean:
	$(RM) $(OBJS)
	make -C ./src/libft clean

fclean:	clean
	$(RM) $(NAME)
	make -C ./src/libft fclean

re:	fclean all 

.PHONY:	all re clean fclean