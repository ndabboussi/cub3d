/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:11:24 by ndabbous          #+#    #+#             */
/*   Updated: 2025/06/26 18:48:51 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close_window(t_game *game)
{
	mlx_loop_end(game->window.mlx_ptr);
	return (0);
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
