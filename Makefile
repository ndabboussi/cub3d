
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
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a

FILES = main.c parser.c map_checker.c flood_fill.c \
		init.c events.c map2d.c clean.c map2d_utils.c \
		movement.c raycasting.c raycasting_utils.c \
		cast_rays.c cast_rays_utils.c parser_utils.c \
		parse_till_map.c rotation.c
		

OBJ = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))
INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

# Compilation mode (silent by default, set VERBOSE=1 to show commands)
VERBOSE ?= 0
ifeq ($(VERBOSE),1)
V :=
else
V := @
endif

DEFAULT = \033[0m
DEF_COLOR = \033[0;90m
WHITE = \033[1;37m
GREEN = \033[0;92m
YELLOW = \033[0;93m
CYAN = \033[0;96m
RED = \033[0;31m
RESET = \033[0m

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

all: $(OBJ_DIR) $(MLX_DIR) $(LIBFT) $(NAME_EXE)

$(OBJ_DIR):
	$(V)mkdir -p $(OBJ_DIR) || true

# Dependencies
DEP = $(OBJ:.o=.d)
$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	$(V)$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

-include $(DEP)

$(NAME_EXE): $(OBJ) $(LIBFT)
	$(V)$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -L$(LIBFT_DIR) -L$(MLX_DIR) -lft -o $(NAME_EXE) $(MLXFLAG)
	$(V)echo "$(GREEN)[$(NAME_EXE)] Executable created ✅$(RESET)"

# Libft
$(LIBFT):
	$(V)$(MAKE) --silent -C $(LIBFT_DIR)
	$(V)echo "[$(NAME_EXE)] Libft build successfully"

# MiniLibX
$(MLX_DIR):
	$(V)echo "[$(NAME_EXE)] Downloading MiniLibX from github.com...$(RESET)"
	@git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR) > /dev/null 2>&1
	$(V)echo "[$(NAME_EXE)] Compiling MiniLibX...$(RESET)"
	@$(MAKE) -C $(MLX_DIR) > /dev/null 2>&1
	$(V)echo "[$(NAME_EXE)] MiniLibX installed successfully$(RESET)"

clean:
	$(V)echo "$(RED)[$(NAME_EXE)] Cleaning objects$(RESET)"
	$(V)rm -rf $(OBJ_DIR)
	$(V)$(MAKE) clean -C $(LIBFT_DIR) > /dev/null
	$(V)echo "$(GREEN)$(NAME_EXE) object files cleaned!$(DEFAULT)"

fclean: clean
	$(V)echo "$(RED)[$(NAME_EXE)] Cleaning all files$(RESET)"
	$(V)rm -f $(NAME_EXE)
	$(V)$(MAKE) fclean -C $(LIBFT_DIR) > /dev/null
	$(V)echo "$(RED)[mlx] Remove directory$(RESET)"
	@rm -rf $(MLX_DIR)
	$(V)echo "$(CYAN)$(NAME_EXE) executables and objects removed successfully!$(DEFAULT)"

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

.PHONY: all clean fclean re go gov test