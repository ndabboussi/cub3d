/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndabbous <ndabbous@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-25 18:02:16 by ndabbous          #+#    #+#             */
/*   Updated: 2025-06-25 18:02:16 by ndabbous         ###   ########.fr       */
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

void	draw_square(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < TILE_SIZE)
	{
		while (j < TILE_SIZE)
		{
			mlx_pixel_put(game->window.mlx_ptr, game->window.mlx_window, \
				x + (WIN_WIDTH / 2 + j), y + (WIN_HEIGHT / 2 + i), color);
			j++;
		}
		j = 0;
		i++;
	}
}

void	draw_map2d(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == '1')
				draw_square(game, x * TILE_SIZE, y * TILE_SIZE, \
					0xFFFFFF); //white for walls
			else if (game->map.map[y][x] == '0' || game->map.map[y][x] == ' ')
				draw_square(game, x * TILE_SIZE, y * TILE_SIZE, \
					0x000000); //black for floor
			x++;
		}
		y++;
	}
}

void	clear_image(t_window *win)
{
	int		x;
	int		y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			my_mlx_pixel_put(win, x, y, 0x000000);
			x++;
		}
		y++;
	}
}

int	print_map_2d(t_game *game)
{
	clear_image(&game->window);
	draw_map2d(game);
	return (0);
}