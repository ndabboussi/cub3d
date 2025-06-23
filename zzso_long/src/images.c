/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:16:53 by pde-vara          #+#    #+#             */
/*   Updated: 2025/01/28 19:22:25 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_images(t_game *game)
{
	game->img.floor = mlx_xpm_file_to_image(game->mlx,
			"textures/floor.xpm", &game->img.width, &game->img.height);
	if (!game->img.floor)
		return (ft_printf("Error: Failed to load 'floor.xpm'\n"), 0);
	game->img.wall = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &game->img.width, &game->img.height);
	if (!game->img.wall)
		return (ft_printf("Error: Failed to load 'wall.xpm'\n"), 0);
	game->img.player = mlx_xpm_file_to_image(game->mlx,
			"textures/player.xpm", &game->img.width, &game->img.height);
	if (!game->img.player)
		return (ft_printf("Error: Failed to load 'player.xpm'\n"), 0);
	game->img.collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &game->img.width, &game->img.height);
	if (!game->img.collectible)
		return (ft_printf("Error: Failed to load 'collectible.xpm'\n"), 0);
	game->img.exit = mlx_xpm_file_to_image(game->mlx,
			"textures/exit.xpm", &game->img.width, &game->img.height);
	if (!game->img.exit)
		return (ft_printf("Error: Failed to load 'exit.xpm'\n"), 0);
	if (!game->img.floor || !game->img.wall || !game->img.player
		|| !game->img.collectible || !game->img.exit)
		return (0);
	return (1);
}

int	init_window(t_game *game)
{
	int	width;
	int	height;

	width = ft_strlen(game->map.map[0]) * game->img.width;
	height = 0;
	while (game->map.map[height])
		height++;
	height *= game->img.height;
	game->win = mlx_new_window(game->mlx, width, height, "so_long");
	if (!game->win)
		return (0);
	return (1);
}

void	draw_tile(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img,
		x * game->img.width, y * game->img.height);
}

int	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == '1')
				draw_tile(game, game->img.wall, x, y);
			else if (game->map.map[y][x] == 'P')
				draw_tile(game, game->img.player, x, y);
			else if (game->map.map[y][x] == 'C')
				draw_tile(game, game->img.collectible, x, y);
			else if (game->map.map[y][x] == 'E')
				draw_tile(game, game->img.exit, x, y);
			else
				draw_tile(game, game->img.floor, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

void	handle_exit(t_game *game, char next_pos)
{
	if (next_pos == 'E' && game->map.collectible == 0)
	{
		ft_printf("\nCongratulations! You won in %d moves!\n", game->moves + 1);
		mlx_loop_end(game->mlx);
		return ;
	}
	if (next_pos == 'E' && game->map.collectible > 0)
	{
		game->current = 1;
		ft_printf("Collect all items ! Remaining: %d\n", game->map.collectible);
	}
}
