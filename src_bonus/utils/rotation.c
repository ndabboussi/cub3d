/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndabbous <ndabbous@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-08 13:45:38 by ndabbous          #+#    #+#             */
/*   Updated: 2025-07-08 13:45:38 by ndabbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	rotate_left(t_game *g)
{
	g->player.angle -= ROT_SPEED;
	if (g->player.angle < 0)
		g->player.angle += 2 * PI;
}

void	rotate_right(t_game *g)
{
	g->player.angle += ROT_SPEED;
	if (g->player.angle > 2 * PI)
		g->player.angle -= 2 * PI;
}

void	rotate_left_mouse(t_game *g)
{
	g->player.angle -= ROT_SPEED / 10;
	if (g->player.angle < 0)
		g->player.angle += 2 * PI;
}

void	rotate_right_mouse(t_game *g)
{
	g->player.angle += ROT_SPEED / 10;
	if (g->player.angle > 2 * PI)
		g->player.angle -= 2 * PI;
}
