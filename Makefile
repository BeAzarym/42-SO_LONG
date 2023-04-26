NAME	=	so_long

SRC	=	main.c \

SRCS = $(addprefix $(SRC_DIR)/, $(SRC))

OBJS =	$(SRCS:.c=.o)

LIBFT = make -C include/libft
MLX = make -C include/mlx

INC_DIR = include
SRC_DIR = src


CFLAGS = -Wall -Wextra -Werror

CC	=	gcc

RM	=	@rm -rf

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

libft :
	@$(LIBFT)
	@$(MLX)
all:	$(NAME)

$(NAME): libft	$(OBJS) 
	$(CC) $(CFLAGS) -I $(INC_DIR) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
	
	
fclean:	clean
	$(RM) $(NAME)

re:	fclean all 

.PHONY:	all re clean fclean