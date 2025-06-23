/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:01:20 by pde-vara          #+#    #+#             */
/*   Updated: 2025/01/28 19:15:56 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//check_map

int	check_player(t_map *game)
{
	int	x;
	int	y;
	int	nb_p;

	nb_p = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				nb_p++;
				game->player_x = x;
				game->player_y = y;
			}
			x++;
		}
		y++;
	}
	if (nb_p != 1)
		return (-1);
	return (0);
}

int	check_exit(t_map *game)
{
	int	x;
	int	y;
	int	nb_e;

	nb_e = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'E')
			{
				nb_e++;
				game->exit_x = x;
				game->exit_y = y;
			}
			x++;
		}
		y++;
	}
	if (nb_e != 1)
		return (-1);
	return (0);
}

int	check_collectible(t_map *game)
{
	int	x;
	int	y;
	int	nb_c;

	nb_c = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
			{
				nb_c++;
				game->collectible = nb_c;
			}
			x++;
		}
		y++;
	}
	if (nb_c < 1)
		return (-1);
	return (0);
}

void	fill(t_map *game, int x, int y, char **map_copy)
{
	int	map_height;

	if (!game || !game->map)
		return ;
	map_height = 0;
	while (game->map[map_height])
		map_height++;
	if (y < 0 || y >= map_height)
		return ;
	if (x < 0 || x >= (int)ft_strlen(map_copy[y]))
		return ;
	if (map_copy[y][x] == '1' || map_copy[y][x] == 'V')
		return ;
	if (map_copy[y][x] == 'C')
		game->accessible_collectible++;
	if (map_copy[y][x] == 'E')
		game->exit_accessible = 1;
	map_copy[y][x] = 'V';
	fill(game, x + 1, y, map_copy);
	fill(game, x - 1, y, map_copy);
	fill(game, x, y + 1, map_copy);
	fill(game, x, y - 1, map_copy);
}

void	flood_fill(t_map *game)
{
	char	**map_copy;
	int		i;
	int		height;

	if (!game || !game->map)
		return ;
	height = 0;
	while (game->map[height])
		height++;
	map_copy = malloc(sizeof(char *) * (height + 1));
	if (!map_copy)
		return ;
	i = -1;
	while (++i < height)
	{
		map_copy[i] = strdup(game->map[i]);
		if (!map_copy[i])
			return (free_map(map_copy));
	}
	map_copy[height] = NULL;
	game->accessible_collectible = 0;
	fill(game, game->player_x, game->player_y, map_copy);
	free_map(map_copy);
}
