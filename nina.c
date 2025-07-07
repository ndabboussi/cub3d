
#include "cub3d.h"

int	get_texture_pixel(t_texture *texture, int x, int y)
{
	int	offset;

	if (!texture || !texture->addr)
		return (0xFF00FF);
	if (x < 0 || x >= TEXTURE_W || y < 0 || y >= TEXTURE_H)
		return (0xFF00FF);
	offset = (y * texture->line_length) + (x * (texture->bits_per_pixel / 8));
	return (*(unsigned int *)(texture->addr + offset));
}

int	perform_dda(t_game *game, t_dda *d)
{
	while (1)
	{
		if (d->side_dist_x < d->side_dist_y)
		{
			d->side_dist_x += d->delta_dist_x;
			d->map_x += d->step_x;
			d->side = 0;
		}
		else
		{
			d->side_dist_y += d->delta_dist_y;
			d->map_y += d->step_y;
			d->side = 1;
		}
		if (d->map_y < 0 || d->map_y >= game->map.height ||
			d->map_x < 0 || d->map_x >= (int)ft_strlen(game->map.map[d->map_y]))
			return (0);
		if (game->map.map[d->map_y][d->map_x] == '1')
			return (1);
	}
}

void	render_column(t_game *game, int x, t_rays ray)
{
	int		line_height;
	int		wall_top;
	int		wall_bottom;
	double	step;
	double	texture_pos;
	int		y;
	int		texture_y;
	int		color;

	line_height = (int)(WIN_HEIGHT / ray.distance);
	wall_top = (WIN_HEIGHT / 2) - (line_height / 2);
	wall_bottom = (WIN_HEIGHT / 2) + (line_height / 2);
	if (wall_top < 0)
		wall_top = 0;
	if (wall_bottom >= WIN_HEIGHT)
		wall_bottom = WIN_HEIGHT - 1;
	draw_vertical_line(&game->window, x, 0, wall_top, color_to_int(game->path.ceiling));
	step = 1.0 * TEXTURE_H / line_height;
	texture_pos = (wall_top - WIN_HEIGHT / 2 + line_height / 2) * step;
	y = wall_top;
	while (y < wall_bottom)
	{
		texture_y = (int)texture_pos & (TEXTURE_H - 1);
		texture_pos += step;
		color = get_texture_pixel(ray.texture, ray.texture_x, texture_y);
		my_mlx_pixel_put(&game->window, x, y, color);
		y++;
	}
	draw_vertical_line(&game->window, x, wall_bottom, WIN_HEIGHT, color_to_int(game->path.floor));
}

int	render_frame(t_game *game)
{
	int			x;
	double		ray_angle;
	t_rays		ray;

	x = 0;
	clear_image(&game->window);
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
	draw_map2d(game);
	draw_player(game);
	draw_rays(game);
	mlx_put_image_to_window(game->window.mlx_ptr,
		game->window.mlx_window, game->window.img, 0, 0);
	return (0);
}


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

