/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:02:16 by ndabbous          #+#    #+#             */
/*   Updated: 2025/07/02 18:59:03 by pde-vara         ###   ########.fr       */
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

void	draw_square(t_game *game, int x, int y, int size, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			my_mlx_pixel_put(&game->window, x + j, y + i, color);
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

	player_map_x = game->player.pos.x * TILE_SIZE ;
	player_map_y = game->player.pos.y * TILE_SIZE;
	draw_square(game, player_map_x - PLAYER_SIZE / 2, player_map_y - PLAYER_SIZE / 2, PLAYER_SIZE, 0xff00ff);
}


void draw_line(t_game *game, int x0, int y0, int x1, int y1, int color)
{
	int dx = abs(x1 - x0); // Absolute distances between x and y coordinates
	int dy = abs(y1 - y0);
	int sx = x0 < x1 ? 1 : -1; // Step direction for x
	int sy = y0 < y1 ? 1 : -1; // Step direction for y
	int err = dx - dy; // Error accumulator
	int e2;

	while (1)
	{
		// Only draw the pixel if it's within window bounds
		if (x0 >= 0 && x0 < WIN_WIDTH && y0 >= 0 && y0 < WIN_HEIGHT)
			my_mlx_pixel_put(&game->window, x0, y0, color);
		// Stop when the end point is reached
		if (x0 == x1 && y0 == y1)
			break ;

		e2 = 2 * err;
		// Move in x direction
		if (e2 > -dy)
		{
			err -= dy;
			x0 += sx;
		}
		// Move in y direction
		if (e2 < dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}

void draw_rays(t_game *game)
{
	int		i;
	int		num_rays;
	double	ray_angle;

	// Starting point of all rays: player's pixel position
	double start_x = game->player.pos.x * TILE_SIZE;
	double start_y = game->player.pos.y * TILE_SIZE;

	t_rays distance;
		
	i = 0;
	num_rays = WIN_WIDTH / 4; // Draw every 4th ray to avoid clutter
	while (i < num_rays)
	{
		// Calculate ray angle (same logic as in render_frame)
		ray_angle = game->player.angle
			- (FOV * PI / 180.0 / 2.0)  // Start at leftmost FOV angle
			+ ((double)(i * 4) / WIN_WIDTH) * (FOV * PI / 180.0); // Step toward right
		// Cast the ray to get distance
		distance = cast_ray(game, ray_angle);
		// Convert distance to 2D map coordinates
		double end_x = start_x + cos(ray_angle) * distance.distance * TILE_SIZE;
		double end_y = start_y + sin(ray_angle) * distance.distance * TILE_SIZE;

		draw_line(game, (int)start_x, (int)start_y, (int)end_x, (int)end_y, 0x00FF00);// Draw the ray line
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
				draw_square(game, x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, 0xFFFFFF); //white for walls
			// else if (game->map.map[y][x] == '0' || game->map.map[y][x] == ' ')
			// 	draw_square(game, x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, 0x000000); //black for floor
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
// meilleure version ??

// void clear_image(t_window *win) 
// {
// 	int i;
// 	int total_pixels;
// 	int *pixels;

// 	i = 0;
// 	total_pixels = WIN_WIDTH * WIN_HEIGHT;
// 	pixels = (int *)win->addr;
// 	while (i < total_pixels)
// 		pixels[i++] = 0x000000;
// }