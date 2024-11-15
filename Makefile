MAKEFLAGS += -s
NAME = so_long
CC = cc -g -Wall -Wextra -Werror
RM = rm -rf
LIBFT = libft/libft.a
LIBFT_DIR = libft/
MLX_DIR = ./mlx
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
SRCS = *.c
OBJS = $(SRCS:.c=.o)
INCLUDES = -I/usr/include -Imlx

all:  $(MLX_LIB) $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIBFT) $(MLX_FLAGS)
	@echo "The game is ready to play!"

$(MLX_LIB):
	@make -C $(MLX_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJS): $(SRCS)
	$(CC) -c $(SRCS) $(INCLUDES)

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)
	@echo "objects was removed!"

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
	@echo "GAME OVER!!!!"

re: fclean all

leak: re
	valgrind --leak-check=full --show-leak-kinds=all \
        ./$(NAME) maps/invalid_map/2players.ber