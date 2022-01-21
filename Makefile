FILES = createpath	\
		auxfun	\
		main	\
		freefun \

CC = clang

CFLAGS = -Wextra -Wall -Werror #-fsanitize=address -g3

NAME = pipex

INC = -I./includes

RM = rm -f

S = ./src/
SRC = $(addprefix $(S), $(addsuffix .c, $(FILES)))
OBJS = $(addprefix $(S), $(addsuffix .o, $(FILES)))

$(NAME): $(OBJS) 
		$(MAKE) -C ./libft
		cp ./libft/libftprintf.a . 
		$(CC) $(CFLAGS) -g $(INC) $(OBJS) libftprintf.a -o pipex

all: $(NAME)

clean:
		$(RM) $(OBJS)
		$(MAKE) clean -C ./printf

fclean: clean
		$(RM) $(NAME)
		$(RM) *.a
		$(MAKE) fclean -C ./printf

re: fclean all

.PHONY: all re clean fclean
