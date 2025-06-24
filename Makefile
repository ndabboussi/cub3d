NAME_EXE = cub3d

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
MLXFLAG = -lmlx -lXext -lX11 -Lminilibx-linux -Iminilibx-linux -lXext -lX11 -lm -lz

LIBFT_DIR = ./libft
SRCS_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./include/
MLX_DIR = ./minilibx-linux/

FILES = main.c

OBJ = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))

INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

DEFAULT = \033[0m
DEF_COLOR = \033[0;90m
WHITE = \033[1;37m
GREEN = \033[0;92m
YELLOW = \033[0;93m
CYAN = \033[0;96m

all: $(NAME_EXE)

$(NAME_EXE): $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(MLX_DIR)
	@echo "$(GREEN)$(NAME_EXE) compiled!$(DEFAULT)"
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -L$(LIBFT_DIR) -L$(MLX_DIR) -lft -o $(NAME_EXE) $(MLXFLAG)

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c | $(OBJ_DIR)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ)
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(MLX_DIR)
	@echo "$(GREEN)$(NAME_EXE) object files cleaned!$(DEFAULT)"

fclean: clean
	@rm -rf $(NAME_EXE)
	@echo "$(CYAN)$(NAME_EXE) executables and objects removed successfully!$(DEFAULT)"
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@echo "$(CYAN) executables and objects removed successfully!$(DEFAULT)"

re: fclean all

.PHONY: all clean fclean re