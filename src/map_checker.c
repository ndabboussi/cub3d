/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:50:07 by ndabbous          #+#    #+#             */
/*   Updated: 2025/07/01 11:32:28 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_player(t_game *game)
{
	int	x;
	int	y;
	int	nb_p;

	nb_p = 0;
	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == 'N' || game->map.map[y][x] == 'S' \
				|| game->map.map[y][x] == 'E' || game->map.map[y][x] == 'W')
			{
				nb_p++;
				game->map.player_dir = game->map.map[y][x];
				game->map.player_x = x;
				game->map.player_y = y;
			}
			x++;
		}
		y++;
	}
	if (nb_p != 1)
		return (ft_puterr_fd(ERR_PLAYER, 2), -1);
	return (0);
}

int	check_forbidden_char(t_game *game)
{
	int	x;
	int	y;
	int	nb_p;

	nb_p = 0;
	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] != '0' && game->map.map[y][x] != '1' \
				&& game->map.map[y][x] != 'N' && game->map.map[y][x] != 'S' \
				&& game->map.map[y][x] != 'E' && game->map.map[y][x] != 'W' \
				&& game->map.map[y][x] != ' ')
				return (ft_puterr_fd(ERR_MAP_CHAR, 2), -1);
			x++;
		}
		y++;
	}
	return (0);
}

int	check_map_validity(t_game *game)
{
	if (!game || !game->map.map)
		return (ft_puterr_fd(ERR_MAP_VALIDITY, 2), -1);
	if (check_player(game) == -1)
		return (-1);
	if (check_forbidden_char(game) == -1)
		return (-1);
	if (!flood_fill(game))
		return (perror("Error : invalid map.\n"), -1);
	return (0);
}
