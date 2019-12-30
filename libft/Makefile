# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjose <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/20 10:39:14 by mjose             #+#    #+#              #
#    Updated: 2018/05/28 16:11:24 by mjose            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), clean, fclean, re

NAME = libft.a

NOC=\033[0m
OKC=\033[32m
ERC=\033[31m
WAC=\033[33m

CC = gcc

#CC_FLAGS = -Wall -Wextra -Werror -fsanitize=address -g
CC_FLAGS = -Wall -Wextra -Werror

INC_PATH = ./Includes/
SRC_PATH = ./Sources/
OBJ_PATH = ./Binaries/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

INC_NAME = libft.h get_next_line.h
SRC_NAME = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
	ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
	ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
	ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	ft_isprint.c ft_iswhitespace.c ft_toupper.c ft_tolower.c \
	ft_putchar_fd.c ft_putchar.c ft_putstr_fd.c ft_putstr.c ft_putnbr_fd.c \
	ft_putnbr.c ft_putendl_fd.c ft_putendl.c ft_strclr.c ft_strequ.c \
	ft_strnequ.c ft_striter.c ft_striteri.c ft_memalloc.c ft_memdel.c \
	ft_strnew.c ft_strdel.c ft_stralloc.c ft_strmap.c ft_strmapi.c \
	ft_strjoin.c ft_strsub.c ft_strtrim.c ft_countparts.c ft_partlen.c \
	ft_strsplit.c ft_intlen.c ft_itoa.c \
	ft_lstadd.c ft_lstdelone.c ft_lstdel.c ft_lstiter.c ft_lstmap.c \
	ft_lstnew.c ft_printlst.c ft_absolut.c ft_sqrt.c get_next_line.c
OBJ_NAME = $(SRC_NAME:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@rm -rf $(OBJ_PATH)
	@echo "$(WAC)LIBRARY STATUS:\t\t$(OKC)Ready$(NOC)"
	@echo "======"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS)  $(INC) -o $@ -c $<
	@echo -n =

clean:
	@rm -rf $(OBJ_PATH)
	@echo "$(WAC)LIBRARY:\t\tRemoving binaries folder.$(NOC)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(WAC)LIBRARY:\t\tRemoving library.$(NOC)"

re: fclean all
