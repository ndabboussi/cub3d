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

// void	my_mlx_pixel_put(t_window *img, int x, int y, int color)
// {
// 	char	*dst;

// 	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
// 		return ;
// 	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

// void	draw_vertical_line(t_window *win, int x, int start, int end, int color)
// {
// 	int	y;

// 	y = start;
// 	while (y < end)
// 	{
// 		my_mlx_pixel_put(win, x, y, color);
// 		y++;
// 	}
// }

// int	is_wall(t_game *game, float x, float y)
// {
// 	int	map_x;
// 	int	map_y;

// 	map_x = (int)x;
// 	map_y = (int)y;
// 	if (map_y < 0 || map_y >= game->map.height || map_x < 0 \
// 				|| map_x >= (int)ft_strlen(game->map.map[map_y]))
// 		return (1);
// 	return (game->map.map[map_y][map_x] == '1');
// }

// void	clear_image(t_window *win)
// {
// 	int		x;
// 	int		y;

// 	y = 0;
// 	while (y < WIN_HEIGHT)
// 	{
// 		x = 0;
// 		while (x < WIN_WIDTH)
// 		{
// 			my_mlx_pixel_put(win, x, y, 0x000000);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// int	render_frame(t_game *game)
// {
// 	int		x;
// 	float	ray_angle, ray_x, ray_y, step, distance;
// 	int		line_height, wall_top, wall_bottom;

// 	x = 0;
// 	clear_image(&game->window);
// 	while (x < WIN_WIDTH)
// 	{
// 		ray_angle = (game->map.player_dir * PI / 180.0) - \
// 			(FOV * PI / 180.0 / 2.0) + (x * (FOV * PI / 180.0) / WIN_WIDTH);
// 		ray_x = game->map.player_x + 0.5;
// 		ray_y = game->map.player_y + 0.5;
// 		step = 0.01;
// 		distance = 0;
// 		while (!is_wall(game, ray_x, ray_y))
// 		{
// 			ray_x += cos(ray_angle) * step;
// 			ray_y += sin(ray_angle) * step;
// 			distance += step;
// 		}
// 		if (distance == 0)
// 			distance = 0.0001;
// 		line_height = (int)(WIN_HEIGHT / distance);
// 		wall_top = (WIN_HEIGHT / 2) - (line_height / 2);
// 		wall_bottom = (WIN_HEIGHT / 2) + (line_height / 2);
// 		draw_vertical_line(&game->window, x, 0, wall_top, 0xFF9B55); // sky
// 		draw_vertical_line(&game->window, x, wall_top, wall_bottom, 0xFFFFFF); // wall
// 		draw_vertical_line(&game->window, x, wall_bottom, WIN_HEIGHT, 0xD50062); // floor
// 		x++;
// 	}
// 	mlx_put_image_to_window(game->window.mlx_ptr, game->window.mlx_window, game->window.img, 0, 0);
// 	return (0);
// }
