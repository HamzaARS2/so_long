CC := cc
CFLAGS := -Wall -Wextra -Werror -Wunreachable-code -Ofast 

LIBMLX := ~/MLX42
MLX_HEADERS := -I ./include -I $(LIBMLX)/include
MLX_LIBS := $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm 

LIBFT_DIR = libft/
GNL_DIR = get_next_line/
FT_PRINTF_DIR = ft_printf/

LIBFT = $(LIBFT_DIR)libft.a 
GNL_LIB = $(GNL_DIR)gnl.a
FT_PRINTF = $(FT_PRINTF_DIR)libftprintf.a

LIBS = $(LIBFT) $(GNL_LIB) $(FT_PRINTF)

MAIN_FILES := so_long.c read_map.c map_handler.c comp_checker.c \
is_walled.c player_manager.c direction.c load_img_texture.c map_loader.c \
get_starting_pos.c check_collision.c update_game.c handle_input.c render_game.c \
handle_error.c can_reach_all.c clean_resources.c utils.c load_components.c \
moves_counter.c check_coins.c sprites.c
GNL_FILES := get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

MAIN_OBJS := $(MAIN_FILES:.c=.o)
GNL_OBJS := $(GNL_FILES:.c=.o)

NAME := so_long

all: libmlx $(NAME)
	

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(LIBFT):
	@make -C $(LIBFT_DIR) all bonus

$(FT_PRINTF):
	@make -C $(FT_PRINTF_DIR)

$(GNL_LIB): $(GNL_OBJS)
	@ar rcs $@ $^

$(NAME): $(MAIN_OBJS) $(LIBS)
	$(CC) $(MAIN_OBJS) $(LIBS) $(MLX_LIBS) $(MLX_HEADERS) -o $@


%.o: %.c so_long.h
	$(CC) -c $< -o $@ $(MLX_HEADERS)

clean:
	rm -rf $(MAIN_OBJS)
	@rm -rf $(GNL_OBJS)
	@rm -rf $(LIBMLX)/build
	@make -C $(LIBFT_DIR) clean
	@make -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -rf $(NAME)
	@rm -rf $(LIBFT)
	@rm -rf $(GNL_LIB)
	@rm -rf $(FT_PRINTF)

re: fclean all

.PHONY: all, clean, fclean, re, libmlx