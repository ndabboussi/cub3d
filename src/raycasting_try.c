/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_try.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:02:16 by ndabbous          #+#    #+#             */
/*   Updated: 2025/07/01 12:22:47 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_vertical_line(t_window *win, int x, int start, int end, int color)
{
	int	y;

	y = start;
	while (y < end)
	{
		my_mlx_pixel_put(win, x, y, color);
		y++;
	}
}

int	is_wall(t_game *game, float x, float y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_y < 0 || map_y >= game->map.height || map_x < 0 \
				|| map_x >= (int)ft_strlen(game->map.map[map_y]))
		return (1);
	return (game->map.map[map_y][map_x] == '1');
}

int color_to_int(t_color color)
{
    return (color.r << 16) | (color.g << 8) | color.b;
}


// void render_column(t_game *game, int x, float distance)
// {
// 	int line_height = (int)(WIN_HEIGHT / distance);
// 	int wall_top = (WIN_HEIGHT / 2) - (line_height / 2);
// 	int wall_bottom = (WIN_HEIGHT / 2) + (line_height / 2);

// 	int ceiling_color = color_to_int(game->texture.ceiling);
// 	int floor_color = color_to_int(game->texture.floor);

// 	draw_vertical_line(&game->window, x, 0, wall_top, ceiling_color);	   // sky
// 	draw_vertical_line(&game->window, x, wall_top, wall_bottom, 0xFFFFFF);  // wall (keep white for now)
// 	draw_vertical_line(&game->window, x, wall_bottom, WIN_HEIGHT, floor_color);  // floor
// }

// int	render_frame(t_game *game)
// {
// 	int		x;
// 	float	ray_angle;
// 	float	distance;

// 	clear_image(&game->window);
// 	x = 0;
// 	while (x < WIN_WIDTH)
// 	{
// 		ray_angle = game->player.angle - (FOV * PI / 180.0 / 2.0) + \
// 					(x * (FOV * PI / 180.0) / WIN_WIDTH);
// 		distance = cast_ray(game, ray_angle);
// 		render_column(game, x, distance);
// 		x++;
// 	}
// 	mlx_put_image_to_window(game->window.mlx_ptr, game->window.mlx_window, game->window.img, 0, 0);
// 	return (0);
// }
