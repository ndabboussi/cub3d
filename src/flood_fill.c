/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndabbous <ndabbous@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-23 14:54:34 by ndabbous          #+#    #+#             */
/*   Updated: 2025-06-23 14:54:34 by ndabbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_map_copy(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static int	get_max_width(char **map)
{
	int	i;
	int	max_width;
	int	len;

	i = 0;
	max_width = 0;
	while (map[i])
	{
		len = 0;
		while (map[i][len])
			len++;
		if (len > max_width)
			max_width = len;
		i++;
	}
	return (max_width);
}

static char	**copy_and_normalize_map(char **map, int height, int *width_out)
{
	char	**copy;
	int		width;
	int		i;
	int		j;

	width = get_max_width(map);
	*width_out = width;
	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = malloc(sizeof(char) * (width + 1));
		if (!copy[i])
			return (NULL);
		j = 0;
		while (j < width)
		{
			if (j < (int)ft_strlen(map[i]))
			{
				if (map[i][j] == ' ')
					copy[i][j] = '-';
				else
					copy[i][j] = map[i][j];
			}
			else
				copy[i][j] = '-';
			j++;
		}
		copy[i][width] = '\0';
		i++;
	}
	copy[height] = NULL;
	return (copy);
}

static int	fill(char **map, int x, int y, int height, int width)
{
	if (x < 0 || y < 0 || y >= height || x >= width)
		return (0);
	if (map[y][x] == '-' || map[y][x] == ' ')
		return (0);
	if (map[y][x] == '1' || map[y][x] == 'V')
		return (1);
	map[y][x] = 'V';
	if (!fill(map, x + 1, y, height, width))
		return (0);
	if (!fill(map, x - 1, y, height, width))
		return (0);
	if (!fill(map, x, y + 1, height, width))
		return (0);
	if (!fill(map, x, y - 1, height, width))
		return (0);
	return (1);
}

int	flood_fill(t_game *game)
{
	char	**map_copy;
	int		height;
	int		width;

	if (!game || !game->map.map)
		return (0);
	height = 0;
	while (game->map.map[height])
		height++;
	map_copy = copy_and_normalize_map(game->map.map, height, &width);
	if (!map_copy)
		return (perror("Error : alloc failure\n"), 1);
	if (map_copy[game->map.player_y][game->map.player_x] == 'N'
		|| map_copy[game->map.player_y][game->map.player_x] == 'S'
		|| map_copy[game->map.player_y][game->map.player_x] == 'E'
		|| map_copy[game->map.player_y][game->map.player_x] == 'W')
		map_copy[game->map.player_y][game->map.player_x] = '0';
	if (!fill(map_copy, game->map.player_x, game->map.player_y, height, width))
	{
		free_map_copy(map_copy);
		return (0);
	}
	free_map_copy(map_copy);
	return (1);
}

// void	fill(t_game *game, int x, int y, char **map_copy)
// {
// 	int	map_height;

// 	if (!game || !game->map.map)
// 		return ;
// 	map_height = 0;
// 	while (game->map.map[map_height])
// 		map_height++;
// 	if (y < 0 || y >= map_height)
// 		return ;
// 	if (x < 0 || x >= (int)ft_strlen(map_copy[y]))
// 		return ;
// 	if (map_copy[y][x] == '1' || map_copy[y][x] == 'V')
// 		return ;
// 	map_copy[y][x] = 'V';
// 	fill(game, x + 1, y, map_copy);
// 	fill(game, x - 1, y, map_copy);
// 	fill(game, x, y + 1, map_copy);
// 	fill(game, x, y - 1, map_copy);
// }

// void	flood_fill(t_game *game, char **map)
// {
// 	char	**map_copy;
// 	int		i;
// 	int		height;

// 	if (!map)
// 		return ;
// 	height = 0;
// 	while (map[height])
// 		height++;
// 	map_copy = malloc(sizeof(char *) * (height + 1));
// 	if (!map_copy)
// 		return ;
// 	i = -1;
// 	while (++i < height)
// 	{
// 		map_copy[i] = strdup(map[i]);
// 		if (!map_copy[i])
// 			return (free_map(map_copy));
// 	}
// 	map_copy[height] = NULL;
// 	fill(game, game->map.player_x, game->map.player_y, map_copy);
// 	free_map(map_copy);
// }
