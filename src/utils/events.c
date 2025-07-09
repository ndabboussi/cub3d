/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:11:24 by ndabbous          #+#    #+#             */
/*   Updated: 2025/07/02 18:59:22 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close_window(t_game *game)
{
	ft_exit_all(game, 1);
	return (-1);
}

int	ft_key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		ft_close_window(game);
	if (keycode == KEY_W)
		game->player.k_pressed[0] = 1;
	if (keycode == KEY_S)
		game->player.k_pressed[1] = 1;
	if (keycode == KEY_A)
		game->player.k_pressed[2] = 1;
	if (keycode == KEY_D)
		game->player.k_pressed[3] = 1;
	if (keycode == KEY_LEFT)
		game->player.k_pressed[4] = 1;
	if (keycode == KEY_RIGHT)
		game->player.k_pressed[5] = 1;
	return (0);
}

int	ft_key_release(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->player.k_pressed[0] = 0;
	if (keycode == KEY_S)
		game->player.k_pressed[1] = 0;
	if (keycode == KEY_A)
		game->player.k_pressed[2] = 0;
	if (keycode == KEY_D)
		game->player.k_pressed[3] = 0;
	if (keycode == KEY_LEFT)
		game->player.k_pressed[4] = 0;
	if (keycode == KEY_RIGHT)
		game->player.k_pressed[5] = 0;
	return (0);
}

void	handle_movement(t_game *game)
{
	if (game->player.k_pressed[0])
		move_forward(game);
	if (game->player.k_pressed[1])
		move_backward(game);
	if (game->player.k_pressed[2])
		move_left(game);
	if (game->player.k_pressed[3])
		move_right(game);
	if (game->player.k_pressed[4])
		rotate_left(game);
	if (game->player.k_pressed[5])
		rotate_right(game);
}
