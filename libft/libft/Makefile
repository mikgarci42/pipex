# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mikgarci <mikgarci@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/29 18:08:14 by mikgarci          #+#    #+#              #
#    Updated: 2021/09/28 15:59:16 by mikgarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = mem/ft_memset.c        \
        mem/ft_bzero.c        \
        mem/ft_memcpy.c       \
        mem/ft_memccpy.c      \
        mem/ft_memmove.c		\
        mem/ft_memchr.c        \
        mem/ft_calloc.c        \
        mem/ft_memcmp.c        \
        is/ft_isalpha.c    	\
        is/ft_isdigit.c        \
        is/ft_isalnum.c        \
        is/ft_isascii.c        \
        is/ft_isprint.c        \
        to/ft_toupper.c        \
        to/ft_tolower.c        \
        str/ft_strchr.c        \
        str/ft_strrchr.c        \
        str/ft_strlen.c        \
        str/ft_strncmp.c        \
        str/ft_strlcpy.c        \
        str/ft_strlcat.c        \
        str/ft_strnstr.c        \
		str/ft_strjoin.c		\
        str/ft_strdup.c        \
		str/ft_strtrim.c	\
		str/ft_substr.c		\
		put/ft_putchar_fd.c		\
		put/ft_putstr_fd.c		\
		put/ft_putendl_fd.c		\
		put/ft_putnbr_fd.c		\
		put/ft_putnbr.c		\
		str/ft_split.c		\
		str/ft_strmapi.c	\
        num/ft_atoi.c        \
		num/ft_itoa.c		\
		lst/ft_lstnew.c		\
		lst/ft_lstadd_front.c\
		lst/ft_lstsize.c		\
		lst/ft_lstlast.c		\
		lst/ft_lstadd_back.c	\
		lst/ft_lstdelone.c	\
		lst/ft_lstclear.c	\
		lst/ft_lstiter.c		\
		lst/ft_lstmap.c		\


NAME = libft.a

OBJS = $(SRCS:.c=.o)

AR = ar rcs

RANLIB = ranlib

LFLAGS = -I

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)
			$(RANLIB) $(NAME)

all: 		$(NAME)

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -f $(NAME)

re:		fclean all

.PHONY:	all clean fclean

