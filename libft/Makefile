NAME = 	libftprintf.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f
INC = -I.


FILES =   printf/ft_printf\
	  printf/ft_printhex\
	  printf/ft_printnum\
	  printf/ft_printstr\
	  printf/ft_contfun\
	  printf/ft_printfsrc\
	  printf/ft_printnumesrc\
	  printf/ft_printhexautils\
	  printf/ft_printwrite\

FILES_B =  printf/ft_printf\
	  printf/ft_printhex\
	  printf/ft_printnum\
	  printf/ft_printstr\
	  printf/ft_contfun\
	  printf/ft_printfsrc\
	  printf/ft_printnumesrc\
	  printf/ft_printhexautils\
	  printf/ft_printwrite\

S = ./
SRCS = $(addprefix $(S), $(addsuffix .c, $(FILES)))
SRCS_B = $(addprefix $(S), $(addsuffix .c, $(FILES_B)))

O = ./
OBJS = $(addprefix $(S), $(addsuffix .o, $(FILES)))
OBJS_B = $(addprefix $(S), $(addsuffix .o, $(FILES_B)))

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp ./libft/libft.a $(NAME) 
	$(AR) $@ $(OBJS) 

bonus: $(OBJS_B)
	$(AR) $(NAME) $^

all: $(NAME)

clean: 
	$(RM) $(OBJS) $(OBJS_B)
	$(MAKE) clean -C ./libft 

fclean: clean
	$(RM) *.a 
	$(MAKE) fclean -C ./libft 

re: clean all

.PHONY: bonus all clean fclean re
