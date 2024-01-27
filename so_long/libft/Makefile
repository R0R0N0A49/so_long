NAME=libft.a
SRC=ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c\
	ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c\
	ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c\
	ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c\
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
	get_next_line.c get_next_line_utils.c
OBJS=$(SRC:.c=.o)
RM=rm -f
CC=gcc 
CFLAGS=-Wextra -Werror -Wall
ARRC=ar -rc

CYAN='\033[1;46m'
BLUE='\033[1;44m'
GREEN='\033[1;42m'
WHITE='\033[0;37m'

all: $(NAME)

$(NAME): $(OBJS)
	@$(ARRC) $(NAME) $(OBJS)
	@echo ${GREEN}">-Successful compilation-<"${WHITE}
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ 
clean:
	@$(RM) $(OBJS)
	@echo ${BLUE}">------Files clean-------<\n"${WHITE}
fclean: clean
	@$(RM) $(NAME)
	@echo ${CYAN}">-------Name clean-------<\n"${WHITE}
re: fclean $(NAME)

.PHONY: all clean fclean re
