/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndabbous <ndabbous@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-07 12:57:53 by ndabbous          #+#    #+#             */
/*   Updated: 2025-07-07 12:57:53 by ndabbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	draw_vertical_line(t_window *win, int x, int range[2], int color)
{
	int	y;

	y = range[0];
	while (y < range[1])
	{
		my_mlx_pixel_put(win, x, y, color);
		y++;
	}
}

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
