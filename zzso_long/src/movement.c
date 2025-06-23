/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:14:32 by pde-vara          #+#    #+#             */
/*   Updated: 2025/01/29 14:40:01 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, int new_x, int new_y)
{
	char		next_pos;

	next_pos = game->map.map[new_y][new_x];
	if (next_pos == '1')
		return ;
	if (game->current == 1)
	{
		game->map.map[game->map.player_y][game->map.player_x] = 'E';
		game->current = 0;
	}
	else
		game->map.map[game->map.player_y][game->map.player_x] = '0';
	handle_exit(game, next_pos);
	if (next_pos == 'C')
		game->map.collectible--;
	game->moves++;
	game->map.map[new_y][new_x] = 'P';
	game->map.player_x = new_x;
	game->map.player_y = new_y;
	ft_printf("Moves: %d | Coraux restants: %d\n",
		game->moves, game->map.collectible);
	render_map(game);
}

int	handle_keypress(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->map.player_x;
	new_y = game->map.player_y;
	if (keycode == 65307)
		return (cleanup_images(game), 0);
	if (keycode == 119 || keycode == 65362)
		new_y--;
	else if (keycode == 115 || keycode == 65364)
		new_y++;
	else if (keycode == 97 || keycode == 65361)
		new_x--;
	else if (keycode == 100 || keycode == 65363)
		new_x++;
	if (new_x != game->map.player_x || new_y != game->map.player_y)
		move_player(game, new_x, new_y);
	return (0);
}

int	cleanup_images(t_game *ptr)
{
	if (!ptr)
		exit(EXIT_SUCCESS);
	if (ptr->img.floor)
		mlx_destroy_image(ptr->mlx, ptr->img.floor);
	if (ptr->img.wall)
		mlx_destroy_image(ptr->mlx, ptr->img.wall);
	if (ptr->img.player)
		mlx_destroy_image(ptr->mlx, ptr->img.player);
	if (ptr->img.collectible)
		mlx_destroy_image(ptr->mlx, ptr->img.collectible);
	if (ptr->img.exit)
		mlx_destroy_image(ptr->mlx, ptr->img.exit);
	if (ptr->win)
		mlx_destroy_window(ptr->mlx, ptr->win);
	if (ptr->mlx)
	{
		mlx_destroy_display(ptr->mlx);
		free(ptr->mlx);
		ptr->mlx = NULL;
	}
	if (ptr->map.map)
		free_map(ptr->map.map);
	exit(EXIT_SUCCESS);
}
