SRC = ./Source/*.c
INC = ./Include
CC = cc
FLAGS = -Wall -Werror -Wextra
OBJ = $(SRC:.c=.o)

bip:
	$(CC) $(FLAGS) $(SRC) -L./minilibx-linux -lmlx_Linux -lXext -lX11 -lmlx -lz -I$(INC) ft_printf/libftprintf.a libft/libft.a
