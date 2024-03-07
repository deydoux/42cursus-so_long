NAME				=	so_long

SOURCES				=	close_window.c		\
						closed_map.c		\
						create_map_img.c	\
						find_components.c	\
						find_valid_path.c	\
						free_mlx.c			\
						key_press.c			\
						key_release.c		\
						loop.c				\
						new_img.c			\
						open_img.c			\
						parse_map.c			\
						put_img_to_img.c	\
						read_map.c			\
						so_long.c

LIBFT_DIR			=	libft
MLX_DIR				=	minilibx-linux
SOURCES_DIR			=	sources
INCLUDE_DIR			=	include
BUILD_DIR			=	build

ifeq				($(shell uname), Darwin)
X11_DIR				=	/usr/X11/lib
else
X11_DIR				=	/usr/lib
endif

CC					=	cc
CFLAGS				=	-I$(INCLUDE_DIR) -I$(MLX_DIR) -MD -Wall -Wextra -Werror
LFLAGS				=	-L$(X11_DIR) -lX11 -lXext -lm
RM					=	rm -rf
MKDIR				=	mkdir -p

LIBFT				=	$(LIBFT_DIR)/libft.a
MLX					=	$(MLX_DIR)/libmlx.a
OBJECTS				=	$(addprefix $(BUILD_DIR)/,$(SOURCES:.c=.o))
DEPENDENCIES		=	$(OBJECTS:.o=.d)

all					:	$(NAME)

-include 				$(DEPENDENCIES)

$(LIBFT_DIR)		:
	$(MAKE) --no-print-directory -C	$@

$(LIBFT)			:	$(LIBFT_DIR)

$(MLX_DIR)			:
	$(MAKE) --no-print-directory -C	$@

$(MLX)				:	$(MLX_DIR)

$(BUILD_DIR)/%.o	:	$(SOURCES_DIR)/%.c
	@$(MKDIR) $(@D)
	$(CC) $(CFLAGS) -o $@ -c	$<

$(NAME)				:	$(OBJECTS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

clean				:
	$(MAKE) --no-print-directory -C	$(LIBFT_DIR) $@
	$(MAKE) --no-print-directory -C	$(MLX_DIR) $@
	$(RM) $(BUILD_DIR)

fclean				:
	$(MAKE) --no-print-directory -C	$(LIBFT_DIR) $@
	$(MAKE) --no-print-directory -C	$(MLX_DIR) clean
	$(RM) $(BUILD_DIR) $(NAME)

re					:	fclean all

.PHONY				:	all clean fclean re $(LIBFT_DIR) $(MLX_DIR)
