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


void	draw_square(t_game *game, int x, int y, int size, int color, double scale)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
  
	while (i < MINIMAP_TILE_SIZE *scale)
	{
		while (j < MINIMAP_TILE_SIZE *scale)
		{
			my_mlx_pixel_put(&game->window, \
				MINIMAP_MARGIN + x + j,MINIMAP_MARGIN + y + i, color);
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
	double start_x = game->player.pos.x * MINIMAP_TILE_SIZE;
	double start_y = game->player.pos.y * MINIMAP_TILE_SIZE;
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
		double end_x = start_x + cos(ray_angle) * distance.distance * MINIMAP_TILE_SIZE;
		double end_y = start_y + sin(ray_angle) * distance.distance * MINIMAP_TILE_SIZE;

		draw_line(game, (int)start_x, (int)start_y, (int)end_x, (int)end_y, 0x00FF00);// Draw the ray line
		i++;
	}
}

void draw_player_minimap(t_game *game, double scale)
{
	int player_x = game->player.pos.x * MINIMAP_TILE_SIZE * scale;
	int player_y = game->player.pos.y * MINIMAP_TILE_SIZE * scale;

	draw_square(game, player_x, player_y, 0xFF0000, scale);
}

void	draw_map2d(t_game *game)
{
	int		x;
	int		y;
	double	scale_x;
	double	scale_y;
	double	scale;

	scale_x = (double)MINIMAP_WIDTH / (game->map.width * MINIMAP_TILE_SIZE);
	scale_y = (double)MINIMAP_HEIGHT / (game->map.height * MINIMAP_TILE_SIZE);
	if (scale_x < scale_y)
		scale = scale_x;
	else 
		scale = scale_y;	
	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == '1')
				draw_square(game, x * MINIMAP_TILE_SIZE, y * MINIMAP_TILE_SIZE, MINIMAP_TILE_SIZE, 0xFFFFFF, scale); //white for walls
			// else if (game->map.map[y][x] == '0' || game->map.map[y][x] == ' ')
			// 	draw_square(game, x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, 0x000000); //black for floor
			x++;
		}
		y++;
	}
	draw_player_minimap(game, scale);
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
