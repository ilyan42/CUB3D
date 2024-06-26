NAME = cub3d
CC = gcc -g3
CFLAGS = -Wall -Wextra -Werror
_HEADERS_DIR = ./include

NORM = @norminette include srcs map texture LIBFT
_OBJ_DIR = .obj
_SRCS = 		srcs/main.c \
				srcs/parser/parse_map/get_file.c \
				srcs/parser/parse_texture/get_texture.c \
				srcs/parser/parse_texture/parse_and_open_texture.c \
				srcs/parser/parse_texture/texture_file.c \
				srcs/parser/parse_texture/color.c \
				srcs/parser/parse_map/parse_map.c \
				srcs/error/print_error.c \
				srcs/player_movement/move.c \
				srcs/raycasting/render_raycast.c \
				srcs/raycasting/get_distance_wall.c \
				srcs/raycasting/raycasting.c \
				srcs/init/init_struct.c \
				srcs/raycasting/render_utils.c \
				srcs/player_movement/handle_key.c \
				srcs/player_movement/key_utils.c \
				srcs/parser/mini_map/get_mini_map.c \
				srcs/parser/parse_map/parse_map_utils.c \
				srcs/init/init_struct_utils.c \
				srcs/init/init_sprite_window.c \
				srcs/parser/parse_map/check_map.c \
				srcs/parser/mini_map/get_mini_map_utils.c \
				srcs/error/free.c \
				srcs/player_movement/mouse_move.c \
				srcs/weapon/draw_weapon.c \
				srcs/weapon/draw_weapon_utils.c \
				srcs/utils/destroy.c \
				srcs/parser/parse_texture/put_texture.c \
				srcs/utils/utils.c \
				srcs/utils/utils1.c \
				srcs/utils/utils2.c \
				srcs/error/print_exit.c \

SRC_DIR = .

SRCS = $(_SRCS:%=$(SRC_DIR)/%)

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	LDFLAGS = -Lminilibx-linux -lmlx ./LIBFT/libft.a -lXext -lX11 -lm -lz
else ifeq ($(UNAME_S),Darwin)
	LDFLAGS = -Lmlx -lmlx -Imlx -L./LIBFT -lft -framework OpenGL -framework AppKit
else
	$(error Unsupported operating system: $(UNAME_S))
endif

AR = ar
ARFLAGS = rcs

OBJS = $(patsubst $(SRC_DIR)/%.c, $(_OBJ_DIR)/%.o, $(SRCS))

$(_OBJ_DIR):
	mkdir -p $(_OBJ_DIR)/srcs/parser/parse_texture
	mkdir -p $(_OBJ_DIR)/srcs/parser/parse_map
	mkdir -p $(_OBJ_DIR)/srcs/error
	mkdir -p $(_OBJ_DIR)/srcs/raycasting
	mkdir -p $(_OBJ_DIR)/srcs/player_movement
	mkdir -p $(_OBJ_DIR)/srcs/init
	mkdir -p $(_OBJ_DIR)/srcs/parser/mini_map
	mkdir -p $(_OBJ_DIR)/srcs/weapon
	mkdir -p $(_OBJ_DIR)/srcs/utils

all: force $(_OBJ_DIR) $(NAME)

$(_OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(_HEADERS_DIR)/cub3d.h $(_HEADERS_DIR)/define.h $(_HEADERS_DIR)/struct.h Makefile
	$(CC) -I$(_HEADERS_DIR) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(MAKE) all -C ./LIBFT 
	$(MAKE) -C minilibx-linux
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME) 

force:
		make -C LIBFT

clean:
	rm -f $(OBJS)
	rm -rf $(_OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./LIBFT
	$(MAKE) clean -C minilibx-linux

norminette:
	$(NORM)

re: fclean all

.PHONY: all clean fclean re norminette force