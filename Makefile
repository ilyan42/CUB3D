NAME = cub3d
CC = gcc -g3
CFLAGS = -Wall -Wextra -Werror
_HEADERS = cub3d.h

_SRCS = 		srcs/main.c \
				srcs/parser/parser_texture.c \
				srcs/parser/get_file.c \
				srcs/parser/parse_texture/get_texture.c \
				srcs/parser/parse_texture/parse_and_open_texture.c \
				srcs/parser/parse_map/parse_map.c \
				srcs/error/print_error.c \
				srcs/raycasting/raycasting.c \

SRC_DIR = .

SRCS = $(_SRCS:%=$(SRC_DIR)/%)

HEADERS_DIR = .

HEADERS = $(_HEADERS:%=$(HEADERS_DIR)/%)

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

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -I$(HEADERS_DIR) -c $< -o $@

$(NAME): $(OBJS)
	$(MAKE) all -C ./LIBFT 
	$(MAKE) -C minilibx-linux
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME) 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./LIBFT
	$(MAKE) clean -C minilibx-linux

re: fclean all

.PHONY: all clean fclean re
