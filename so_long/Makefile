
NAME = so_long

SRCDIR = src
OBJDIR = obj
INCDIR = include

# Source Files
SRC = main.c parse_map.c images.c movement.c parse_utils.c
OBJ = $(SRC:.c=.o)
SRC := $(addprefix $(SRCDIR)/, $(SRC))
OBJ := $(patsubst $(SRCDIR)/%, $(OBJDIR)/%, $(OBJ))

LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a
LIBFT_INCLUDE := $(LIBFT_DIR)

MINILIBX_DIR := ./minilibx-linux
MLX := $(MINILIBX_DIR)/libmlx.a

LDFLAGS =  -L$(MINILIBX_DIR) -L$(LIBFT_DIR)
LIBS =  $(MLX) $(LIBFT)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCDIR) -g3 -I$(MINILIBX_DIR) -I/usr/include/X11 -I$(LIBFT_INCLUDE)

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	MLXFLAGS += -lmlx -lXext -lX11
else ifeq ($(UNAME_S),Darwin)
	MLXFLAGS += -L/opt/X11/lib -lX11 -lXext -lXrandr -lXcursor
endif


# Compilation mode (silent by default, set VERBOSE=1 to show commands)
VERBOSE ?= 0
ifeq ($(VERBOSE),1)
  V := 
else
  V := @
endif

RED     := "\033[1;31m"
GREEN   := "\033[1;32m"
RESET   := "\033[0m"


all: $(OBJDIR) $(MINILIBX_DIR) $(LIBFT) $(NAME)

$(OBJDIR):
	$(V)mkdir -p $(OBJDIR) || true

DEP = $(OBJ:.o=.d)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@mkdir -p $(dir $@)
	$(V)$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

-include $(DEP)

$(NAME): $(OBJ) $(LIBFT)
	$(V)$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) $(BONUS_OBJ) $(LIBS) $(MLXFLAGS) -o $(NAME)
	$(V)echo $(GREEN)"[$(NAME)] Executable created ✅"$(RESET)

# Libft
$(LIBFT):
	$(V)$(MAKE) --silent -C $(LIBFT_DIR)
	$(V)echo '[$(NAME)] Libft build successfully'

# MiniLibX
$(MINILIBX_DIR):
	$(V)echo '[$(NAME)] Downloading MiniLibX from github.com...'$(RESET)
	@git clone https://github.com/42Paris/minilibx-linux.git $(MINILIBX_DIR) > /dev/null 2>&1
	$(V)echo '[$(NAME)] Compiling MiniLibX...'$(RESET)
	@$(MAKE) -C $(MINILIBX_DIR) > /dev/null 2>&1
	$(V)echo '[$(NAME)] MiniLibX installed successfully'$(RESET)

clean:
	$(V)echo $(RED)'[$(NAME)] Cleaning objects'd$(RESET)
	$(V)rm -rf $(OBJDIR)

fclean: clean
	$(V)echo $(RED)'[$(NAME)] Cleaning all files'$(RESET)
	$(V)rm -f $(NAME)
	$(V)$(MAKE) --silent -C $(LIBFT_DIR) fclean
	$(V)echo $(RED)'[mlx] Remove directory'$(RESET)
	@rm -rf $(MINILIBX_DIR)

re: fclean all

.PHONY: all clean fclean re
.DEFAULT_GOAL := all
