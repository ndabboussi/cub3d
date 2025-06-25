/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndabbous <ndabbous@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-25 16:12:42 by ndabbous          #+#    #+#             */
/*   Updated: 2025-06-25 16:12:42 by ndabbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_game *game)
{
	game->player.pos.x = game->map.player_x + 0.5;
	game->player.pos.y = game->map.player_y + 0.5;
	game->player.orientation = game->map.player_dir;
	if (game->player.orientation == 'N')
		game->player.angle = PI / 2; //90° vers le haut
	else if (game->player.orientation == 'S')
		game->player.angle = 3 * PI / 2; //270° vers le bas
	else if (game->player.orientation == 'E')
		game->player.angle = 0; //0° vers la droite
	else if (game->player.orientation == 'W')
		game->player.angle = PI; //180° vers la gauche
}
