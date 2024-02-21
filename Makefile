NAME				=	so_long

SOURCES				=	close_window.c	\
						key_release.c	\
						so_long.c

LIBFT_DIR			=	libft
MLX_DIR				=	minilibx-linux
SOURCES_DIR			=	sources
INCLUDE_DIR			=	include
BUILD_DIR			=	build

CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror -MMD -I $(INCLUDE_DIR)
LFLAGS				=	-L $(MLX_DIR) -lmlx -lXext -lX11 -lm
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
