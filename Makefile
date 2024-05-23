CC := cc
CFLAGS := -Wall -Wextra -Werror -Wunreachable-code -Ofast 

LIBMLX := ~/MLX42
MLX_HEADERS := -I ./include -I $(LIBMLX)/include
MLX_LIBS := $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm 
MLX_FLAGS := -framework Cocoa -framework OpenGL -framework IOKit

LIBFT_DIR = libft/
GNL_DIR = get_next_line/
FT_PRINTF_DIR = ft_printf/

LIBFT = $(LIBFT_DIR)libft.a 
GNL_LIB = $(GNL_DIR)gnl.a
FT_PRINTF = $(FT_PRINTF_DIR)libftprintf.a

LIBS = $(LIBFT) $(GNL_LIB) $(FT_PRINTF)

MAIN_FILES := so_long.c set_color.c read_map.c map_checker.c comp_checker.c \
is_walled.c player_manager.c direction.c load_img_texture.c map_loader.c
GNL_FILES := get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

MAIN_OBJS := $(MAIN_FILES:.c=.o)
GNL_OBJS := $(GNL_FILES:.c=.o)

NAME := gameoftheyear

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
	$(CC) $(MLX_FLAGS) $(MAIN_OBJS) $(LIBS) $(MLX_LIBS) $(MLX_HEADERS) -o $@


%.o: %.c 
	@$(CC) -o $@ -c $< $(MLX_HEADERS)

clean:
	rm -rf $(MAIN_OBJS)
	@rm -rf $(GNL_OBJS)
	#@rm -rf $(LIBMLX)/build
	@make -C $(LIBFT_DIR) clean
	@make -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -rf $(NAME)
	@rm -rf $(LIBFT)
	@rm -rf $(GNL_LIB)
	@rm -rf $(FT_PRINTF)

re: fclean all

.PHONY: all, clean, fclean, re, libmlx