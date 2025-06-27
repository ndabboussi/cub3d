/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA_try.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 12:05:54 by pde-vara          #+#    #+#             */
/*   Updated: 2025/06/27 12:46:33 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cub3d.h"

// double	cast_ray(t_game *game, double ray_angle)
// {
// 	t_coordinates	pos = game->player.pos;
// 	double			ray_dir_x = cos(ray_angle);
// 	double			ray_dir_y = sin(ray_angle);
// 	int				map_x = (int)pos.x;
// 	int				map_y = (int)pos.y;

// 	double	delta_dist_x = fabs(1 / ray_dir_x);
// 	double	delta_dist_y = fabs(1 / ray_dir_y);
// 	double	side_dist_x, side_dist_y;
// 	int		step_x, step_y, side, hit = 0;

// 	step_x = (ray_dir_x < 0) ? -1 : 1;
// 	step_y = (ray_dir_y < 0) ? -1 : 1;
// 	side_dist_x = (ray_dir_x < 0) ? (pos.x - map_x) * delta_dist_x : (map_x + 1.0 - pos.x) * delta_dist_x;
// 	side_dist_y = (ray_dir_y < 0) ? (pos.y - map_y) * delta_dist_y : (map_y + 1.0 - pos.y) * delta_dist_y;

// 	while (!hit)
// 	{
// 		if (side_dist_x < side_dist_y)
// 		{
// 			side_dist_x += delta_dist_x;
// 			map_x += step_x;
// 			side = 0;
// 		}
// 		else
// 		{
// 			side_dist_y += delta_dist_y;
// 			map_y += step_y;
// 			side = 1;
// 		}
// 		if (game->map.map[map_y][map_x] == '1')
// 			hit = 1;
// 	}
// 	if (side == 0)
// 		return ((map_x - pos.x + (1 - step_x) / 2) / ray_dir_x);
// 	else
// 		return ((map_y - pos.y + (1 - step_y) / 2) / ray_dir_y);
// }


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
// 	double	ray_angle;
// 	double	distance;

// 	clear_image(&game->window);

// 	x = 0;
// 	while (x < WIN_WIDTH)
// 	{
// 		ray_angle = game->player.angle - (FOV * PI / 180.0 / 2.0)
// 			+ ((double)x / WIN_WIDTH) * (FOV * PI / 180.0);
// 		distance = cast_ray(game, ray_angle);
// 		distance *= cos(ray_angle - game->player.angle); // fisheye correction
// 		if (distance < 0.0001)
// 			distance = 0.0001;
// 		render_column(game, x, distance);
// 		x++;
// 	}
// 	mlx_put_image_to_window(game->window.mlx_ptr,
// 		game->window.mlx_window, game->window.img, 0, 0);
// 	return (0);
// }
