FILES = ft_printf.c ft_printf_utils.c ft_printf_utils_2.c ft_printf_utils_3.c

FLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

OBJ = $(FILES:.c=.o)

HEADER = ft_printf.h

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@ar -rcs $(NAME) $(OBJ)
	@echo "lib is created"
	

%.o : %.c $(HEADER)
	@cc $(FLAGS) -c $< -o $@ -I $(HEADER)
	@echo "Compilation $<"

clean:
	@rm -f $(OBJ)
	@echo "Obj deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "All deleted"

re: fclean all

.PHONY : all, clean, fclean, re
