/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:12:42 by ndabbous          #+#    #+#             */
/*   Updated: 2025/07/07 13:00:18 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clear_image(t_window *win)
{
	int		x;
	int		y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			my_mlx_pixel_put(win, x, y, 0x000000);
			x++;
		}
		y++;
	}
}

void	init_player(t_game *game)
{
	game->player.pos.x = game->map.player_x;
	game->player.pos.y = game->map.player_y;
	// game->player.orientation = game->map.player_dir;
	if (game->map.player_dir == 'S')
		game->player.angle = PI / 2; //90° vers le haut
	else if (game->map.player_dir == 'N')
		game->player.angle = 3 * PI / 2; //270° vers le bas
	else if (game->map.player_dir == 'E')
		game->player.angle = 0; //0° vers la droite
	else if (game->map.player_dir == 'W')
		game->player.angle = PI; //180° vers la gauche
}
