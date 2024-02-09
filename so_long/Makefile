NAME = so_long
SRCS = so_long.c parsing.c parsing_2.c init_tabs_map.c choice_char.c error_and_free.c destroy_img_tex.c dead_and_win.c\
		load_txt_img.c moving.c display_map.c ghost.c display_number.c
OBJS=$(SRCS:.c=.o)
RM=rm -rf
CC= clang
CFLAGS= -Wall -Wextra -Werror -I./MLX42/include -I./libft -g
MLXFLAGS= -ldl -lX11 -lglfw -lm -lz -lbsd -lXext 

CYAN='\033[1;36m'
BLUE='\033[1;34m'
GREEN='\033[6;32m'
WHITE='\033[0;m'

all: libmlx $(NAME)
libmlx:
	@cmake ./MLX42 -B ./MLX42/build 
	@make -C ./MLX42/build --no-print-directory -j4
$(NAME) : $(OBJS)
	@make --directory ./libft 
	@make --directory ./MLX42/build
	@clear
	@$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) ./libft/libft.a ./MLX42/build/libmlx42.a -o $@
	@if [ $$? -eq 0 ]; then \
		echo ${GREEN}"Compilation successful!"${GREEN}; \
	fi
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 
first:
	@git clone https://github.com/codam-coding-college/MLX42.git
	@git clone https://github.com/R0R0N0A49/libft.git
clean:
	@clear
	@$(RM) $(OBJS)
	@echo ${BLUE}">------Files clean-------<\n"${WHITE}
fclean: clean
	@$(RM) $(NAME)
	@make fclean --directory ./libft 
	@clear
	@echo ${BLUE}">------Files clean-------<\n"${WHITE}
	@echo ${CYAN}">-------Name clean-------<\n"${WHITE}
cleanall: fclean
	@$(RM) MLX42
	@$(RM) libft
re: fclean all

.PHONY: all clean fclean re cleanall first
