#include "cub3d.h"

void	ft_putchar(char c)
{
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

void	ft_putendl(char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		ft_putendl(map[i]);
		i++;
	}
}
