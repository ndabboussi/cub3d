/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:55:38 by pde-vara          #+#    #+#             */
/*   Updated: 2025/06/25 14:58:18 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_game	game;
	int		len;

	if (ac != 2)
		return (printf("Usage: ./cub3D map.cub\n"), 1);
	len = ft_strlen(av[1]);
	if (av[1][len - 1] != 'b' || av[1][len - 2] != 'u'
		|| av[1][len - 3] != 'c' || av[1][len - 4] != '.')
		return (perror("Error : \n"), 1);
	ft_memset(&game, 0, sizeof(t_game));
	if (parse_file(av[1], &game) < 0)
		return (-1);
	//print_texture(&game.texture);
	//print_map(game.map.map);
	if (check_map_validity(&game) != 0)
		return (1);
	init_window(&game);
	//print_path(&game.texture);
	init_player(&game);
	mlx_hook(game.window.mlx_window, 17, 0, ft_close_window, &game);
	mlx_hook(game.window.mlx_window, 2, 1L << 0, ft_key_handler, &game);
	mlx_loop_hook(game.window.mlx_ptr, print_map_2d, &game);
	mlx_loop(game.window.mlx_ptr);
	ft_exit_all(&game, 0);
	return (0);
}
