NAME = so_long
NAME_BONUS = so_long_bonus

SRCS = so_long.c ft_input.c ft_count_length.c \
	get_next/get_next_line.c get_next/get_next_line_utils.c \
	ft_count_line.c ft_save_map.c ft_funct_libft.c ft_init.c \
	ft_put.c ft_key_hook.c move.c win.c ft_itoa.c ft_creat_map.c

SRCS_BONUS = so_long_bonus.c ft_input.c ft_count_length.c \
	get_next/get_next_line.c get_next/get_next_line_utils.c \
	ft_count_line.c ft_save_map_bonus.c ft_funct_libft.c ft_init_bonus.c \
	ft_put.c ft_key_hook_bonus.c move_bonus.c win.c ft_itoa.c animation.c \
	ft_creat_map_bonus.c

PRINTF = printf/libftprintf.a
CC = gcc

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

%.o: %.c
	$(CC) $(GFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	cd printf && make && cd ..
	$(CC) $(SRCS) $(PRINTF)  $(MLX_FLAGS) -o $(NAME) 

bonus: $(NAME_BONUS)

$(NAME_BONUS):
	cd printf && make && cd ..
	$(CC) $(SRCS_BONUS) $(PRINTF)  $(MLX_FLAGS) -o $(NAME_BONUS)
 
clean:
	cd printf && make clean && cd ..
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)

fclean: clean
	cd printf && make fclean && cd ..
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus