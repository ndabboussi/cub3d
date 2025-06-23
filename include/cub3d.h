/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:59:54 by pde-vara          #+#    #+#             */
/*   Updated: 2025/06/23 15:13:04 by pde-vara         ###   ########.fr       */
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

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
	int		player_x;
	int		player_y;
	char	player_dir;
}	t_map;

typedef struct s_config
{
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	int		floor_color;
	int		ceiling_color;
}	t_config;

typedef struct s_window
{
	void	*mlx_ptr;
	void	*mlx_window;
	void	*img;	
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_window;

typedef struct s_game
{
	t_config	config;
	t_map		map;
}	t_game;

//PARSING
// void	flood_fill(t_game *game, char **map);
int	flood_fill(t_game *game);
void	free_map(char **map);

//utils print
void	print_map(char **map);