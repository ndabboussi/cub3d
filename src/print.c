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
void	print_texture(t_path *tex)
{
	printf("NO texture: %s\n", tex->no_texture);
	printf("SO texture: %s\n", tex->so_texture);
	printf("WE texture: %s\n", tex->we_texture);
	printf("EA texture: %s\n", tex->ea_texture);
	printf("Floor color:   R=%d G=%d B=%d\n", tex->floor.r, tex->floor.g, tex->floor.b);
	printf("Ceiling color: R=%d G=%d B=%d\n", tex->ceiling.r, tex->ceiling.g, tex->ceiling.b);
}

void print_path(t_path *path)
{
	if (!path)
	{
		printf("t_path pointer is NULL.\n");
		return;
	}
	printf("==== DEBUG t_path ====\n");
	printf("North texture path: %s\n", path->no_texture);
	printf("South texture path: %s\n", path->so_texture);
	printf("West texture path:  %s\n", path->we_texture);
	printf("East texture path:  %s\n", path->ea_texture);

	printf("Floor color: R=%d, G=%d, B=%d\n", path->floor.r, path->floor.g, path->floor.b);
	printf("Ceiling color: R=%d, G=%d, B=%d\n", path->ceiling.r, path->ceiling.g, path->ceiling.b);
	printf("======================\n");
}

void print_coordinates(t_coordinates *coord, const char *label)
{
	if (!coord)
	{
		printf("%s: Coordinates pointer is NULL.\n", label);
		return;
	}
	// printf("%s -> x: %.2f, y: %.2f, angle: %.2f\n", label, coord->x, coord->y, coord->angle);
}
void print_player(t_player *player)
{
	if (!player)
	{
		printf("t_player pointer is NULL.\n");
		return;
	}
	printf("==== DEBUG t_player ====\n");
	print_coordinates(&player->pos, "Position");
	printf("========================\n");
}
