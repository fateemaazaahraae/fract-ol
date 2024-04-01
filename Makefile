# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 22:58:03 by fbazaz            #+#    #+#              #
#    Updated: 2024/03/31 21:11:03 by fbazaz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
NAME_BONUS = fractol_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ./mandatory/events.c ./mandatory/exit_error.c ./mandatory/initialize.c ./mandatory/julia.c ./mandatory/main.c ./mandatory/mandelbrot.c
SRC += ./mandatory/check_args.c ./utils/ft_putendl_fd.c ./utils/ft_strcmp.c ./utils/ft_tolower.c ./utils/ft_atof.c ./utils/ft_isdigit.c

SRC_BONUS = ./bonus/burningship_bonus.c ./bonus/events_bonus.c ./bonus/exit_error_bonus.c ./bonus/initialize_bonus.c ./bonus/julia_bonus.c ./bonus/main_bonus.c ./bonus/mandelbrot_bonus.c ./bonus/tricorn_bonus.c
SRC_BONUS += ./bonus/check_args_bonus.c ./utils/ft_putendl_fd.c ./utils/ft_strcmp.c ./utils/ft_tolower.c ./utils/ft_atof.c ./utils/ft_isdigit.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJ)
	@clear
	@echo "\x1b[32m------- MANDATORY PART COMPILED SUCCESSFULLY -------\x1b[0m"
	@echo "\x1b[32m------- FRACTOL IS READY ✅️ -------\x1b[0m"

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJ_BONUS)
	@$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS) $(OBJ_BONUS)
	@clear
	@echo "\x1b[32m------- BONUS PART COMPILED SUCCESSFULLY -------\x1b[0m"
	@echo "\x1b[32m------- FRACTOL IS READY ✅️ -------\x1b[0m"
	
clean :
	@rm -rf $(OBJ) $(OBJ_BONUS)
	@echo "\x1b[32m------- OBJECT FILE CLEANED SUCCESSFULLY -------\x1b[0m"

fclean : clean
	@rm -rf $(NAME) $(NAME_BONUS)
	@echo "\x1b[32m------- FRACTOL CLEANED SUCCESSFULLY -------\x1b[0m"

re : fclean all

.PHONY: all clean fclean re