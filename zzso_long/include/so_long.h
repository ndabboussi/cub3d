/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:37:27 by pde-vara          #+#    #+#             */
/*   Updated: 2025/01/28 19:18:45 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include "libft.h"

typedef struct s_map
{
	char	**map;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		collectible;
	int		accessible_collectible;
	int		exit_accessible;
}	t_map;

typedef struct s_img
{
	void	*floor;
	void	*wall;
	void	*player;
	void	*collectible;
	void	*exit;
	int		width;
	int		height;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		current;
	int		moves;
	t_map	map;
	t_img	img;
}	t_game;

int		initialize_game(t_map *game, char *filename);
int		check_player(t_map *game);
int		check_exit(t_map *game);
int		check_collectible(t_map *game);
int		check_inside(t_map *game);
int		ft_countlines(char *str);
int		is_rectangle(char **map);
char	*lecture_map(char *str);
int		wall_check(char **map);
void	free_map(char **map);
char	**ft_map(char *filename);
void	fill(t_map *game, int x, int y, char **map_copy);
void	flood_fill(t_map *game);
int		init_images(t_game *game);
int		init_window(t_game *game);
void	draw_tile(t_game *game, void *img, int x, int y);
int		render_map(t_game *game);

int		display_game(t_game *ptr);
int		handle_keypress(int keycode, t_game *game);
void	move_player(t_game *game, int new_x, int new_y);
int		close_window(t_game *game);
void	handle_exit(t_game *game, char next_pos);
int		cleanup_images(t_game *ptr);

#endif