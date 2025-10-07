# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/20 18:20:06 by acoste            #+#    #+#              #
#    Updated: 2025/10/06 23:09:56 by acoste           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02

NAME_BONUS = rush_bonus

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror -I ex00

SRCS_DIR = ex00
OBJS_DIR = $(SRCS_DIR)/.objs

LIST_SRCS = main.c \
			utils.c \
			dictionnary.c \
			get_next_line.c \
			get_next_line_utils.c \
			chain.c \
			split_du_pauvre.c \
			parsing.c \
			packet.c

LIST_OBJS = $(LIST_SRCS:.c=.o)

OBJS = $(addprefix $(OBJS_DIR)/, $(LIST_OBJS))

# SRCS_BONUS_DIR = bonus

# OBJS_BONUS_DIR = $(SRCS_BONUS_DIR)/.objs_bonus

# LIST_SRCS_BONUS =	main.c \


# LIST_OBJS_BONUS = $(LIST_SRCS_BONUS:.c=.o)

# OBJS_BONUS = $(addprefix $(OBJS_BONUS_DIR)/, $(LIST_OBJS_BONUS))

all : $(NAME)

$(OBJS_DIR)/%.o	:	$(SRCS_DIR)/%.c
					@mkdir -p $(OBJS_DIR)
					$(CC) $(CFLAGS) -o $@ -c $<

$(NAME)	:	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)


# bonus	:	$(OBJS_BONUS)
# 	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)


# $(OBJS_BONUS_DIR)/%.o	:	$(SRCS_BONUS_DIR)/%.c
# 					@mkdir -p $(OBJS_BONUS_DIR)
# 					$(CC) $(CFLAGS) -o $@ -c $<


clean :
	rm -rf $(OBJS_DIR)
	rm -rf $(OBJS_BONUS_DIR)

fclean : clean
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)

re : fclean all

.PHONY : all clean fclean re bonus
