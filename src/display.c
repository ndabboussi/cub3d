/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:02:16 by ndabbous          #+#    #+#             */
/*   Updated: 2025/07/02 16:01:19 by pde-vara         ###   ########.fr       */
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


void draw_line(t_game *game, int x0, int y0, int x1, int y1, int color)
{
	int dx = abs(x1 - x0); // Absolute distances between x and y coordinates
	int dy = abs(y1 - y0);
	int sx = x0 < x1 ? 1 : -1; 
	int sy = y0 < y1 ? 1 : -1;
	int err = dx - dy;
	int e2;

	while (1)
	{
		// Check bounds before drawing
		if (x0 >= 0 && x0 < WIN_WIDTH && y0 >= 0 && y0 < WIN_HEIGHT)
			my_mlx_pixel_put(&game->window, x0, y0, color);
		
		if (x0 == x1 && y0 == y1)
			break;
		
		e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}


void draw_rays(t_game *game)
{
	int i;
		
	int num_rays = WIN_WIDTH / 4; // Draw every 4th ray to avoid clutter
	double ray_angle;
	double start_x = game->player.pos.x * TILE_SIZE;
	double start_y = game->player.pos.y * TILE_SIZE;
	t_rays distance;
		
	i = 0;
	while (i < num_rays)
	{
		// Calculate ray angle (same logic as in render_frame)
		ray_angle = game->player.angle - (FOV * PI / 180.0 / 2.0) 
			+ ((double)(i * 4) / WIN_WIDTH) * (FOV * PI / 180.0);
		
		// Cast the ray to get distance
		distance = cast_ray(game, ray_angle);
		
		// Convert distance to 2D map coordinates
		double end_x = start_x + cos(ray_angle) * distance.distance * TILE_SIZE;
		double end_y = start_y + sin(ray_angle) * distance.distance * TILE_SIZE;
		
		// Draw the ray line
		draw_line(game, (int)start_x, (int)start_y, (int)end_x, (int)end_y, 0x00FF00);
		i++;
	}
		
	// Draw player direction ray (main ray) in different color
	double main_end_x = start_x + cos(game->player.angle) * 100;
	double main_end_y = start_y + sin(game->player.angle) * 100;
	draw_line(game, (int)start_x, (int)start_y, (int)main_end_x, (int)main_end_y, 0xFF0000);
}


// void	draw_ray(t_game *game)
// {
// 	int		ray_length;
// 	double	end_x;
// 	double	end_y;

// 	ray_length = 50;
// 	end_x = game->player.pos.x * TILE_SIZE \
// 				+ cos(game->player.angle) * ray_length;
// 	end_y = game->player.pos.y * TILE_SIZE \
// 					+ sin(game->player.angle) * ray_length;
// 	// while ()
// 	// {
// 		my_mlx_pixel_put(&game->window, \
// 				(int)end_x, (int)end_y, 0x00FF00);
// 	// }
// }

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
			// else if (game->map.map[y][x] == '0' || game->map.map[y][x] == ' ')
			// 	draw_square(game, x * TILE_SIZE, y * TILE_SIZE, \
			// 		0x000000); //black for floor
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

int	print_map_2d(t_game *game)
{
	clear_image(&game->window);
	draw_map2d(game);
	draw_player(game);
	draw_rays(game);
	mlx_put_image_to_window(game->window.mlx_ptr, \
		game->window.mlx_window, game->window.img, 0, 0);
	return (0);
}
