NAME_EXE = cub3D
NAME_EXE_BONUS = cub3D_bonus

ARGS = ./map/valid_map/map_1.cub

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
MLXFLAG = -lmlx -lXext -lX11 -Lminilibx-linux -Iminilibx-linux -lXext -lX11 -lm -lz

LIBFT_DIR = ./libft
SRC_DIR = ./src/
BONUS_DIR = ./src_bonus/
OBJ_DIR = ./obj/
INC_DIR = ./include/
MLX_DIR = ./minilibx-linux/

LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a

DIRS = minimap parsing raycasting utils

# -------------------- SRC Mandatory --------------------
FILES = main.c
PARSING_FILES = parser.c map_checker.c flood_fill.c init.c parser_utils.c parse_till_map.c
RAYCASTING_FILES = raycasting.c raycasting_utils.c cast_rays.c cast_rays_utils.c drawing_utils.c
UTILS_FILES = events.c clean.c movement.c rotation.c

SRC_FILES = \
	$(addprefix src/, $(FILES)) \
	$(addprefix src/parsing/, $(PARSING_FILES)) \
	$(addprefix src/raycasting/, $(RAYCASTING_FILES)) \
	$(addprefix src/utils/, $(UTILS_FILES))

OBJ = $(patsubst src/%.c, obj/%.o, $(SRC_FILES))
DEP = $(OBJ:.o=.d)

# -------------------- SRC Bonus --------------------
BONUS_FILES = main.c
BONUS_MINIMAP_FILES = map2d.c map2d_utils.c
BONUS_PARSING_FILES = parser.c map_checker.c flood_fill.c init.c parser_utils.c parse_till_map.c
BONUS_RAYCASTING_FILES = raycasting.c raycasting_utils.c cast_rays.c cast_rays_utils.c
BONUS_UTILS_FILES = events.c clean.c movement.c rotation.c

BONUS_SRC_FILES = \
	$(addprefix src_bonus/, $(BONUS_FILES)) \
	$(addprefix src_bonus/minimap/, $(BONUS_MINIMAP_FILES)) \
	$(addprefix src_bonus/parsing/, $(BONUS_PARSING_FILES)) \
	$(addprefix src_bonus/raycasting/, $(BONUS_RAYCASTING_FILES)) \
	$(addprefix src_bonus/utils/, $(BONUS_UTILS_FILES))

BONUS_OBJ = $(patsubst src_bonus/%.c, obj/bonus/%.o, $(BONUS_SRC_FILES))
BONUS_DEP = $(BONUS_OBJ:.o=.d)

# -------------------- Includes --------------------
INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

# Compilation mode

DIRS = 	minimap parsing raycasting utils

FILES = 			main.c
MINIMAP_FILES = 	map2d.c map2d_utils.c
PARSING_FILES = 	parser.c map_checker.c flood_fill.c init.c parser_utils.c parse_till_map.c
RAYCASTING_FILES =	raycasting.c raycasting_utils.c cast_rays.c cast_rays_utils.c
UTILS_FILES = 		events.c clean.c movement.c rotation.c


SRC_FILES = 	$(addprefix src/, $(FILES)) \
				$(addprefix src/minimap/, $(MINIMAP_FILES)) \
				$(addprefix src/parsing/, $(PARSING_FILES)) \
				$(addprefix src/raycasting/, $(RAYCASTING_FILES)) \
				$(addprefix src/utils/, $(UTILS_FILES))


OBJ = $(patsubst src/%.c, obj/%.o, $(SRC_FILES))
INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

# Compilation mode (silent by default, set VERBOSE=1 to show commands)
VERBOSE ?= 0
ifeq ($(VERBOSE),1)
V :=
else
V := @
endif

# Colors
DEFAULT = \033[0m
DEF_COLOR = \033[0;90m
WHITE = \033[1;37m
GREEN = \033[0;92m
YELLOW = \033[0;93m
CYAN = \033[0;96m
RED = \033[0;31m
RESET = \033[0m

# -------------------- Rules --------------------
all: $(OBJ_DIR) $(MLX_DIR) $(LIBFT) $(NAME_EXE)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@for dir in $(DIRS); do mkdir -p $(OBJ_DIR)/$$dir; done

$(NAME_EXE): $(OBJ) $(LIBFT)
	$(V)$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -L$(LIBFT_DIR) -L$(MLX_DIR) -lft -o $(NAME_EXE) $(MLXFLAG)
	$(V)echo "$(GREEN)[$(NAME_EXE)] Executable created ✅$(RESET)"

# Bonus build
bonus: bonus_dirs $(BONUS_OBJ) $(LIBFT) $(MLX)
	$(V)$(CC) $(CFLAGS) $(INCLUDES) $(BONUS_OBJ) -L$(LIBFT_DIR) -L$(MLX_DIR) -lft -o $(NAME_EXE_BONUS) $(MLXFLAG)
	$(V)echo "$(GREEN)[$(NAME_EXE_BONUS)] Bonus executable created ✅$(RESET)"

bonus_dirs:
	@mkdir -p obj/bonus
	@for dir in $(DIRS); do mkdir -p obj/bonus/$$dir; done

# -------------------- Compilation --------------------
$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	$(V)$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

obj/bonus/%.o: src_bonus/%.c | bonus_dirs
	@mkdir -p $(dir $@)
	@echo "$(CYAN)[BONUS] Compiling: $< $(DEF_COLOR)"
	$(V)$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

# -------------------- Dependencies --------------------
-include $(DEP)
-include $(BONUS_DEP)

# -------------------- Libraries --------------------
$(LIBFT):
	$(V)$(MAKE) --silent -C $(LIBFT_DIR)
	$(V)echo "[$(NAME_EXE)] Libft build successfully"

$(MLX_DIR):
	$(V)echo "[$(NAME_EXE)] Downloading MiniLibX from github.com...$(RESET)"
	@git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR) > /dev/null 2>&1
	$(V)echo "[$(NAME_EXE)] Compiling MiniLibX...$(RESET)"
	@$(MAKE) -C $(MLX_DIR) > /dev/null 2>&1
	$(V)echo "[$(NAME_EXE)] MiniLibX installed successfully$(RESET)"

# -------------------- Cleaning --------------------
clean:
	$(V)echo "$(RED)[$(NAME_EXE)] Cleaning objects$(RESET)"
	$(V)rm -rf $(OBJ_DIR)
	$(V)rm -rf obj/bonus
	$(V)$(MAKE) clean -C $(LIBFT_DIR) > /dev/null
	$(V)echo "$(GREEN)Object files cleaned!$(DEFAULT)"

fclean: clean
	$(V)echo "$(RED)[$(NAME_EXE)] Cleaning all files$(RESET)"
	$(V)rm -f $(NAME_EXE) $(NAME_EXE_BONUS)
	$(V)$(MAKE) fclean -C $(LIBFT_DIR) > /dev/null
	$(V)rm -rf $(MLX_DIR)
	$(V)echo "$(CYAN)Executables and objects removed successfully!$(DEFAULT)"

re: fclean all

all: $(OBJ_DIR) $(MLX_DIR) $(LIBFT) $(NAME_EXE)

go: all
	@./$(NAME_EXE) $(ARGS)
	@rm -rf $(NAME_EXE)

gov: all
	@valgrind --leak-check=full ./$(NAME_EXE) $(ARGS)
	@rm -rf $(NAME_EXE)

.PHONY: all bonus clean fclean re go gov
