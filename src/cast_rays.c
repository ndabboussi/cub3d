/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndabbous <ndabbous@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-07 12:30:06 by ndabbous          #+#    #+#             */
/*   Updated: 2025-07-07 12:30:06 by ndabbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	calculate_distance(t_dda *d)
{
	if (d->side == 0)
		return ((d->map_x - d->ray_x + (1 - d->step_x) / 2.0f) / d->ray_dir_x);
	else
		return ((d->map_y - d->ray_y + (1 - d->step_y) / 2.0f) / d->ray_dir_y);
}

t_texture	*select_texture(t_game *game, t_dda *d)
{
	if (d->side == 0 && d->ray_dir_x > 0)
		return (&game->ea_texture);
	else if (d->side == 0)
		return (&game->we_texture);
	else if (d->side == 1 && d->ray_dir_y > 0)
		return (&game->so_texture);
	else
		return (&game->no_texture);
}

int	calculate_texture_x(t_dda *d, double distance)
{
	double	wall_x;
	int		texture_x;

	if (d->side == 0)
		wall_x = d->ray_y + distance * d->ray_dir_y;
	else
		wall_x = d->ray_x + distance * d->ray_dir_x;
	if (wall_x < 0)
		wall_x += 1.0;
	wall_x -= (int)wall_x;
	texture_x = (int)(wall_x * (double)TEXTURE_W);
	if (d->side == 0 && d->ray_dir_x > 0)
		texture_x = TEXTURE_W - texture_x - 1;
	if (d->side == 1 && d->ray_dir_y < 0)
		texture_x = TEXTURE_W - texture_x - 1;
	return (texture_x);
}

t_rays	cast_ray(t_game *game, float ray_angle)
{
	t_dda	d;
	t_rays	ray;

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
	ray.distance = calculate_distance(&d);
	if (ray.distance == 0)
		ray.distance = 0.01f;
	ray.texture = select_texture(game, &d);
	if (ray.texture == NULL)
		ray.texture = &game->no_texture;
	ray.texture_x = calculate_texture_x(&d, ray.distance);
	ray.side = d.side;
	return (ray);
}
