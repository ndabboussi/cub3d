/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 10:28:46 by ndabbous          #+#    #+#             */
/*   Updated: 2025/07/02 15:55:43 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_texture_pixel(t_texture *texture, int x, int y)
{
	int	offset;

	if (!texture || !texture->addr)
		return (0xFF00FF); // Retourne une couleur de debug (magenta)
	if (x < 0 || x >= TEXTURE_W || y < 0 || y >= TEXTURE_H)
		return (0xFF00FF);
	offset = (y * texture->line_length) + (x * (texture->bits_per_pixel / 8));
	return (*(unsigned int *)(texture->addr + offset));
}

// Step 1: Ray start position and direction setup
void	init_ray_position_and_direction(t_game *game, t_dda *d, float ray_angle)
{
	d->ray_x = game->player.pos.x;
	d->ray_y = game->player.pos.y;
	d->ray_dir_x = cos(ray_angle);
	d->ray_dir_y = sin(ray_angle);
	d->map_x = (int)d->ray_x;
	d->map_y = (int)d->ray_y;
	if (d->ray_dir_x == 0)//Si ray_angle = 0 → rayon vers la droite → (1, 0)
		d->delta_dist_x = 1e30; //big value to prevent division by 0 and a crash
	else
		d->delta_dist_x = fabs(1 / d->ray_dir_x);//La distance que le rayon doit parcourir pour franchir une case complète en x ou en y
	if (d->ray_dir_y == 0)
		d->delta_dist_y = 1e30;
	else
		d->delta_dist_y = fabs(1 / d->ray_dir_y);

}

// Step 2: DDA stepping and initial sidedist setup
// On détermine dans quel sens le rayon avance dans la grille 
//+ on calcule la distance jusqu’à la première intersection
void	init_dda_steps_and_sidedist(t_dda *d)
{
	if (d->ray_dir_x < 0)
	{
		d->step_x = -1;//go to the left
		d->side_dist_x = (d->ray_x - d->map_x) * d->delta_dist_x;
	}
	else
	{
		d->step_x = 1;//go to the right
		d->side_dist_x = (d->map_x + 1.0 - d->ray_x) * d->delta_dist_x;
	}
	if (d->ray_dir_y < 0)
	{
		d->step_y = -1;
		d->side_dist_y = (d->ray_y - d->map_y) * d->delta_dist_y;
	}
	else
	{
		d->step_y = 1;
		d->side_dist_y = (d->map_y + 1.0 - d->ray_y) * d->delta_dist_y;
	}
}

int	perform_dda(t_game *game, t_dda *d)
{
	while (1)
	{
		if (d->side_dist_x < d->side_dist_y)
		{
			d->side_dist_x += d->delta_dist_x;
			d->map_x += d->step_x;
			d->side = 0;//collision sur mur vertical
		}
		else
		{
			d->side_dist_y += d->delta_dist_y;
			d->map_y += d->step_y;
			d->side = 1;//collision sur mur horizontal
		}
		if (d->map_y < 0 || d->map_y >= game->map.height ||
			d->map_x < 0 || d->map_x >= (int)ft_strlen(game->map.map[d->map_y]))
			return (0);
		if (game->map.map[d->map_y][d->map_x] == '1')
			return (1);
	}
}

/* Goal : to calculate the distance with the wall, determine which texture to use and which texture column to render*/
t_rays	cast_ray(t_game *game, float ray_angle)
{
	t_dda		d;
	t_rays		ray;
	double		wall_x;

	init_ray_position_and_direction(game, &d, ray_angle);
	init_dda_steps_and_sidedist(&d);
	if (!perform_dda(game, &d))
	{
		ray.distance = 1e30;
		ray.texture = NULL;
		ray.texture_x = 0;
		ray.side = 0;
		return (ray);
	}
	if (d.side == 0)
		ray.distance = (d.map_x - d.ray_x \
			+ (1 - d.step_x) / 2.0f) / d.ray_dir_x;
	else
		ray.distance = (d.map_y - d.ray_y \
			+ (1 - d.step_y) / 2.0f) / d.ray_dir_y;
	if (ray.distance == 0)//si on est hyper pret, on evite de mettre une distance a 0 pour pas diviser par 0
		ray.distance = 0.01f;
	if (d.side == 0 && d.ray_dir_x > 0)//east wall
		ray.texture = &game->ea_texture;
	else if (d.side == 0)
		ray.texture = &game->we_texture;//west wall
	else if (d.side == 1 && d.ray_dir_y > 0)
		ray.texture = &game->so_texture;//south wall
	else
		ray.texture = &game->no_texture;//north wall
	// if (ray.texture == NULL)
	// 	ray.texture = &game->no_texture;
	if (d.side == 0)//calcule de l'intersection exacte sur le mur, on utilise y si vertical
		wall_x = d.ray_y + ray.distance * d.ray_dir_y;
	else
		wall_x = d.ray_x + ray.distance * d.ray_dir_x;
	if (wall_x < 0)
		wall_x += 1.0;
	wall_x -= (int)wall_x;
	ray.texture_x = (int)(wall_x * (double)TEXTURE_W);
	if (d.side == 0 && d.ray_dir_x > 0)//correction de l'inversion de la texture
		ray.texture_x = TEXTURE_W - ray.texture_x - 1;
	if (d.side == 1 && d.ray_dir_y < 0)
		ray.texture_x = TEXTURE_W - ray.texture_x - 1;
	ray.side = d.side;//sauvegarde de si on a touche un mur evrtical ou horizontal
	return (ray);
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
	draw_vertical_line(&game->window, x, 0, \
		wall_top, color_to_int(game->path.ceiling));
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
		ray.distance *= cos(ray_angle - game->player.angle); // fisheye correction
		if (ray.distance < 0.0001)
			ray.distance = 0.0001;
		render_column(game, x, ray);
		x++;
	}
	//draw_minimap(game);
	draw_map2d(game);
	draw_player(game);
	draw_rays(game);
	mlx_put_image_to_window(game->window.mlx_ptr,
		game->window.mlx_window, game->window.img, 0, 0);
	return (0);
}
