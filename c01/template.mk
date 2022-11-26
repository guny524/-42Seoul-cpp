NAME		?=
CC			=	c++

# HD_DIR		=	include/
# SRC_DIR		=	src/
# MLX_DIR		=	minilibx_opengl_20191021

SRC_ORI		?=
BSRC_ORI	?=

SRC			=	$(addprefix $(SRC_DIR), $(SRC_ORI))
BSRC		=	$(addprefix $(SRC_DIR), $(BSRC_ORI))

OBJ			=	$(SRC:.cpp=.o)
BOBJ		=	$(BSRC:.cpp=.o)

CFLAGS		+=	-std=c++98 -Wall -Wextra -Werror # -g # -fsanitize=address
CPPFLAGS	+=	# -I $(HD_DIR) -I $(MLX_DIR)
LIBADD		+=	# -lm -lmlx -framework OpenGL -framework Appkit -lpthread
LDFLAGS		+=	# -L$(MLX_DIR)

all:		$(NAME)

%.o:		%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $<

$(NAME):	$(OBJ)
# @make -C $(MLX_DIR) 2> /dev/null
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LIBADD) $^ -o $@

bonus:		$(BOBJ)
# @make -C $(MLX_DIR) 2> /dev/null
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LIBADD) $^ -o $(NAME)
	touch bonus

clean:
	rm -f $(OBJ)
	rm -f $(BOBJ)
	rm -f $(OBJ:.o=.d)
	rm -f $(BOBJ:.o=.d)
	rm -f bonus
# @make -C $(MLX_DIR) clean 2> /dev/null

fclean:		clean
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY:		all clean fclean re bonus
