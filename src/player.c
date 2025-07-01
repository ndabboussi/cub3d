/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:12:42 by ndabbous          #+#    #+#             */
/*   Updated: 2025/07/01 15:04:31 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
