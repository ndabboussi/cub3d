/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:22:12 by ndabbous          #+#    #+#             */
/*   Updated: 2025/07/01 11:26:00 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_textures(t_game *game, t_texture *texture, char *path)
{
	int	width;
	int	height;

	texture->img = mlx_xpm_file_to_image(game->window.mlx_ptr, path, \
					&width, &height);
	if (!texture->img)
	{
		printf("Error: Could not load texture at path: %s\n", path);
		exit(EXIT_FAILURE);
	}
	texture->addr = mlx_get_data_addr(texture->img, &texture->bits_per_pixel, \
					&texture->line_length, &texture->endian);
	if (!texture->addr)
	{
		printf("Error: Could not get data address for texture: %s\n", path);
		exit(EXIT_FAILURE);
	}
}

void	init_textures(t_game *game)
{
	game->texture.no_texture = ft_strtrim(game->texture.no_texture, " \n\t");
	game->texture.so_texture = ft_strtrim(game->texture.so_texture, " \n\t");
	game->texture.we_texture = ft_strtrim(game->texture.we_texture, " \n\t");
	game->texture.ea_texture = ft_strtrim(game->texture.ea_texture, " \n\t");
	get_textures(game, &game->no_texture, game->texture.no_texture);
	get_textures(game, &game->so_texture, game->texture.so_texture);
	get_textures(game, &game->we_texture, game->texture.we_texture);
	get_textures(game, &game->ea_texture, game->texture.ea_texture);
}

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
	init_textures(game);
	//init_colors(game);
}
