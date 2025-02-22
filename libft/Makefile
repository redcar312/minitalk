# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MAKEFILE                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhurtamo <mhurtamo@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 12:00:45 by mhurtamo          #+#    #+#              #
#    Updated: 2024/11/06 12:43:11 by mhurtamo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_isalpha.c ft_strlcat.c ft_strlcpy.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strjoin.c 

BONUS	= ft_lstadd_front_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

HEAD	= ./

OBJS	= ${SRCS:.c=.o}

BOBJS	= ${BONUS:.c=.o}

NAME	= libft.a

AR	= ar rc

RM	= rm -f

LIB	= ranlib

CC	= cc

CFLAGS	= -Wall -Wextra -Werror

all:	${NAME}

c.o: ${CC} ${CFLAGS} -c -I ${HEAD} $< -o ${<:.c=.o}



${NAME}:	${OBJS}
	${AR} ${NAME} ${OBJS}
	${LIB} ${NAME}


bonus:		${OBJS} ${BOBJS}
	${AR} ${NAME} ${OBJS} ${BOBJS}
	
clean:
	rm -f ${OBJS} ${BOBJS}

fclean:	clean
	rm -f ${NAME}

re:	fclean all bonus clean



.PHONY:	all clean fclean re bonus
