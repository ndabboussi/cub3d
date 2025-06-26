/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndabbous <ndabbous@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-24 14:22:12 by ndabbous          #+#    #+#             */
/*   Updated: 2025-06-24 14:22:12 by ndabbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	init_map_textures(t_game *game)
// {

// }

void	init_window(t_game *game)
{
	game->window.mlx_ptr = mlx_init();
	if (!game->window.mlx_ptr)
	{
		perror("Error : mlx_init failed.\n");
		exit(EXIT_FAILURE);
	}
	game->window.screen_width = game->map.width;
	game->window.screen_height = game->map.height;
	game->window.mlx_window = mlx_new_window(game->window.mlx_ptr, \
								WIN_WIDTH, WIN_HEIGHT, "Cub3d - Pierna");
	if (!game->window.mlx_window)
	{
		perror("Error : mlx_new_window failed.\n");
		exit(EXIT_FAILURE);
	}
	game->window.img = mlx_new_image(game->window.mlx_ptr, \
						WIN_WIDTH, WIN_HEIGHT);
	if (!game->window.img)
	{
		perror("Error : mlx_new_image failed.\n");
		exit(EXIT_FAILURE);
	}
	game->window.addr = mlx_get_data_addr(game->window.img, \
		&game->window.bits_per_pixel, &game->window.line_length, \
		&game->window.endian);
	//init_map_textures(game);
	//init_textures(game);
	//init_colors(game);
}
