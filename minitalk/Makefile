# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhurtamo <mhurtamo@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/16 19:38:50 by mhurtamo          #+#    #+#              #
#    Updated: 2025/02/16 20:01:25 by mhurtamo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CSRCS	= client.c utils.c ft_atoi.c

SSRCS	= server.c utils.c ft_atoi.c

HEAD	= ./

COBJS	= ${CSRCS:.c=.o}

SOBJS	= ${SSRCS:.c=.o}

CNAME	= client

SNAME	= server

RM	= rm -f

CC	= cc

CFLAGS	= -Wall -Wextra -Werror

all:	${CNAME} ${SNAME}

c.o: ${CC} ${CFLAGS} -c -I ${HEAD} $< -o ${<:.c=.o}

${CNAME}: ${COBJS}
	${CC} ${CFLAGS} ${COBJS} -o ${CNAME}
	
${SNAME}: ${SOBJS}
	${CC} ${CFLAGS} ${SOBJS} -o ${SNAME}
	
clean:
	rm -f ${COBJS}
	rm -f ${SOBJS}

fclean:	clean
	rm -f ${CNAME}
	rm -f ${SNAME}

re:	fclean all clean

.PHONY:	all clean fclean re
