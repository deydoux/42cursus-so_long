NAME						=	so_long
BONUS_NAME					=	so_long_bonus

SOURCES						=	close_win.c								\
								copy_img.c								\
								free_game.c								\
								init_game/check_args.c					\
								init_game/init_game.c					\
								init_game/init_map_img.c				\
								init_game/init_mlx.c					\
								init_game/new_win.c						\
								init_game/open_spr.c					\
								init_game/parse_map/check_map_charset.c	\
								init_game/parse_map/check_map_exit.c	\
								init_game/parse_map/check_map_path.c	\
								init_game/parse_map/check_map_size.c	\
								init_game/parse_map/check_map_walls.c	\
								init_game/parse_map/find_map_collects.c	\
								init_game/parse_map/find_map_start.c	\
								init_game/parse_map/parse_map.c			\
								init_game/parse_map/read_map_file.c		\
								init_loop/init_loop.c					\
								init_loop/key_press.c					\
								init_loop/key_release.c					\
								loop/check_move.c						\
								loop/loop.c								\
								loop/render_frame.c						\
								new_img.c								\
								open_img.c								\
								so_long.c

LIBFT_DIR					=	libft
MLX_DIR						=	minilibx-linux
SOURCES_DIR					=	sources
INCLUDE_DIR					=	include
BUILD_DIR					=	build
BONUS_BUILD_DIR				=	$(BUILD_DIR)/bonus

ifeq						($(shell uname), Darwin)
X11_DIR						=	/usr/X11/lib
else
X11_DIR						=	/usr/lib
endif

CC							=	cc
CFLAGS						=	-I$(INCLUDE_DIR) -I$(MLX_DIR) -MD -Wall -Wextra -Werror
BONUS_CFLAGS				=	$(CFLAGS) -D BONUS
LFLAGS						=	-L$(X11_DIR) -lX11 -lXext -lm
RM							=	rm -rf
MKDIR						=	mkdir -p

LIBFT						=	$(LIBFT_DIR)/libft.a
MLX							=	$(MLX_DIR)/libmlx.a
OBJECTS						=	$(addprefix $(BUILD_DIR)/,$(SOURCES:.c=.o))
BONUS_OBJECTS				=	$(addprefix $(BONUS_BUILD_DIR)/,$(SOURCES:.c=.o))
DEPENDENCIES				=	$(OBJECTS:.o=.d)

all							:	$(NAME) bonus

bonus						:	$(BONUS_NAME)

-include 						$(DEPENDENCIES)

$(LIBFT_DIR)				:
	$(MAKE) --no-print-directory -C	$@

$(LIBFT)					:	$(LIBFT_DIR)

$(MLX_DIR)					:
	$(MAKE) --no-print-directory -C	$@

$(MLX)						:	$(MLX_DIR)

$(BONUS_BUILD_DIR)/%.o	:	$(SOURCES_DIR)/%.c
	@$(MKDIR) -p $(@D)
	$(CC) $(BONUS_CFLAGS) -o $@ -c	$<

$(BUILD_DIR)/%.o			:	$(SOURCES_DIR)/%.c
	@$(MKDIR) -p $(@D)
	$(CC) $(CFLAGS) -o $@ -c	$<

$(NAME)						:	$(OBJECTS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

$(BONUS_NAME)				:	$(BONUS_OBJECTS) $(LIBFT) $(MLX)
	$(CC) $(BONUS_CFLAGS) -o $@ $^ $(LFLAGS)

clean						:
	$(MAKE) --no-print-directory -C	$(LIBFT_DIR) $@
	$(MAKE) --no-print-directory -C	$(MLX_DIR) $@
	$(RM) $(BUILD_DIR)

fclean						:
	$(MAKE) --no-print-directory -C	$(LIBFT_DIR) $@
	$(MAKE) --no-print-directory -C	$(MLX_DIR) clean
	$(RM) $(BUILD_DIR) $(NAME) $(BONUS_NAME)

re							:	fclean all

.PHONY						:	all bonus clean fclean re $(LIBFT_DIR) $(MLX_DIR)
