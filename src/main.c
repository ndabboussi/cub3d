/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:55:38 by pde-vara          #+#    #+#             */
/*   Updated: 2025/06/25 14:54:10 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_game	game;
	int len;
  
	if (ac != 2)
		return (printf("Usage: ./cub3D map.cub\n"), 1);
		
	len = ft_strlen(av[1]);
	if (av[1][len - 1] != 'b' || av[1][len - 2] != 'u'
		|| av[1][len - 3] != 'c' || av[1][len - 4] != '.')
		return (perror("Error : \n"), 1);
	ft_memset(&game, 0, sizeof(t_game));
	if (parse_file(av[1], &game) < 0)
		return (-1);

	// ✅ Print texture paths
	printf("NO texture: %s\n", game.texture.no_texture);
	printf("SO texture: %s\n", game.texture.so_texture);
	printf("WE texture: %s\n", game.texture.we_texture);
	printf("EA texture: %s\n", game.texture.ea_texture);

	// ✅ Print floor and ceiling RGB values
	printf("Floor color:   R=%d G=%d B=%d\n", game.texture.floor.r, game.texture.floor.g, game.texture.floor.b);
	printf("Ceiling color: R=%d G=%d B=%d\n", game.texture.ceiling.r, game.texture.ceiling.g, game.texture.ceiling.b);
	
	// print_map(game.map.map);
	
	if (check_map_validity(&game) != 0)
		return (1);
	return (0);
}
