/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:22:12 by ndabbous          #+#    #+#             */
/*   Updated: 2025/07/02 18:59:59 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	get_textures(t_game *game, t_texture *texture, char *path)
{
	texture->img = mlx_xpm_file_to_image(game->window.mlx_ptr, path, \
					&texture->width, &texture->height);
	if (!texture->img)
	{
		ft_puterr_fd(ERR_TEXT_IMG, 2);
		ft_exit_all(game, 1);
	}
	texture->addr = mlx_get_data_addr(texture->img, &texture->bits_per_pixel, \
					&texture->line_length, &texture->endian);
	if (!texture->addr)
	{
		ft_puterr_fd(ERR_TEXT_ADDR, 2);
		ft_exit_all(game, 1);
	}
}

void	init_textures(t_game *game)
{
	get_textures(game, &game->no_texture, game->path.no_texture);
	get_textures(game, &game->so_texture, game->path.so_texture);
	get_textures(game, &game->we_texture, game->path.we_texture);
	get_textures(game, &game->ea_texture, game->path.ea_texture);
}

int	ft_init_mlx(t_game	*game)
{
	game->window.mlx_ptr = mlx_init();
	if (!game->window.mlx_ptr)
		return (ft_puterr_fd(MLX_PTR, 2), -1);
	game->window.screen_width = game->map.width;
	game->window.screen_height = game->map.height;
	game->window.mlx_window = mlx_new_window(game->window.mlx_ptr, \
								WIN_WIDTH, WIN_HEIGHT, "Cub3d - Nina & Pierre");
	if (!game->window.mlx_window)
		return (ft_puterr_fd(MLX_WIN, 2), -1);
	game->window.img = mlx_new_image(game->window.mlx_ptr, \
						WIN_WIDTH, WIN_HEIGHT);
	if (!game->window.img)
		return (ft_puterr_fd(MLX_IMAGE, 2), -1);
	game->window.addr = mlx_get_data_addr(game->window.img, \
		&game->window.bits_per_pixel, &game->window.line_length, \
		&game->window.endian);
	if (!game->window.addr)
		return (ft_puterr_fd(MLX_DATA, 2), -1);
	return (0);
}

void	init_window(t_game *game)
{
	if (check_textures_path(game->path) < 0)
	{
		ft_puterr_fd(ERR_TEXT_PATH, 2);
		ft_exit_all(game, 1);
	}
	if (ft_init_mlx(game) < 0)
		ft_exit_all(game, 1);
	init_textures(game);
}

void	init_player(t_game *game)
{
	game->player.pos.x = game->map.player_x;
	game->player.pos.y = game->map.player_y;
	if (game->map.player_dir == 'S')
		game->player.angle = PI / 2;
	else if (game->map.player_dir == 'N')
		game->player.angle = 3 * PI / 2;
	else if (game->map.player_dir == 'E')
		game->player.angle = 0;
	else if (game->map.player_dir == 'W')
		game->player.angle = PI;
}
