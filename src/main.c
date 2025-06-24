/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:55:38 by pde-vara          #+#    #+#             */
/*   Updated: 2025/06/24 15:01:52 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(char **map)
{
	int	j;

	j = 0;
	if (!map)
		return ;
	while (map[j])
	{
		free(map[j]);
		j++;
	}
	free(map);
	map = NULL;
}

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
				game->map.player_x = x;
				game->map.player_y = y;
			}
			x++;
		}
		y++;
	}
	if (nb_p != 1)
		return (-1);
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
				return (-1);
			x++;
		}
		y++;
	}
	return (0);
}

int	check_inside(t_game *game)
{
	if (!game || !game->map.map)
		return (perror("impossible de charger la map"), -1);
	if (check_player(game) == -1)
		return (perror("Error : more than one player"), -1);
	if (check_forbidden_char(game) == -1)
		return (perror("Error : map should only be composed of 0 & 1"), -1);
	return (0);
}

int	initialize_game(t_game *game)
{
	if (check_inside(game) == -1)
		return (free_map(game->map.map), 1);
	if (!flood_fill(game))
		return (1);
	return (0);
}

int main(int ac, char **av)
{
	t_game game;
	int		len;

	if (ac != 2)
		return (printf("Usage: ./cub3D map.cub\n"), 1);
		
	len = ft_strlen(av[1]);
	if (av[1][len - 1] != 'b' || av[1][len - 2] != 'u'
		|| av[1][len - 3] != 'c' || av[1][len - 4] != '.')
		return (perror("Error : \n"), 1);
	
	ft_memset(&game, 0, sizeof(t_game));
	if (parse_file(av[1], &game) != 0)
		return (1);
	if (initialize_game(&game))
 		return (perror("Error : invalid map\n"), 1);
	return (0);
}
