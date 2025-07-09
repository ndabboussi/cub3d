/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:55:38 by pde-vara          #+#    #+#             */
/*   Updated: 2025/07/08 18:19:04 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	main(int ac, char **av)
{
	t_game	game;
	int		len;

	if (ac != 2)
		return (ft_puterr_fd(ERR_USAGE, 2), 1);
	len = ft_strlen(av[1]);
	if (len < 4 || ft_strncmp(av[1] + len - 4, ".cub", 4) != 0)
		return (ft_puterr_fd(ERR_FORMAT, 2), 1);
	ft_memset(&game, 0, sizeof(t_game));
	game.path.floor = (t_color){-1, -1, -1};
	game.path.ceiling = (t_color){-1, -1, -1};
	if (parse_file(av[1], &game) < 0)
		ft_exit_all(&game, 1);
	if (check_map_validity(&game) < 0)
		ft_exit_all(&game, 1);
	init_window(&game);
	init_player(&game);
	mlx_hook(game.window.mlx_window, 17, 0, ft_close_window, &game);
	mlx_hook(game.window.mlx_window, 2, 1L << 0, &ft_key_press, &game);
	mlx_hook(game.window.mlx_window, 3, 1L << 1, &ft_key_release, &game);
	mlx_hook(game.window.mlx_window, 6, 1L << 6, ft_mouse_hook, &game);
	mlx_loop_hook(game.window.mlx_ptr, render_frame, &game);
	mlx_loop(game.window.mlx_ptr);
	ft_exit_all(&game, 0);
	return (0);
}
