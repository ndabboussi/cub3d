/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA_try.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 12:05:54 by pde-vara          #+#    #+#             */
/*   Updated: 2025/06/27 17:19:16 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Step 1: Ray start position and direction setup
void	init_ray_position_and_direction(t_game *game, t_dda *d, float ray_angle)
{
	d->ray_x = game->player.pos.x + 0.5;
	d->ray_y = game->player.pos.y + 0.5;
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

int	render_frame(t_game *game)
{
	int		x;
	double	ray_angle;
	double	distance;

	clear_image(&game->window);

	x = 0;
	while (x < WIN_WIDTH)
	{
		ray_angle = game->player.angle - (FOV * PI / 180.0 / 2.0)
			+ ((double)x / WIN_WIDTH) * (FOV * PI / 180.0);
		distance = cast_ray(game, ray_angle);
		distance *= cos(ray_angle - game->player.angle); // fisheye correction
		if (distance < 0.0001)
			distance = 0.0001;
		render_column(game, x, distance);
		x++;
	}
	mlx_put_image_to_window(game->window.mlx_ptr,
		game->window.mlx_window, game->window.img, 0, 0);
	return (0);
}


float	cast_ray(t_game *game, float ray_angle)
{
	t_dda	d;
	float	distance;

	init_ray_position_and_direction(game, &d, ray_angle);
	init_dda_steps_and_sidedist(&d);
	if (!perform_dda(game, &d))
		return (1e30);
	if (d.side == 0)
		distance = (d.map_x - d.ray_x + (1 - d.step_x) / 2.0f) / d.ray_dir_x;
	else
		distance = (d.map_y - d.ray_y + (1 - d.step_y) / 2.0f) / d.ray_dir_y;
	if (distance == 0)
		return (0.0001f);
}

float	cast_ray(t_game *game, float ray_angle)
{
	t_dda	d;			// Declare a structure to hold DDA variables.
	float	distance;	 // Variable to hold the computed distance to the wall.

	// Init DDA variables for this ray based on the player's position, the ray angle, and the map.
	init_ray_position_and_direction(game, &d, ray_angle);
	init_dda_steps_and_sidedist(&d);

	// Run the DDA loop to step through the grid until the ray rays a wall.
	// The function 'perform_dda' updates 'd' with the grid coordinates (d.map_x, d.map_y)
	// where the collision occurs, and it returns 1 if a wall was ray.
	if (!perform_dda(game, &d))
		return (1e30); // If no wall is ray, return a very large distance (infinite-ish).

	// Once a wall is ray, compute the perpendicular distance to the wall. 
	// This calculation adjusts for whether the ray was on a vertical side (side 0) or a horizontal side (side 1).
	if (d.side == 0)
		distance = (d.map_x - d.ray_x + (1 - d.step_x) / 2.0f) / d.ray_dir_x;
	else
		distance = (d.map_y - d.ray_y + (1 - d.step_y) / 2.0f) / d.ray_dir_y;

	// Prevent a zero distance (which might cause division-by-zero errors later).
	if (distance == 0)
		return (0.0001f);

	return (distance);
}

void	render_column(t_game *game, int x, float distance)
{
	int line_height = (int)(WIN_HEIGHT / distance);
	int wall_top = (WIN_HEIGHT / 2) - (line_height / 2);
	int wall_bottom = (WIN_HEIGHT / 2) + (line_height / 2);

	int ceiling_color = color_to_int(game->texture.ceiling);
	int floor_color = color_to_int(game->texture.floor);

	draw_vertical_line(&game->window, x, 0, wall_top, ceiling_color);	   // sky
	draw_vertical_line(&game->window, x, wall_top, wall_bottom, 0xFFFFFF);  // wall (keep wraye for now)
	draw_vertical_line(&game->window, x, wall_bottom, WIN_HEIGHT, floor_color);  // floor
}
