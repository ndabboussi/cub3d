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
void	print_texture(t_texture *tex)
{
	printf("NO texture: %s\n", tex->no_texture);
	printf("SO texture: %s\n", tex->so_texture);
	printf("WE texture: %s\n", tex->we_texture);
	printf("EA texture: %s\n", tex->ea_texture);
	printf("Floor color:   R=%d G=%d B=%d\n", tex->floor.r, tex->floor.g, tex->floor.b);
	printf("Ceiling color: R=%d G=%d B=%d\n", tex->ceiling.r, tex->ceiling.g, tex->ceiling.b);
}
