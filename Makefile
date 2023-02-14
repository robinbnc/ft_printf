SRCS	= 	ft_print_memory.c ft_printf.c ft_putchar.c ft_putnbr_base.c ft_putnbr_unsigned.c\
			ft_putnbr.c ft_putstr.c

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

CC	= gcc

CFLAGS	= -Wall -Wextra -Werror

RM	= rm -f


.c.o:	ft_printf.h
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}

all:		${NAME}

clean:
		${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
		${RM} ${NAME}

re:		fclean all
