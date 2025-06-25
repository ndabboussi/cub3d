/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndabbous <ndabbous@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-24 15:14:56 by ndabbous          #+#    #+#             */
/*   Updated: 2025-06-24 15:14:56 by ndabbous         ###   ########.fr       */
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

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	ft_exit_all(t_game *game, int code)
{
	(void)code;
	if (game->window.img)
		mlx_destroy_image(game->window.mlx_ptr, game->window.img);
	if (game->window.mlx_window)
		mlx_destroy_window(game->window.mlx_ptr, game->window.mlx_window);
	if (game->window.mlx_ptr)
	{
		mlx_destroy_display(game->window.mlx_ptr);
		free(game->window.mlx_ptr);
	}
	if (game->map.map)
		free_map(game->map.map);
	// ft_free_textures;
	// ft_free_colors;
	//put_error(NULL);
}
