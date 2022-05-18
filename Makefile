FILES = srcs/read_parse_map.c srcs/main.c srcs/useful_func.c srcs/textures.c srcs/open_close_window.c\
	srcs/movin.c srcs/check.c  srcs/useful_func_1.c srcs/enemy.c \
	gnl/get_next_line.c gnl/get_next_line_utils.c \
	ft_printf/ft_printf.c ft_printf/ft_printf_utils.c ft_printf/ft_printf_utils_2.c ft_printf/ft_printf_utils_3.c

FLAGS = -Wall -Werror -Wextra

NAME = so_long

OBJ = $(FILES:.c=.o)

HEADER = includes/so_long.h gnl/get_next_line.h ft_printf/ft_printf.h

MLX_DIR = mlx/
all: $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	@gcc $(FLAGS) $(OBJ) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "so_long is created"

$(MLX):		
		@echo "Compilation libmlx"
		@make -s -C $(MLX_PATH)
		@echo "libmlx is compliled"

%.o : %.c $(HEADER)
	@gcc $(FLAGS) -c $< -o $@ 
	@echo "Compilation $<"

clean:
	@rm -f $(OBJ) 
	@echo "Obj deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "All deleted"

re: fclean all

.PHONY : all, clean, fclean, re