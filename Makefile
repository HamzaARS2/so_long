CC := cc
CFLAGS := -Wall -Wextra -Werror -Wunreachable-code -Ofast

LIBMLX := ~/MLX42
MLX_HEADERS := -I ./include -I $(LIBMLX)/include
MLX_LIBS := $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm $(MLX_FLAGS)
MLX_FLAGS := -framework Cocoa -framework OpenGL -framework IOKit


MAIN_FILES := so_long.c set_color.c read_map.c 
GNL_FILES := get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
MAIN_OBJS := $(MAIN_FILES:.c=.o)

NAME := gameoftheyear


all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): $(MAIN_OBJS) $(GNL_FILES)
	$(CC) $(MAIN_OBJS) $(GNL_FILES) $(MLX_LIBS) $(MLX_HEADERS) -o $@

%.o: %.c 
	@$(CC) -o $@ -c $< $(MLX_HEADERS)


clean:
	rm -rf $(MAIN_OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, libmlx