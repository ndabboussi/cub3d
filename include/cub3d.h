/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:59:54 by pde-vara          #+#    #+#             */
/*   Updated: 2025/06/25 14:58:32 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#include "mlx.h"
#include "libft.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <math.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

#define WIN_WIDTH 2048
#define WIN_HEIGHT 1080

#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_LEFT 65361
#define KEY_RIGHT 65363
#define KEY_ESC 65307


typedef struct s_coordinates
{
	float 	x;
	float 	y;
	float 	angle;
}			t_coordinates;

typedef struct s_player
{
	int				size;
	t_coordinates	pos;
	t_coordinates	dir;
	double			orientation;
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

typedef struct s_color {
	int r;
	int g;
	int b;
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

typedef struct s_path
{
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	t_color floor;
	t_color ceiling;
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

typedef struct s_game
{
	t_texture	no_texture;
	t_texture	so_texture;
	t_texture	we_texture;
	t_texture	ea_texture;
	t_player	player;
	t_path		texture;
	t_window	window;
	t_map		map;
}	t_game;

#define RED "\033[31;01m"
#define RESET "\033[00m"

//PARSING
int		parse_file(char *filename, t_game *game);
int		check_map_validity(t_game *game);
int		flood_fill(t_game *game);
void	free_map(char **map);

//INIT
void	init_window(t_game *game);
int		ft_key_handler(int keycode, t_game *game);

void	init_player(t_game *game);

//CLEAN
int		ft_close_window(t_game *game);
void	ft_exit_all(t_game *game, int d);

//utils print
void	print_map(char **map);
void	print_texture(t_path *tex);