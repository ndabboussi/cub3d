/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndabbous <ndabbous@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-07 12:19:10 by ndabbous          #+#    #+#             */
/*   Updated: 2025-07-07 12:19:10 by ndabbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ceiling(t_game *game, int x, int wall_top)
{
	int	range[2];

	range[0] = 0;
	range[1] = wall_top;
	draw_vertical_line(&game->window, x, range, \
		color_to_int(game->path.ceiling));
}

void	draw_floor(t_game *game, int x, int wall_bottom)
{
	int	range[2];

	range[0] = wall_bottom;
	range[1] = WIN_HEIGHT;
	draw_vertical_line(&game->window, x, range, color_to_int(game->path.floor));
}

void	draw_wall(t_game *game, int x, int *range, t_rays ray)
{
	double	step;
	double	texture_pos;
	int		y;
	int		texture_y;
	int		color;

	step = 1.0 * TEXTURE_H / (WIN_HEIGHT / ray.distance);
	texture_pos = (range[1] - WIN_HEIGHT / 2 \
					+ (WIN_HEIGHT / ray.distance) / 2) * step;
	y = range[1];
	while (y < range[0])
	{
		texture_y = (int)texture_pos & (TEXTURE_H - 1);
		texture_pos += step;
		color = get_texture_pixel(ray.texture, ray.texture_x, texture_y);
		my_mlx_pixel_put(&game->window, x, y, color);
		y++;
	}
}

void	render_column(t_game *game, int x, t_rays ray)
{
	int	line_height;
	int	wall_top;
	int	wall_bottom;
	int	range[2];

	if (ray.distance < 0.0001)
		ray.distance = 0.0001;
	line_height = (int)(WIN_HEIGHT / ray.distance);
	wall_top = (WIN_HEIGHT / 2) - (line_height / 2);
	wall_bottom = (WIN_HEIGHT / 2) + (line_height / 2);
	if (wall_top < 0)
		wall_top = 0;
	if (wall_bottom >= WIN_HEIGHT)
		wall_bottom = WIN_HEIGHT - 1;
	draw_ceiling(game, x, wall_top);
	range[0] = wall_bottom;
	range[1] = wall_top;
	draw_wall(game, x, range, ray);
	draw_floor(game, x, wall_bottom);
}

int	render_frame(t_game *game)
{
	int			x;
	double		ray_angle;
	t_rays		ray;

	x = 0;
	clear_image(&game->window);
	handle_movement(game);
	while (x < WIN_WIDTH)
	{
		ray_angle = game->player.angle - (FOV * PI / 180.0 / 2.0) \
			+ ((double)x / WIN_WIDTH) * (FOV * PI / 180.0);
		ray = cast_ray(game, ray_angle);
		ray.distance *= cos(ray_angle - game->player.angle);
		if (ray.distance < 0.0001)
			ray.distance = 0.0001;
		render_column(game, x, ray);
		x++;
	}
	mlx_put_image_to_window(game->window.mlx_ptr,
		game->window.mlx_window, game->window.img, 0, 0);
	return (0);
}
