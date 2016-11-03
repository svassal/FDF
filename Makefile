NAME =		fdf
SRC_DIR =	srcs
SRC =		$(SRC_DIR)/bresenham.c \
			$(SRC_DIR)/camera.c \
			$(SRC_DIR)/env.c \
			$(SRC_DIR)/fdf.c \
			$(SRC_DIR)/memory.c \
			$(SRC_DIR)/parse.c \
			$(SRC_DIR)/parse2.c \
			$(SRC_DIR)/point.c \
			$(SRC_DIR)/projection.c\
			$(SRC_DIR)/color.c \
			$(SRC_DIR)/image.c
OBJ =		$(SRC:.c=.o)
INC =		-I includes
LFT =		-Llibft -lft
LMLX =		-Lmlx -lmlx
LIB =		$(LFT) $(LMLX)
GRAPH =		-framework OpenGL -framework AppKit
FLAGS =		-Wall -Wextra -Werror
DEBUG = 	-g

$(NAME):	$(OBJ)
		make -C libft/
		make -C mlx/
		gcc -o $(NAME) $(OBJ) $(LIB) $(GRAPH)

debug:		$(OBJ)
		make -C libft/
		make -C mlx/
		gcc -o $(NAME) $(OBJ) $(LIB) $(GRAPH) $(DEBUG)

all:		$(NAME)

clean:
		make clean -C libft/
		make clean -C mlx/
		rm -f $(OBJ)

fclean:		clean
		make fclean -C libft/
		make clean -C mlx/
		rm -f $(NAME)

re:			fclean all

norme:
		norminette libft/*.c
		norminette libft/includes/*.h
		norminette srcs/*.c
		norminette includes/*.h

%.o:		%.c
		gcc -c $(INC) $(FLAGS) $^ -o $@