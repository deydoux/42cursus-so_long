NAME				=	so_long

SOURCES				=	deal_key.c	\
						so_long.c

LIBFT_DIR			=	libft
MLX_DIR				=	minilibx-linux
SOURCES_DIR			=	sources
INCLUDE_DIR			=	include
OBJECTS_DIR			=	.objects

CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror -MMD -I $(INCLUDE_DIR)
LFLAGS				=	-lmlx -lXext -lX11 -L $(MLX_DIR)
RM					=	rm -rf
MKDIR				=	mkdir -p

LIBFT				=	$(LIBFT_DIR)/libft.a
MLX					=	$(MLX_DIR)/libmlx.a
OBJECTS				=	$(addprefix $(OBJECTS_DIR)/,$(SOURCES:.c=.o))
DEPENDENCIES		=	$(OBJECTS:.o=.d)

all					:	$(NAME)

-include 				$(DEPENDENCIES)

$(LIBFT)			:
	$(MAKE) -C $(@D) $(@F)

$(MLX)				:
	$(MAKE) -C $(@D) all

$(OBJECTS_DIR)/%.o	:	$(SOURCES_DIR)/%.c
	@$(MKDIR) $(@D)
	$(CC) $(CFLAGS) -o $@ -c	$<

$(NAME)				:	$(OBJECTS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ $^

clean				:
	$(MAKE) -C $(LIBFT_DIR) $@
	$(MAKE) -C $(MLX_DIR) $@
	$(RM) $(OBJECTS_DIR)

fclean				:
	$(MAKE) -C $(LIBFT_DIR) $@
	$(MAKE) -C $(MLX_DIR) clean
	$(RM) $(OBJECTS_DIR) $(NAME)

re					:	fclean all

.PHONY				:	all clean fclean re
