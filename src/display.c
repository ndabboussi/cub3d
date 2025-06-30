/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:02:16 by ndabbous          #+#    #+#             */
/*   Updated: 2025/06/27 12:44:40 by pde-vara         ###   ########.fr       */
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
			my_mlx_pixel_put(&game->window, \
				x + j, y + i, color);
			j++;
		}
		j = 0;
		i++;
	}
}

void	draw_player(t_game *game)
{
	int	player_map_x;
	int	player_map_y;

	player_map_x = game->player.pos.x * TILE_SIZE;
	player_map_y = game->player.pos.y * TILE_SIZE;
	draw_square(game, player_map_x, player_map_y, \
					0xff00ff);
}

void	draw_ray(t_game *game)
{
	int		ray_length;
	double	end_x;
	double	end_y;

	ray_length = 50;
	end_x = game->player.pos.x * TILE_SIZE \
				+ cos(game->player.angle) * ray_length;
	end_y = game->player.pos.y * TILE_SIZE \
					+ sin(game->player.angle) * ray_length;
	// while ()
	// {
		my_mlx_pixel_put(&game->window, \
				(int)end_x, (int)end_y, 0x00FF00);
	// }
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
//meilleure version ??

// void clear_image(t_window *win) 
// {
// 	int i;
// 	int total_pixels = WIN_WIDTH * WIN_HEIGHT;
// 	int *pixels = (int *)win->addr;

// 	i = 0;
// 	while (i < total_pixels)
// 		pixels[i++] = 0x000000;
// }

int	print_map_2d(t_game *game)
{
	clear_image(&game->window);
	draw_map2d(game);
	draw_player(game);
	draw_ray(game);
	mlx_put_image_to_window(game->window.mlx_ptr, \
		game->window.mlx_window, game->window.img, 0, 0);
	return (0);
}
