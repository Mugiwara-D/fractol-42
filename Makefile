SRC = ./Source/*.c
INC = ./Include
CC = cc
FLAGS = -Wall -Werror -Wextra
OBJ = $(SRC:.c=.o)

bip:
	$(CC) $(SRC) -L./minilibx-linux -lmlx_Linux -lXext -lX11 -lmlx -lz -I$(INC)
