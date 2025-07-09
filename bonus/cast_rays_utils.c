/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndabbous <ndabbous@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-07 13:01:46 by ndabbous          #+#    #+#             */
/*   Updated: 2025-07-07 13:01:46 by ndabbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray_position_and_direction(t_game *game, t_dda *d, float ray_angle)
{
	d->ray_x = game->player.pos.x;
	d->ray_y = game->player.pos.y;
	d->ray_dir_x = cos(ray_angle);
	d->ray_dir_y = sin(ray_angle);
	d->map_x = (int)d->ray_x;
	d->map_y = (int)d->ray_y;
	if (d->ray_dir_x == 0)
		d->delta_dist_x = 1e30;
	else
		d->delta_dist_x = fabs(1 / d->ray_dir_x);
	if (d->ray_dir_y == 0)
		d->delta_dist_y = 1e30;
	else
		d->delta_dist_y = fabs(1 / d->ray_dir_y);
}

void	init_dda_steps_and_sidedist(t_dda *d)
{
	if (d->ray_dir_x < 0)
	{
		d->step_x = -1;
		d->side_dist_x = (d->ray_x - d->map_x) * d->delta_dist_x;
	}
	else
	{
		d->step_x = 1;
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
			d->side = 0;
		}
		else
		{
			d->side_dist_y += d->delta_dist_y;
			d->map_y += d->step_y;
			d->side = 1;
		}
		if (d->map_y < 0 || d->map_y >= game->map.height \
			|| d->map_x < 0 \
			|| d->map_x >= (int)ft_strlen(game->map.map[d->map_y]))
			return (0);
		if (game->map.map[d->map_y][d->map_x] == '1')
			return (1);
	}
}
