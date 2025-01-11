# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 12:50:20 by ticasali          #+#    #+#              #
#    Updated: 2025/01/11 00:29:24 by ticasali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =				gnl.a

DIR_SRCS =			src

SRCS =				$(DIR_SRCS)/get_next_line.c 	\

DIR_OBJS =			.objs
OBJS =				$(SRCS:$(DIR_SRCS)/%.c=$(DIR_OBJS)/%.o)

CFLAGS =			-Wall -Wextra -Werror
AR = ar -rcs

all:				$(NAME)

$(DIR_OBJS)/%.o:	$(DIR_SRCS)/%.c $(INC)
					@mkdir -p $(dir $@)
					$(CC) $(CFLAGS) -c $< -o $@ -I./include

$(NAME):			$(OBJS) include/get_next_line.h
					$(AR) $(NAME) $(OBJS)

clean:
					$(RM) -r $(DIR_OBJS)

fclean:				clean
					$(RM) $(NAME)

re:					fclean
					$(MAKE) all

.PHONY:				all clean fclean re