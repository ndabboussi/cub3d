/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:14:56 by ndabbous          #+#    #+#             */
/*   Updated: 2025/07/02 11:42:34 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void free_texture(t_game *game, t_texture *texture)
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

// void	ft_exit_all(t_game *game, int status)
// {
// 	if (game->path.no_texture)
// 		free(game->path.no_texture);
// 	if (game->path.so_texture)
// 		free(game->path.so_texture);
// 	if (game->path.we_texture)
// 		free(game->path.we_texture);
// 	if (game->path.ea_texture)
// 		free(game->path.ea_texture);
// 	if (game->map.map)
// 		free_double_tab(game->map.map);
// 	if (game->window.mlx_window)
// 		mlx_destroy_window(game->window.mlx_ptr, game->window.mlx_window);
// 	if (game->window.img)
// 		mlx_destroy_image(game->window.mlx_ptr, game->window.img);
// 	mlx_loop_end(game->window.mlx_ptr);
// 	// put_error(NULL);
// 	exit(status);
// }


void ft_exit_all(t_game *game, int status)
{
    // Clean up texture images
    free_texture(game, &game->no_texture);
    free_texture(game, &game->so_texture);
    free_texture(game, &game->we_texture);
    free_texture(game, &game->ea_texture);
    
    // Clean up paths
    free_paths(&game->path);
    
    // Clean up map
    if (game->map.map)
        free_double_tab(game->map.map);
    
    // Clean up window resources
    if (game->window.img)
        mlx_destroy_image(game->window.mlx_ptr, game->window.img);
    if (game->window.mlx_window)
        mlx_destroy_window(game->window.mlx_ptr, game->window.mlx_window);
    
    // Clean up MLX
    if (game->window.mlx_ptr)
    {
        mlx_loop_end(game->window.mlx_ptr);
        mlx_destroy_display(game->window.mlx_ptr);
        free(game->window.mlx_ptr);
    }
    
    exit(status);
}
