/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_try.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:02:16 by ndabbous          #+#    #+#             */
/*   Updated: 2025/07/01 15:06:41 by pde-vara         ###   ########.fr       */
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

int color_to_int(t_color color)
{
    return (color.r << 16) | (color.g << 8) | color.b;
}
