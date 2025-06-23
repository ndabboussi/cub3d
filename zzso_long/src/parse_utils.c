/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:08:22 by pde-vara          #+#    #+#             */
/*   Updated: 2025/01/28 19:13:20 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*lecture_map(char *filename)
{
	int		fd;
	char	*line;
	char	*content;
	char	*temp;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (perror("Erreur: fichier non trouvé ou illisible\n"), NULL);
	content = ft_strdup("");
	if (!content)
		return (perror("Err: alloc failed\n"), close(fd), NULL);
	line = get_next_line(fd);
	while (line != NULL)
	{
		temp = content;
		content = ft_strjoin(content, line);
		if (!content)
			return (perror("Err: alloc failed\n"), close(fd), NULL);
		free(line);
		free(temp);
		line = NULL;
		line = get_next_line(fd);
	}
	close(fd);
	return (content);
}

int	wall_check(char **map)
{
	int	x;
	int	y;

	if (!map || !map[0])
		return (-1);
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] && map[y][x] != '\n')
		{
			if ((y == 0 || !map[y + 1] || x == 0 || !map[y][x + 1])
				&& map[y][x] != '1')
				return (-1);
			if (map[y][x] != 'C' && map[y][x] != 'E' && map[y][x] != 'P'
				&& map[y][x] != '1' && map[y][x] != '0')
			{
				return (perror("ya du nimporte quoi dans la map"), -1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	is_rectangle(char **map)
{
	int	i;
	int	first_len;
	int	current_len;

	if (!map || !map[0])
		return (0);
	first_len = ft_strlen(map[0]);
	if (map[0][first_len - 1] == '\n')
		first_len--;
	i = 1;
	while (map[i])
	{
		current_len = ft_strlen(map[i]);
		if (map[i][current_len - 1] == '\n')
			current_len--;
		if (current_len != first_len)
			return (0);
		i++;
	}
	return (1);
}

void	free_map(char **map)
{
	int	j;

	j = 0;
	if (!map)
		return ;
	while (map[j])
	{
		free(map[j]);
		j++;
	}
	free(map);
	map = NULL;
}

char	**ft_map(char *filename)
{
	char	**map;
	char	*content;

	content = lecture_map(filename);
	if (!content)
		return (NULL);
	map = NULL;
	map = ft_split(content, '\n');
	free(content);
	if (!map)
		return (perror("Err: map alloc failed\n"), NULL);
	if (wall_check(map) == -1)
	{
		perror("Erreur: la map n'est pas entourée de murs\n");
		free_map(map);
		return (NULL);
	}
	if (!is_rectangle(map))
	{
		perror("Erreur: la map n'est pas rectangulaire\n");
		free_map(map);
		return (NULL);
	}
	return (map);
}
