/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:03:07 by pde-vara          #+#    #+#             */
/*   Updated: 2025/02/20 11:04:43 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_inside(t_map *game)
{
	if (!game || !game->map)
		return (perror("impossible de charger la map"), -1);
	if (check_player(game) == -1)
		return (perror("erreur player"), -1);
	if (check_exit(game) == -1)
		return (perror("erreur exit"), -1);
	if (check_collectible(game) == -1)
		return (perror("erreur collectible"), -1);
	return (0);
}

int	initialize_game(t_map *game, char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (filename[len - 1] != 'r' || filename[len - 2] != 'e'
		|| filename[len - 3] != 'b' || filename[len - 4] != '.')
		return (perror("pas de fichier.ber\n"), 1);
	game->map = ft_map(filename);
	if (!game->map)
		return (perror("échec du chargement de la map\n"), 1);
	if (check_inside(game) == -1)
		return (free_map(game->map), 1);
	flood_fill(game);
	if (game->accessible_collectible != game->collectible)
	{
		perror("Tous les collectibles ne sont pas accessibles !\n");
		return (free_map(game->map), 1);
	}
	if (!game->exit_accessible)
	{
		perror("La sortie n'est pas accessible !\n");
		return (free_map(game->map), 1);
	}
	return (0);
}

int	display_game(t_game *ptr)
{
	if (!ptr)
		return (0);
	ptr->moves = 0;
	ptr->img.floor = 0;
	ptr->img.wall = 0;
	ptr->img.player = 0;
	ptr->img.collectible = 0;
	ptr->img.exit = 0;
	ptr->current = 0;
	ptr->mlx = NULL;
	ptr->win = NULL;
	ptr->mlx = mlx_init();
	if (!ptr->mlx)
		return (cleanup_images(ptr), perror("MLX init failed\n"), 0);
	if (!init_images(ptr))
		return (cleanup_images(ptr), perror("Failed to load images\n"), 0);
	if (!init_window(ptr))
		return (cleanup_images(ptr), perror("Failed to create window\n"), 0);
	render_map(ptr);
	mlx_hook(ptr->win, 2, 1L << 0, handle_keypress, ptr);
	mlx_hook(ptr->win, 17, 0, cleanup_images, ptr);
	mlx_loop(ptr->mlx);
	cleanup_images(ptr);
	return (1);
}

int	main(int ac, char **av)
{
	t_map	cursor;
	t_game	game;

	if (ac != 2)
	{
		perror("Error\n");
		return (1);
	}
	ft_memset(&cursor, 0, sizeof(t_map));
	if (initialize_game(&cursor, av[1]))
		return (1);
	game.map = cursor;
	if (display_game(&game))
		return (1);
	return (0);
}
