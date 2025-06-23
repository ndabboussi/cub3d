/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:59:54 by pde-vara          #+#    #+#             */
/*   Updated: 2025/06/23 14:43:26 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

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
	char	player_dir;
}	t_map;

typedef struct s_img
{
	void	*floor;
	void	*wall;
	void	*player;
	int		width;
	int		height;
}	t_img;

typedef struct s_game
{
	t_config	config;
	t_map		map;
}	t_game;