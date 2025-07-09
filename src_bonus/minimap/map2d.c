/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 12:13:22 by ndabbous          #+#    #+#             */
/*   Updated: 2025/07/08 16:03:24 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	draw_single_ray(t_game *game, int i, double start_x, double start_y)
{
	double			ray_angle;
	t_rays			distance;
	t_coordinates	start;
	t_coordinates	end;

	ray_angle = game->player.angle - (FOV * PI / 180.0 / 2.0)
		+ ((double)(i * 4) / WIN_WIDTH) * (FOV * PI / 180.0);
	distance = cast_ray(game, ray_angle);
	start.x = start_x;
	start.y = start_y;
	end.x = start_x + cos(ray_angle) * distance.distance
		* TILE_SIZE * game->minimap_scale;
	end.y = start_y + sin(ray_angle) * distance.distance
		* TILE_SIZE * game->minimap_scale;
	if (start_x >= 0 && start_x < MINIMAP_WIDTH \
		&& start_y >= 0 && start_y < MINIMAP_HEIGHT \
		&& end.x >= 0 && end.x < MINIMAP_WIDTH \
		&& end.y >= 0 && end.y < MINIMAP_HEIGHT)
		draw_line(game, start, end, 0x00FF00);
}

void	draw_rays(t_game *game)
{
	int		i;
	int		num_rays;
	double	start_x;
	double	start_y;

	start_x = game->player.pos.x * TILE_SIZE * game->minimap_scale;
	start_y = game->player.pos.y * TILE_SIZE * game->minimap_scale;
	num_rays = WIN_WIDTH / 4;
	i = 0;
	while (i < num_rays)
	{
		draw_single_ray(game, i, start_x, start_y);
		i++;
	}
}

void	draw_map2d(t_game *game)
{
	int		x;
	int		y;
	float	scale_x;
	float	scale_y;

	scale_x = (float)MINIMAP_WIDTH / (game->map.width * TILE_SIZE);
	scale_y = (float)MINIMAP_HEIGHT / (game->map.height * TILE_SIZE);
	if (scale_x < scale_y)
		game->minimap_scale = scale_x;
	else
		game->minimap_scale = scale_y;
	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == '1')
				draw_square_wall(game, x * TILE_SIZE * game->minimap_scale,
					y * TILE_SIZE * game->minimap_scale,
					TILE_SIZE * game->minimap_scale);
			x++;
		}
		y++;
	}
}

void	init_line_data(t_coordinates p0, t_coordinates p1,
		t_line_data *line, int *coords)
{
	coords[0] = (int)p0.x;
	coords[1] = (int)p0.y;
	coords[2] = (int)p1.x;
	coords[3] = (int)p1.y;
	line->dx = abs(coords[2] - coords[0]);
	line->dy = abs(coords[3] - coords[1]);
	if (coords[0] < coords[2])
		line->sx = 1;
	else
		line->sx = -1;
	if (coords[1] < coords[3])
		line->sy = 1;
	else
		line->sy = -1;
	line->err = line->dx - line->dy;
}

void	draw_line(t_game *game, t_coordinates p0, t_coordinates p1, int color)
{
	t_line_data	line;
	int			coords[4];

	init_line_data(p0, p1, &line, coords);
	while (1)
	{
		if (coords[0] >= 0 && coords[0] < WIN_WIDTH
			&& coords[1] >= 0 && coords[1] < WIN_HEIGHT)
			my_mlx_pixel_put(&game->window, coords[0], coords[1], color);
		if (coords[0] == coords[2] && coords[1] == coords[3])
			break ;
		line.e2 = 2 * line.err;
		if (line.e2 > -line.dy)
		{
			line.err -= line.dy;
			coords[0] += line.sx;
		}
		if (line.e2 < line.dx)
		{
			line.err += line.dx;
			coords[1] += line.sy;
		}
	}
}

// typedef struct s_line_data
// {
// 	int	dx; // Absolute distances between x and y coordinates
// 	int	dy;
// 	int	sx; // Step direction for x
// 	int	sy; // Step direction for y
// 	int	err; // Error accumulator
// 	int	e2;
// }	t_line_data;

// void	draw_line(t_game *game, t_point p0, t_point p1, int color)
// {
// 	t_line_data	line;

// 	int dx = abs(x1 - x0);
// 	int dy = abs(y1 - y0);
// 	int sx = x0 < x1 ? 1 : -1;
// 	int sy = y0 < y1 ? 1 : -1;
// 	int err = dx - dy;
// 	int e2;

// 	while (1)
// 	{
// 		// Only draw the pixel if it's within window bounds
// 		if (x0 >= 0 && x0 < WIN_WIDTH && y0 >= 0 && y0 < WIN_HEIGHT)
// 			my_mlx_pixel_put(&game->window, x0, y0, color);
// 		// Stop when the end point is reached
// 		if (x0 == x1 && y0 == y1)
// 			break ;

// 		e2 = 2 * err;
// 		// Move in x direction
// 		if (e2 > -dy)
// 		{
// 			err -= dy;
// 			x0 += sx;
// 		}
// 		// Move in y direction
// 		if (e2 < dx)
// 		{
// 			err += dx;
// 			y0 += sy;
// 		}
// 	}
// }

// static void	draw_single_ray(t_game *game,
// 		int i, double start_x, double start_y)
// {
// 	double	ray_angle;
// 	t_rays	distance;
// 	double	end_x;
// 	double	end_y;

// 	// Calculate ray angle (same logic as in render_frame)
// 	ray_angle = game->player.angle
// 		- (FOV * PI / 180.0 / 2.0)  // Start at leftmost FOV angle
// 		+ ((double)(i * 4) / WIN_WIDTH)
	// * (FOV * PI / 180.0); // Step toward right

// 	distance = cast_ray(game, ray_angle);// Cast the ray to get distance
// 	// Convert distance to 2D map coordinates
// 	end_x = start_x + cos(ray_angle) *
	// distance.distance * TILE_SIZE * game->minimap_scale;
// 	end_y = start_y + sin(ray_angle) * 
	// distance.distance * TILE_SIZE * game->minimap_scale;

// 	//draw_line(game, (int)start_x, (int)start_y,
		// (int)end_x, (int)end_y, 0x00FF00);// Draw the ray line
// 	if (start_x >= 0 && start_x < MINIMAP_WIDTH
// 		&& start_y >= 0 && start_y < MINIMAP_HEIGHT
// 		&& end_x >= 0 && end_x < MINIMAP_WIDTH
// 		&& end_y >= 0 && end_y < MINIMAP_HEIGHT)
// 		draw_line(game, (int)start_x, (int)start_y,
// 			(int)end_x, (int)end_y, 0x00FF00);
// }

// void draw_rays(t_game *game)
// {
// 	int		i;
// 	int		num_rays;
// 	double	start_x;
// 	double	start_y;

// 	// Starting point of all rays: player's pixel position
// 	start_x = game->player.pos.x * TILE_SIZE * game->minimap_scale;
// 	start_y = game->player.pos.y * TILE_SIZE * game->minimap_scale;
// 	num_rays = WIN_WIDTH / 4; // Draw every 4th ray to avoid clutter
// 	i = 0;
// 	while (i < num_rays)
// 	{
// 		draw_single_ray(game, i, start_x, start_y);
// 		i++;
// 	}
// }
