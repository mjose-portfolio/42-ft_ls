# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjose <mjose@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/26 18:25:27 by mjose             #+#    #+#              #
#    Updated: 2018/08/10 02:46:30 by mjose            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), clean, fclean, README

NAME = ft_ls

NOC = \033[0m
OKC = \033[32m
ERC = \033[31m
WAC = \033[33m

CC = gcc

CC_FLAGS = -Wall -Wextra -Werror -g3

SRC_PATH = ./Sources/
OBJ_PATH = ./Objects/
INC_PATH = ./Includes/
LIB_PATH = ./libft/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix $(INC_PATH),$(INC_NAME))

OBJ_NAME = $(SRC_NAME:.c=.o)

INC_NAME = ft_ls.h

SRC_NAME = main.c exec.c error.c flags.c create_tab.c init.c init_2.c\
		   conv_str.c types.c open_close.c clear.c checks.c scan.c info.c\
		   info_2.c scan_2.c apply.c put.c info_3.c put_rights.c rights.c\
		   put_right_special.c puts_2.c list.c sort.c utils.c print.c\
		   exec_2.c exec_3.c exec_4.c exec_5.c exec_6.c exec_7.c exec_8.c\
		   puts_3.c print_2.c exec_9.c exec_10.c exec_11.c scan_3.c list_2.c\
		   print_3.c exec_12.c exec_13.c exec_14.c display.c display_2.c\
		   display_3.c display_4.c exec_15.c display_5.c utils_2.c\
		   display_6.c flags_2.c utils_3.c utils_4.c utils_5.c

all: $(NAME)

$(NAME): $(OBJ)
	@echo
	@make -C $(LIB_PATH)
	@$(CC) -o $(NAME) $(OBJ) -L $(LIB_PATH) -lft
	@echo "$(WAC)FT_LS STATUS:\t\t$(OKC)Ready$(NOC)"
	@echo "======"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) -I $(SRC_PATH) -o $@ -c $<
	@echo -n =

clean:
	@make -C $(LIB_PATH) clean
	@rm -rf $(OBJ_PATH)
	@echo "$(WAC)FT_LS:\t\t\tRemoving binaries folder.$(NOC)"

fclean: clean
	@make -C $(LIB_PATH) fclean
	@rm -rf $(NAME)
	@echo "$(WAC)FT_LS:\t\t\tRemoving executable.$(NOC)"

re: fclean all
