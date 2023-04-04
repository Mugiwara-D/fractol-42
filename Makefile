SRC = ./Source/*.c
INC = ./Include
CC = cc
FLAGS = -Wall -Werror -Wextra
OBJ = $(SRC:.c=.o)

.o:
	$(CC) $(FLAGS) $(SRC) -L./minilibx-linux -lmlx_Linux -lXext -lX11 -lmlx -lz -I./minilibx-linux
