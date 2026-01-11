NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx.a

MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm -lz
INCLUDES = -I$(MLX_DIR)

SRCS =	main.c \
		click.c \
		free_all.c \
		ft_putnbr_fd.c \
		ft_split.c \
		get_next_line.c \
		get_next_line_utils.c \
		image.c \
		initializer.c \
		move_player.c \
		path.c \
		readmap.c \
		rows_and_columns.c \
		valid_char.c \
		validation.c

OBJS = $(SRCS:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
