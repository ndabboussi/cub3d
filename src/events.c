/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndabbous <ndabbous@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-24 16:11:24 by ndabbous          #+#    #+#             */
/*   Updated: 2025-06-24 16:11:24 by ndabbous         ###   ########.fr       */
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
		printf("[KEY] W\n");
	else if (keycode == KEY_S)
		printf("[KEY] S\n");
	else if (keycode == KEY_A)
		printf("[KEY] A\n");
	else if (keycode == KEY_D)
		printf("[KEY] D\n");
	else if (keycode == KEY_LEFT)
		printf("[KEY] LEFT\n");
	else if (keycode == KEY_RIGHT)
		printf("[KEY] RIGHT\n");
	return (0);
}
