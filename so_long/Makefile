NAME=so_long
libft=libft.a
CC=cc
CFLAG= -Werror -Wall -Wextra -g
SRCS= so_long.c parsing.c parsing_2.c init_tabs_map.c ft_printf/ft_printf_utils.c ft_printf/ft_printf.c
OBJS=$(SRCS:.c=.o)
RM=rm -f

CYAN='\033[1;36m'
BLUE='\033[1;34m'
GREEN='\033[6;32m'
WHITE='\033[0;37m'

.c.o:
	@$(CC) $(CFLAG) -c $< -o $(<:.c=.o)
all: $(NAME) $(libft)
$(libft):
	@ make -C libft all
$(NAME) : $(OBJS) $(libft)
	@$(CC) $(CFLAG) -o $(NAME) $(OBJS) libft/libft.a
	@echo ${GREEN}">-Successful compilation-<"${WHITE}
clean:
	@clear
	@$(RM) $(OBJS)
	@echo ${BLUE}">------Files clean-------<\n"${WHITE}
fclean : clean
	@$(RM) $(NAME)
	@ make -C libft fclean
	@echo ${CYAN}">-------Name clean-------<\n"${WHITE}
re: fclean $(NAME)

.PHONY: clean fclean re all
