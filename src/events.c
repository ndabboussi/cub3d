/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:11:24 by ndabbous          #+#    #+#             */
/*   Updated: 2025/06/27 16:15:11 by pde-vara         ###   ########.fr       */
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
