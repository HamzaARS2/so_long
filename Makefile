CC := cc
CFLAGS := -Wall -Wextra -Werror 

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

MAIN_FILES := mandatory/so_long.c mandatory/read_map.c mandatory/map_handler.c mandatory/comp_checker.c \
mandatory/is_walled.c mandatory/player_manager.c mandatory/load_img_texture.c mandatory/map_loader.c \
mandatory/get_starting_pos.c mandatory/check_collision.c mandatory/update_game.c mandatory/handle_input.c mandatory/render_game.c \
mandatory/handle_error.c mandatory/can_reach_all.c mandatory/clean_resources.c mandatory/utils.c mandatory/load_components.c \
mandatory/moves_counter.c mandatory/check_coins.c mandatory/sprites.c mandatory/frames_manager.c mandatory/textures_paths.c

BONUS_FILES := bonus/so_long_bonus.c bonus/read_map_bonus.c bonus/map_handler_bonus.c bonus/comp_checker_bonus.c \
bonus/is_walled_bonus.c bonus/player_manager_bonus.c bonus/load_img_texture_bonus.c bonus/map_loader_bonus.c \
bonus/get_starting_pos_bonus.c bonus/check_collision_bonus.c bonus/update_game_bonus.c bonus/handle_input_bonus.c bonus/render_game_bonus.c \
bonus/handle_error_bonus.c bonus/can_reach_all_bonus.c bonus/clean_resources_bonus.c bonus/utils_bonus.c bonus/load_components_bonus.c \
bonus/moves_counter_bonus.c bonus/check_coins_bonus.c bonus/sprites_bonus.c bonus/frames_manager_bonus.c bonus/textures_paths_bonus.c \
bonus/animate_object_bonus.c bonus/animate_player_bonus.c bonus/enemy_bonus.c bonus/move_enemy_bonus.c \

GNL_FILES := get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

MAIN_OBJS := $(MAIN_FILES:.c=.o)
BONUS_OBJS := $(BONUS_FILES:.c=.o)
GNL_OBJS := $(GNL_FILES:.c=.o)

NAME := so_long
BONUS_NAME := so_long_bonus

all: libmlx $(NAME)

bonus: libmlx $(BONUS_NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(LIBFT):
	@make -C $(LIBFT_DIR) all bonus

$(FT_PRINTF):
	@make -C $(FT_PRINTF_DIR)

$(GNL_LIB): $(GNL_OBJS)
	@ar rcs $@ $^

$(NAME): $(MAIN_OBJS) $(LIBS) 
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(MAIN_OBJS) $(LIBS) $(MLX_LIBS) $(MLX_HEADERS) -o $@

$(BONUS_NAME): $(BONUS_OBJS) $(LIBS) 
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(BONUS_OBJS) $(LIBS) $(MLX_LIBS) $(MLX_HEADERS) -o $@

%.o: %.c mandatory/so_long.h bonus/so_long_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@ $(MLX_HEADERS)

clean:
	rm -rf $(MAIN_OBJS)
	rm -rf $(BONUS_OBJS)
	@rm -rf $(GNL_OBJS)
	@rm -rf $(LIBMLX)/build
	@make -C $(LIBFT_DIR) clean
	@make -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -rf $(NAME)
	rm -rf $(BONUS_NAME)
	@rm -rf $(LIBFT)
	@rm -rf $(GNL_LIB)
	@rm -rf $(FT_PRINTF)

re: fclean all

.PHONY: all, clean, fclean, re, libmlx