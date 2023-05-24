SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
	  ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
	  ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
	  ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
	  ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c 
SRC_B = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstiter.c ft_lstdelone.c ft_lstlast.c \
	ft_lstnew.c ft_lstsize.c ft_lstmap.c
NAME = libft.a
CC = gcc
FLAG = -Werror -Wall -Wextra
OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)
RM = rm -f
AR = ar rc
$(NAME) : all
blip :
	@$(CC) $(FLAG) -c $(SRC) 
bloop : blip
	@$(AR) $(NAME) $(OBJ)
clean : 
	@$(RM) $(OBJ) $(OBJ_B)

fclean : clean
	 @${RM} $(NAME)
cc_b :
	@$(CC) $(FLAG) -c $(SRC_B)
bonus : cc_b
	@$(AR) $(NAME) $(OBJ_B)

all : bloop bonus clean

re : fclean all 

