NAME_EXE = cub3D

ARGS = ./map/valid_map/map_1.cub

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
MLXFLAG = -lmlx -lXext -lX11 -Lminilibx-linux -Iminilibx-linux -lXext -lX11 -lm -lz

LIBFT_DIR = ./libft
SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./include/
MLX_DIR = ./minilibx-linux/

FILES = print.c main.c parser.c map_checker.c flood_fill.c \
		init.c events.c player.c display.c clean.c \
		movement.c DDA_textures.c

OBJ = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))

INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

DEFAULT = \033[0m
DEF_COLOR = \033[0;90m
WHITE = \033[1;37m
GREEN = \033[0;92m
YELLOW = \033[0;93m
CYAN = \033[0;96m

INVALID_MAPS = \
	map/invalid_map/additionnal_element.cub \
	map/invalid_map/doople_element.cub \
	map/invalid_map/doople_F_C.cub \
	map/invalid_map/invalid_path.cub \
	map/invalid_map/invalid_path_2.cub \
	map/invalid_map/lower_case.cub \
	map/invalid_map/missing_F_C.cub \
	map/invalid_map/missing_link.cub \
	map/invalid_map/missing_player.cub \
	map/invalid_map/wrong_border.cub \
	map/invalid_map/wrong_border_2.cub \
	map/invalid_map/wrong_char.cub \
	map/invalid_map/wrong_color.cub \
	map/invalid_map/map.txt \
	map/invalid_map/inexistant_map.cub \
	map/invalid_map/invalid_texture.cub \
	map/invalid_map/vide.cub \
	map/invalid_map/wrong_color_2.cub 

all: $(NAME_EXE)

$(NAME_EXE): $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null
	@$(MAKE) -C $(MLX_DIR) > /dev/null 2>&1
	@echo "$(GREEN)$(NAME_EXE) compiled!$(DEFAULT)"
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -L$(LIBFT_DIR) -L$(MLX_DIR) -lft -o $(NAME_EXE) $(MLXFLAG)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ)
	@$(MAKE) clean -C $(LIBFT_DIR) > /dev/null
#	@$(MAKE) clean -C $(MLX_DIR) > /dev/null
	@echo "$(GREEN)$(NAME_EXE) object files cleaned!$(DEFAULT)"

fclean: clean
	@rm -rf $(NAME_EXE)
	@echo "$(CYAN)$(NAME_EXE) executables and objects removed successfully!$(DEFAULT)"
	@$(MAKE) fclean -C $(LIBFT_DIR) > /dev/null
	@echo "$(CYAN)executables and objects removed successfully!$(DEFAULT)"

re: fclean all

test: all
	@for file in $(INVALID_MAPS); do \
		echo ""; \
		echo "Testing $$file..."; \
		./$(NAME_EXE) $$file || true; \
	done
	@echo ""; echo "Testing without arguments..."; \
	./$(NAME_EXE) || true

go: all
	@./$(NAME_EXE) $(ARGS)
	@rm -rf $(NAME_EXE)

gov: all
	@valgrind --leak-check=full ./$(NAME_EXE) $(ARGS)
	@rm -rf $(NAME_EXE)

.PHONY: all clean fclean re go gov