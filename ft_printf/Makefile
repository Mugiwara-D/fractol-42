SRC = ft_printf.c utils/ft_bool.c utils/ft_format.c utils/ft_printers.c utils/ft_puthex_fd.c \
      utils/ft_putunsigned.c utils/Bonus/ft_parsing.c

SRC_B = ft_printf.c utils/ft_bool.c utils/ft_format.c utils/ft_printers.c utils/ft_puthex_fd.c \
      utils/ft_putunsigned.c utils/Bonus/ft_parsing.c utils/Bonus/ft_printstr_mod.c \
      utils/Bonus/ft_puthex_mod_fd.c utils/Bonus/ft_putnchar.c utils/Bonus/ft_putnstr.c \
      utils/Bonus/ft_putunsigned_mod.c utils/Bonus/ft_printer_b.c utils/Bonus/ft_print_number_mod.c utils/Bonus/ft_print_mod_p.c \
	  utils/Bonus/ft_print_x_mod.c

NAME = libftprintf.a

INC_LIB = ./libft

INC_A = ./libft/libft.a

FLAGS = -Werror -Wall -Wextra

INC = Include

CC = gcc

LIB_OBJ = ft_atoi.o ft_bool.o ft_bzero.o ft_calloc.o ft_format.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o \
		  ft_isprint.o ft_itoa.o ft_lstadd_back.o ft_lstadd_front.o ft_lstclear.o ft_lstdelone.o ft_lstiter.o ft_lstlast.o \
		  ft_lstmap.o ft_lstnew.o ft_lstsize.o ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memmove.o ft_memset.o ft_printers.o \
		  ft_putchar_fd.o ft_putendl_fd.o ft_puthex_fd.o ft_putnbr_fd.o ft_putstr_fd.o ft_putunsigned.o ft_split.o ft_strchr.o \
		  ft_strdup.o ft_striteri.o ft_strjoin.o ft_strlcat.o ft_strlcpy.o ft_strlen.o ft_strmapi.o ft_strncmp.o \
		  ft_strnstr.o ft_strrchr.o ft_strtrim.o ft_substr.o ft_tolower.o ft_toupper.o

OBJ = $(notdir $(SRC:.c=.o))

OBJ_B = $(notdir $(SRC_B:.c=.o))

AR = ar rcs

RM = rm -f

$(NAME) : bip boop clean

bonus : bip_b boop_b clean

bip :
	@echo "make libft and .o"
	@make -C $(INC_LIB)
	@$(CC) $(FLAGS) -I$(INC) -c $(SRC_B) 

boop : 
	@echo "archaving libftprintf.a"
	@ar x $(INC_A) 
	@$(AR) $(NAME) $(OBJ_B) $(LIB_OBJ)

clean :
	@$(RM) $(OBJ) $(OBJ_B) $(LIB_OBJ)
	@echo "zone is clear"

fclean : clean
	@make fclean -C $(INC_LIB)
	$(RM) $(NAME)
	@echo "zone is fclear"

all : $(NAME)
	@echo "all making"

re : fclean all
	@echo "re"

bip_b : 
	@make -C $(INC_LIB)
	@$(CC) $(FLAGS) -c $(SRC_B)
	@echo "bip_b ok"

boop_b : 
	@echo "archaving Bonus"
	@ar x $(INC_A) 
	@$(AR) $(NAME) $(OBJ_B) $(LIB_OBJ)
