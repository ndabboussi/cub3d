/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:26:47 by pde-vara          #+#    #+#             */
/*   Updated: 2025/07/08 16:08:49 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_putchar(char c)
{
	if (c == 'V')
		ft_putstr_fd(RED "V" RESET, 2);
	else
		write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		i++;
	}
	printf("\n");
}
// void	print_texture(t_path *tex)
// {
// 	printf("NO texture: %s\n", tex->no_texture);
// 	printf("SO texture: %s\n", tex->so_texture);
// 	printf("WE texture: %s\n", tex->we_texture);
// 	printf("EA texture: %s\n", tex->ea_texture);
// 	printf("Floor color:   R=%d G=%d B=%d\n", 
// tex->floor.r, tex->floor.g, tex->floor.b);
// 	printf("Ceiling color: R=%d G=%d B=%d\n", 
// tex->ceiling.r, tex->ceiling.g, tex->ceiling.b);
// }

// void print_path(t_path *path)
// {
// 	if (!path)
// 	{
// 		printf("t_path pointer is NULL.\n");
// 		return;
// 	}
// 	printf("==== DEBUG t_path ====\n");
// 	printf("North texture path: %s\n", path->no_texture);
// 	printf("South texture path: %s\n", path->so_texture);
// 	printf("West texture path:  %s\n", path->we_texture);
// 	printf("East texture path:  %s\n", path->ea_texture);

// 	printf("Floor color: R=%d, G=%d, B=%d\n", 
// path->floor.r, path->floor.g, path->floor.b);
// 	printf("Ceiling color: R=%d, G=%d, B=%d\n", 
// path->ceiling.r, path->ceiling.g, path->ceiling.b);
// 	printf("======================\n");
// }

// void print_coordinates(t_coordinates *coord, const char *label)
// {
// 	if (!coord)
// 	{
// 		printf("%s: Coordinates pointer is NULL.\n", label);
// 		return;
// 	}
// 	// printf("%s -> x: %.2f, y: %.2f, angle: %.2f\n", 
// 	label, coord->x, coord->y, coord->angle);
// }
// void print_player(t_player *player)
// {
// 	if (!player)
// 	{
// 		printf("t_player pointer is NULL.\n");
// 		return;
// 	}
// 	printf("==== DEBUG t_player ====\n");
// 	print_coordinates(&player->pos, "Position");
// 	printf("========================\n");
// }

// typedef struct s_dda
// {
// 	int		map_x; //position actuelle du rayon dans la grille (map)
// 	int		map_y;
// 	float	ray_x; //direction du rayon
// 	float	ray_y;
// 	float	ray_dir_x; //distance nécessaire pour parcourir une case entière en x
// 	float	ray_dir_y;
// 	float	delta_dist_x;
// 	float	delta_dist_y;
// 	float	side_dist_x; //distance actuelle entre le rayon et le premier mur potentiel en x
// 	float	side_dist_y;
// 	int		step_x; //direction dans laquelle on avance (gauche -1 ou droite +1)
// 	int		step_y;
// 	int		side; //0 si collision sur un mur vertical, 1 si sur un mur horizontal (utile pour la texture plus tard)
// }	t_dda;