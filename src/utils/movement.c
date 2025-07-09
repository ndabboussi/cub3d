/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:43:19 by pde-vara          #+#    #+#             */
/*   Updated: 2025/07/02 19:01:34 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_walkable(t_game *g, float x, float y)
{
	if (g->map.map[(int)y][(int)x] == '1')
		return (0);
	return (1);
}

void	move_forward(t_game *g)
{
	float	new_x;
	float	new_y;

	new_x = g->player.pos.x + cos(g->player.angle) * MOVE_SPEED;
	new_y = g->player.pos.y + sin(g->player.angle) * MOVE_SPEED;
	if (is_walkable(g, new_x, g->player.pos.y))
		g->player.pos.x = new_x;
	if (is_walkable(g, g->player.pos.x, new_y))
		g->player.pos.y = new_y;
}

void	move_backward(t_game *g)
{
	float	new_x;
	float	new_y;

	new_x = g->player.pos.x - cos(g->player.angle) * MOVE_SPEED;
	new_y = g->player.pos.y - sin(g->player.angle) * MOVE_SPEED;
	if (is_walkable(g, new_x, g->player.pos.y))
		g->player.pos.x = new_x;
	if (is_walkable(g, g->player.pos.x, new_y))
		g->player.pos.y = new_y;
}

void	move_left(t_game *g)
{
	float	new_x;
	float	new_y;

	new_x = g->player.pos.x + sin(g->player.angle) * MOVE_SPEED;
	new_y = g->player.pos.y - cos(g->player.angle) * MOVE_SPEED;
	if (is_walkable(g, new_x, g->player.pos.y))
		g->player.pos.x = new_x;
	if (is_walkable(g, g->player.pos.x, new_y))
		g->player.pos.y = new_y;
}

void	move_right(t_game *g)
{
	float	new_x;
	float	new_y;

	new_x = g->player.pos.x - sin(g->player.angle) * MOVE_SPEED;
	new_y = g->player.pos.y + cos(g->player.angle) * MOVE_SPEED;
	if (is_walkable(g, new_x, g->player.pos.y))
		g->player.pos.x = new_x;
	if (is_walkable(g, g->player.pos.x, new_y))
		g->player.pos.y = new_y;
}
