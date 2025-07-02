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
	if (game->window.mlx_window)
		mlx_destroy_window(game->window.mlx_ptr, game->window.mlx_window);
	if (game->window.img)
		mlx_destroy_image(game->window.mlx_ptr, game->window.img);
	mlx_loop_end(game->window.mlx_ptr);
	exit(0);
}

int	ft_key_handler(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		ft_close_window(game);
	else if (keycode == KEY_W)
		move_forward(game);
	else if (keycode == KEY_S)
		move_backward(game);
	else if (keycode == KEY_A)
		move_left(game);
	else if (keycode == KEY_D)
		move_right(game);
	else if (keycode == KEY_LEFT)
		rotate_left(game);
	else if (keycode == KEY_RIGHT)
		rotate_right(game);
	return (0);
}

int	ft_mouse_hook(int x, int y, void *data)
{
	t_game	*game;

	(void)y;
	game = (t_game *)data;
	if (x > WIN_WIDTH / 2)
		rotate_right_mouse(game);
	if (x < WIN_WIDTH / 2)
		rotate_left_mouse(game);
	mlx_mouse_move(game->window.mlx_ptr, game->window.mlx_window, \
			WIN_WIDTH / 2, WIN_HEIGHT / 2);
	return (0);
}
