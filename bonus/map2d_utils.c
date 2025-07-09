/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 12:33:35 by ndabbous          #+#    #+#             */
/*   Updated: 2025/07/07 18:33:03 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_window *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_square(t_game *game, float x, float y, float size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			my_mlx_pixel_put(&game->window, x + j, y + i, 0xff00ff);
			j++;
		}
		j = 0;
		i++;
	}
}

void	draw_square_wall(t_game *game, float x, float y, float size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			my_mlx_pixel_put(&game->window, x + j, y + i, 0xFFFFFF);
			j++;
		}
		j = 0;
		i++;
	}
}

int	color_to_int(t_color color)
{
	return ((color.r << 16) | (color.g << 8) | color.b);
}

void	draw_player(t_game *game)
{
	int	player_map_x;
	int	player_map_y;

	player_map_x = game->player.pos.x * TILE_SIZE * game->minimap_scale;
	player_map_y = game->player.pos.y * TILE_SIZE * game->minimap_scale;
	draw_square(game, player_map_x - PLAYER_SIZE / 2, \
		player_map_y - PLAYER_SIZE / 2, PLAYER_SIZE);
}
