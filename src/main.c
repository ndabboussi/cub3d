/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:55:38 by pde-vara          #+#    #+#             */
/*   Updated: 2025/06/23 16:40:46 by pde-vara         ###   ########.fr       */
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

int	check_inside(t_game *game)
{
	if (!game || !game->map.map)
		return (perror("impossible de charger la map"), -1);
	if (check_player(game) == -1)
		return (perror("erreur player"), -1);
	return (0);
}


char	*lecture_map(char *filename)
{
	int		fd;
	char	*line;
	char	*content;
	char	*temp;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (perror("Erreur: fichier non trouvé ou illisible\n"), NULL);
	content = ft_strdup("");
	if (!content)
		return (perror("Err: alloc failed\n"), close(fd), NULL);
	line = get_next_line(fd);
	while (line != NULL)
	{
		temp = content;
		content = ft_strjoin(content, line);
		if (!content)
			return (perror("Err: alloc failed\n"), close(fd), NULL);
		free(line);
		free(temp);
		line = NULL;
		line = get_next_line(fd);
	}
	close(fd);
	return (content);
}

// int	wall_check(char **map)
// {
// 	int	x;
// 	int	y;

// 	if (!map || !map[0])
// 		return (-1);
// 	y = 0;
// 	while (map[y])
// 	{
// 		x = 0;
// 		while (map[y][x] && map[y][x] != '\n')
// 		{
// 			if ((y == 0 || !map[y + 1] || x == 0 || !map[y][x + 1])
// 				&& map[y][x] != '1')
// 				return (-1);
// 			if (map[y][x] != 'N' && map[y][x] != 'S' && map[y][x] != 'E'
//				&& map[y][x] != 'W'
// 				&& map[y][x] != '1' && map[y][x] != '0')
// 			{
// 				return (perror("ya du nimporte quoi dans la map"), -1);
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (0);
// }

char	**ft_map(char *filename)
{
	char	**map;
	char	*content;

	content = lecture_map(filename);
	if (!content)
		return (NULL);
	map = NULL;
	map = ft_split(content, '\n');
	free(content);
	if (!map)
		return (perror("Err: map alloc failed\n"), NULL);
	// if (wall_check(map) == -1)
	// {
	// 	perror("Erreur: la map n'est pas entourée de murs\n");
	// 	free_map(map);
	// 	return (NULL);
	// }
	return (map);
}
// char *texture_check(game)
// {
// 	return (*texture_end);
// }

int	initialize_game(t_game *game, char *filename)
{
	//char	*texture_end;
	int		len;

	len = ft_strlen(filename);
	if (filename[len - 1] != 'b' || filename[len - 2] != 'u'
		|| filename[len - 3] != 'c' || filename[len - 4] != '.')
		return (perror("pas de fichier.cub\n"), 1);
	game->map.map = ft_map(filename);
	if (!game->map.map)
		return (perror("échec du chargement de la map\n"), 1);
	if (check_inside(game) == -1)
		return (free_map(game->map.map), 1);
	//texture_check(game)
	if (flood_fill(game) < 0)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (perror("Usage: ./cub3D map.cub\n"), 1);
	ft_memset(&game, 0, sizeof(t_game));
	if (initialize_game(&game, av[1]))
		return (perror("Error : invalid map\n"), 1);
	return (0);
}
