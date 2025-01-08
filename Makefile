# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 12:50:20 by ticasali          #+#    #+#              #
#    Updated: 2025/01/08 12:50:46 by ticasali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =				libftprintf.a

DIR_SRCS =			src

SRCS =				$(DIR_SRCS)/ft_printf.c 	\
					$(DIR_SRCS)/ft_param.c		\
					$(DIR_SRCS)/ft_lenght.c		\
					$(DIR_SRCS)/ft_putchar.c	\
					$(DIR_SRCS)/ft_putstr.c		\
					$(DIR_SRCS)/ft_putnbr.c		\

DIR_OBJS =			.objs
OBJS =				$(SRCS:$(DIR_SRCS)/%.c=$(DIR_OBJS)/%.o)

CFLAGS =			-Wall -Wextra -Werror
AR = ar -rcs

all:				$(NAME)

$(DIR_OBJS)/%.o:	$(DIR_SRCS)/%.c $(INC)
					@mkdir -p $(dir $@)
					$(CC) $(CFLAGS) -c $< -o $@ -I./include

$(NAME):			$(OBJS) include/ft_printf.h
					$(AR) $(NAME) $(OBJS)

clean:
					$(RM) -r $(DIR_OBJS)

fclean:				clean
					$(RM) $(NAME)

re:					fclean
					$(MAKE) all

.PHONY:				all clean fclean re