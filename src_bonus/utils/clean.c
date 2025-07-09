/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:14:56 by ndabbous          #+#    #+#             */
/*   Updated: 2025/07/02 18:58:24 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_puterr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	printf("Error\n");
	if (fd < 0)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	free_double_tab(char **map)
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

void	free_texture(t_game *game, t_texture *texture)
{
	if (texture->img && game->window.mlx_ptr)
		mlx_destroy_image(game->window.mlx_ptr, texture->img);
	texture->img = NULL;
	texture->addr = NULL;
}

void	free_paths(t_path *path)
{
	if (path->no_texture)
		free(path->no_texture);
	if (path->so_texture)
		free(path->so_texture);
	if (path->we_texture)
		free(path->we_texture);
	if (path->ea_texture)
		free(path->ea_texture);
	path->no_texture = NULL;
	path->so_texture = NULL;
	path->we_texture = NULL;
	path->ea_texture = NULL;
}

void	ft_exit_all(t_game *game, int status)
{
	free_texture(game, &game->no_texture);
	free_texture(game, &game->so_texture);
	free_texture(game, &game->we_texture);
	free_texture(game, &game->ea_texture);
	free_paths(&game->path);
	if (game->map.map)
		free_double_tab(game->map.map);
	if (game->window.img)
		mlx_destroy_image(game->window.mlx_ptr, game->window.img);
	if (game->window.mlx_window)
		mlx_destroy_window(game->window.mlx_ptr, game->window.mlx_window);
	if (game->window.mlx_ptr)
	{
		mlx_loop_end(game->window.mlx_ptr);
		mlx_destroy_display(game->window.mlx_ptr);
		free(game->window.mlx_ptr);
	}
	exit(status);
}
