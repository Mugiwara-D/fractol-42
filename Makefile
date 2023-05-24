SRC = Source/burningship.c Source/colors.c Source/hooks.c Source/image.c Source/init.c \
	  Source/julia.c Source/main.c Source/mandelbrot.c Source/utils.c Source/zoom.c Source/palet.c

INC = ./Include

CC = cc

FLAGS = -Wall -Werror -Wextra -g3

FINC = -L./ft_printf -L./minilibx-linux -lmlx_Linux -lXext -lX11 -lmlx -lz -lm

OBJ = $(notdir $(SRC:.c=.o))

NAME = fractol

LIBS = ./ft_printf

MLX = ./minilibx-linux

MLIB = $(MLX)/libmlx_Linux.a

PLIB = $(LIBS)/libftprintf.a

$(NAME) : bip boop clean

boop : 
	$(CC) $(FLAGS) $(OBJ) $(FINC) $(MLIB) $(PLIB) -o $(NAME)

bip :
	@make -C $(LIBS)
	@make -C $(MLX)
	$(CC) $(FLAGS) $(SRC) -I$(INC) -c 

all: $(NAME)

clean :
	rm -f $(OBJ) $(notdir $(MLIB))

fclean : clean
	@make fclean -C $(LIBS)
	rm -f $(NAME)

re : fclean all

.PHONY: all fractol  clean fclean re
