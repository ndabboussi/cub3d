/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:54:34 by ndabbous          #+#    #+#             */
/*   Updated: 2025/07/02 18:59:26 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	get_map_borders(t_game *game)
{
	int	i;
	int	len;
	int	max_w;

	i = 0;
	max_w = 0;
	game->map.height = 0;
	game->map.width = 0;
	while (game->map.map[i])
	{
		game->map.height++;
		i++;
	}
	i = 0;
	while (game->map.map[i])
	{
		len = 0;
		while (game->map.map[i][len])
			len++;
		if (len > max_w)
			max_w = len;
		i++;
	}
	game->map.width = max_w;
}

char	**create_map_copy(t_game *game, char **map)
{
	int		i;
	int		j;
	char	**copy;

	copy = malloc(sizeof(char *) * (game->map.height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < game->map.height)
	{
		copy[i] = malloc(sizeof(char) * (game->map.width + 1));
		if (!copy[i])
			return (NULL);
		j = 0;
		while (j < game->map.width)
		{
			if (j < ft_strlen(map[i]))
					copy[i][j] = map[i][j];
			j++;
		}
		copy[i][game->map.width] = '\0';
		i++;
	}
	copy[game->map.height] = NULL;
	return (copy);
}

int	fill(t_game *game, char **map, int x, int y)
{
	if (x < 0 || y < 0 || y >= game->map.height || x >= game->map.width)
		return (0);
	if (map[y][x] == ' ')
		return (0);
	if (map[y][x] == '1' || map[y][x] == 'V')
		return (1);
	map[y][x] = 'V';
	if (!fill(game, map, x + 1, y))
		return (0);
	if (!fill(game, map, x - 1, y))
		return (0);
	if (!fill(game, map, x, y + 1))
		return (0);
	if (!fill(game, map, x, y - 1))
		return (0);
	return (1);
}

int	flood_fill(t_game *game)
{
	char	**map_copy;
	int		i;

	i = 0;
	if (!game || !game->map.map)
		return (-1);
	get_map_borders(game);
	map_copy = create_map_copy(game, game->map.map);
	if (!map_copy)
		return (ft_puterr_fd(ERR_COPY_ALLOC, 2), -1);
	if (!fill(game, map_copy, game->map.player_x, game->map.player_y))
	{
		free_double_tab(map_copy);
		return (ft_puterr_fd(ERR_FLOOD, 2), -1);
	}
	free_double_tab(map_copy);
	return (1);
}
