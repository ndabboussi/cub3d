/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:59:54 by pde-vara          #+#    #+#             */
/*   Updated: 2025/07/02 18:37:04 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <string.h>
# include <stdbool.h>
# include <errno.h>
# include <math.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

# define ERR_USAGE "Usage: ./cub3D map.cub\n"
# define ERR_FORMAT "Format: need a .cub\n"

# define ERR_MAP "Parse_file: ft_split fail and no map allocation\n"
# define ERR_OPEN "Parse_line_by_line : Failed to open .cub\n"
# define ERR_NO_T_PATH "Check_config_complete: Missing texture path\n"
# define ERR_NO_F_COLOR "Check_config_complete: Missing floor color\n"
# define ERR_NO_C_COLOR "Check_config_complete: Missing ceiling color\n"
# define ERR_MAP_VALIDITY "Check_map_validity : no map send\n"
# define ERR_PLAYER "Check_player : 0 or more than 1 player found\n"
# define ERR_MAP_CHAR "Check_forbidden_char : invalid char found\n"

# define ERR_ALLOC "Memory allocation failed\n"

# define WIN_WIDTH 2048
# define WIN_HEIGHT 1080

# define TILE_SIZE 16
# define MINIMAP_SIZE 10

#define MINIMAP_WIDTH  300
#define MINIMAP_HEIGHT 300
#define MINIMAP_MARGIN 10

# define TEXTURE_W 64
# define TEXTURE_H 64
#define PLAYER_SIZE 8

# define FOV 60
# define PI 3.14159265358979323846

# define MOVE_SPEED 0.1
# define ROT_SPEED (PI / 30)

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307

typedef struct s_coordinates
{
	float	x;
	float	y;
}			t_coordinates;

typedef struct s_player
{
	t_coordinates	pos;
	double			angle;
}			t_player;

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
	float	player_x;
	float	player_y;
	char	player_dir;
}	t_map;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;


typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_texture;

typedef struct s_rays
{
	float		distance;
	t_texture	*texture;
	int			texture_x;
	int			side;
}	t_rays;

typedef struct s_path
{
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	t_color	floor;
	t_color	ceiling;
}	t_path;

typedef struct s_window
{
	void	*mlx_ptr;
	void	*mlx_window;
	void	*img;
	char	*addr;
	int		screen_width;
	int		screen_height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_window;

typedef struct s_dda
{
	int		map_x; //position actuelle du rayon dans la grille (map)
	int		map_y;
	float	ray_x; //direction du rayon
	float	ray_y;
	float	ray_dir_x; //distance nécessaire pour parcourir une case entière en x
	float	ray_dir_y;
	float	delta_dist_x;
	float	delta_dist_y;
	float	side_dist_x; //distance actuelle entre le rayon et le premier mur potentiel en x
	float	side_dist_y;
	int		step_x; //direction dans laquelle on avance (gauche -1 ou droite +1)
	int		step_y;
	int		side; //0 si collision sur un mur vertical, 1 si sur un mur horizontal (utile pour la texture plus tard)
}	t_dda;

typedef struct s_game
{
	t_texture	no_texture;
	t_texture	so_texture;
	t_texture	we_texture;
	t_texture	ea_texture;
	t_player	player;
	t_path		path;
	t_window	window;
	t_map		map;
	float		minimap_scale;
}	t_game;

# define RED "\033[31;01m"
# define RESET "\033[00m"

//PARSING
int		parse_file(char *filename, t_game *game);
int		check_map_validity(t_game *game);
int		flood_fill(t_game *game);

//INIT
void	init_window(t_game *game);
int		ft_key_handler(int keycode, t_game *game);
int		ft_mouse_hook(int x, int y, void *data);
void	init_colors(t_color *floor, t_color *ceiling);

void	init_player(t_game *game);

//DISPLAY
int		print_map_2d(t_game *game);
int		render_frame(t_game *game);
void	clear_image(t_window *win);
void	my_mlx_pixel_put(t_window *img, int x, int y, int color);
void	draw_minimap(t_game *game);
void	draw_line(t_game *game, int x0, int y0, int x1, int y1, int color);

//CLEAN & ERRORS
void	ft_puterr_fd(char *s, int fd);
void	free_double_tab(char **map);
int		ft_close_window(t_game *game);
void	ft_exit_all(t_game *game, int status);

//MOVEMENT
int		is_walkable(t_game *g, float x, float y);
void	move_forward(t_game *g);
void	move_backward(t_game *g);
void	move_left(t_game *g);
void	move_right(t_game *g);
void	rotate_left(t_game *g);
void	rotate_right(t_game *g);
void	rotate_left_mouse(t_game *g);
void	rotate_right_mouse(t_game *g);

//RAYCASTING
void	draw_vertical_line(t_window *win, int x, int start, int end, int color);
int		color_to_int(t_color color);
int		perform_dda(t_game *game, t_dda *d);
t_rays	cast_ray(t_game *game, float ray_angle);

//UTILS PRINT
void	print_map(char **map);
void	print_texture(t_path *tex);
void	print_path(t_path *path);
void	print_coordinates(t_coordinates *coord, const char *label);
void	print_player(t_player *player);

//2D
void	draw_map2d(t_game *game);
void	draw_player(t_game *game);
void	draw_rays(t_game *game);

#endif