# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 10:58:18 by frmonfre          #+#    #+#              #
#    Updated: 2023/05/26 11:52:11 by frmonfre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=

OBJS	=	$(SRCS:.c=.o)

NAME	=	minishell

CC	=	gcc

CFLAG	=	-Wall -Werror -Wextra

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAG) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAG) $(OBJS) -lreadline -o $(NAME)
	norminette
	@echo "___  ____       _     _          _ _ "
	@echo "|  \/  (_)     (_)   | |        | | |"
	@echo "| .  . |_ _ __  _ ___| |__   ___| | |"
	@echo "| |\/| | | '_ \| / __| '_ \ / _ \ | |"
	@echo "| |  | | | | | | \__ \ | | |  __/ | |"
	@echo "\_|  |_/_|_| |_|_|___/_| |_|\___|_|_|\n"

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

push:
	make fclean
	git add ./!(unitTest)
	git commit -m "Makefile auto-commit"
	git push

.PHONY: re fclean all clean push
