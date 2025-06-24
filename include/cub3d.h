/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:59:54 by pde-vara          #+#    #+#             */
/*   Updated: 2025/06/24 12:22:24 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include "mlx.h"
# include "libft.h"
# include "mlx.h"
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

typedef struct s_map
{
	char	**map;
	int		player_x;
	int		player_y;
	char	player_dir;
}	t_map;

typedef struct s_color {
	int r;
	int g;
	int b;
}	t_color;

typedef struct s_texture
{
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	t_color floor;
	t_color ceiling;
}	t_texture;

typedef struct s_game
{
	t_texture	texture;
	t_map		map;
}	t_game;

// typedef struct s_window
// {
// 	void	*mlx_ptr;
// 	void	*mlx_window;
// 	void	*img;	
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_window;

// typedef struct s_world
// {
// 	t_window	*mlx;
// 	char		*map_name;
// }				t_world;
