/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:22:12 by ndabbous          #+#    #+#             */
/*   Updated: 2025/07/02 12:21:38 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_textures(t_game *game, t_texture *texture, char *path)
{
	// int	width;
	// int	height;

	texture->img = mlx_xpm_file_to_image(game->window.mlx_ptr, path, \
					&texture->width, &texture->height);
	if (!texture->img)
	{
		printf("Error: Could not load texture at path: %s\n", path);
		ft_exit_all(game, EXIT_FAILURE);
	}
	texture->addr = mlx_get_data_addr(texture->img, &texture->bits_per_pixel, \
					&texture->line_length, &texture->endian);
	if (!texture->addr)
	{
		printf("Error: Could not get data address for texture: %s\n", path);
		ft_exit_all(game, EXIT_FAILURE);
	}
}

int	check_textures_path(t_path path)
{
	int fd;

	fd = open(path.no_texture, O_RDONLY);
	if (fd < 0)
		return (-1);
	close(fd);

	fd = open(path.so_texture, O_RDONLY);
	if (fd < 0)
		return (-1);
	close(fd);

	fd = open(path.ea_texture, O_RDONLY);
	if (fd < 0)
		return (-1);
	close(fd);

	fd = open(path.we_texture, O_RDONLY);
	if (fd < 0)
		return (-1);
	close(fd);

	return (0);
}

void	init_textures(t_game *game)
{
	if (check_textures_path(game->path) < 0)
		return (printf("Error: Invalid texture path(s)\n"), ft_exit_all(game, EXIT_FAILURE));
	get_textures(game, &game->no_texture, game->path.no_texture);
	get_textures(game, &game->so_texture, game->path.so_texture);
	get_textures(game, &game->we_texture, game->path.we_texture);
	get_textures(game, &game->ea_texture, game->path.ea_texture);
}

void	init_window(t_game *game)
{
	game->window.mlx_ptr = mlx_init();
	if (!game->window.mlx_ptr)
	{
		printf("Error: mlx_init failed\n");
		ft_exit_all(game, EXIT_FAILURE);
	}
	game->window.screen_width = game->map.width;
	game->window.screen_height = game->map.height;
	game->window.mlx_window = mlx_new_window(game->window.mlx_ptr, \
								WIN_WIDTH, WIN_HEIGHT, "Cub3d - Pierna");
	if (!game->window.mlx_window)
	{
		printf("Error: mlx_new_window failed\n");
		ft_exit_all(game, EXIT_FAILURE);
	}
	game->window.img = mlx_new_image(game->window.mlx_ptr, \
						WIN_WIDTH, WIN_HEIGHT);
	if (!game->window.img)
	{
		printf("Error: mlx_new_image failed\n");
		ft_exit_all(game, EXIT_FAILURE);
	}
	game->window.addr = mlx_get_data_addr(game->window.img, \
		&game->window.bits_per_pixel, &game->window.line_length, \
		&game->window.endian);
	if (!game->window.addr)
	{
		printf("Error: mlx_get_data_addr failed\n");
		ft_exit_all(game, EXIT_FAILURE);
	}
	init_textures(game);
}
