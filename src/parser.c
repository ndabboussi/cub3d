/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:26:47 by pde-vara          #+#    #+#             */
/*   Updated: 2025/06/27 16:49:13 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char *trim_prefix(char *line, char *prefix)
{
	line += ft_strlen(prefix);
	while (*line == ' ' || *line == '\t')
		line++;
	return (line);
}

static int	is_empty_line(const char *line)
{
	char *trimmed = ft_strtrim(line, " \t\n");
	if (!trimmed)
		return (-1);
	if (ft_strlen(trimmed) == 0)
	{
		free(trimmed);
		return (1);
	}
	free(trimmed);
	return (0);
}

int	parse_color(char *str, t_color *color)
{
	int		i;
	char	**components;

	i = 0;
	components = ft_split(str, ',');
	if (!components)
		return (-1);
	while (components[i])
		i++;
	if (i != 3)
		return (free_map(components), 1);
	color->r = ft_atoi(components[0]);
	color->g = ft_atoi(components[1]);
	color->b = ft_atoi(components[2]);
	free_map(components);
	if (color->r < 0 || color->r > 255 ||
		color->g < 0 || color->g > 255 ||
		color->b < 0 || color->b > 255)
		return (-1);
	return (0);
}

int	parse_till_map(char *line, t_path *config)
{
	char	*trimmed;

	if (is_empty_line(line))
		return (0);

	if (ft_strncmp(line, "NO", 2) == 0)
		config->no_texture = ft_strdup(trim_prefix(line, "NO"));
	else if (ft_strncmp(line, "SO", 2) == 0)
		config->so_texture = ft_strdup(trim_prefix(line, "SO"));
	else if (ft_strncmp(line, "WE", 2) == 0)
		config->we_texture = ft_strdup(trim_prefix(line, "WE"));
	else if (ft_strncmp(line, "EA", 2) == 0)
		config->ea_texture = ft_strdup(trim_prefix(line, "EA"));
	else if (ft_strncmp(line, "F", 1) == 0)
	{
		trimmed = trim_prefix(line, "F");
		if (parse_color(trimmed, &config->floor))
			return (-1);
	}
	else if (ft_strncmp(line, "C", 1) == 0)
	{
		trimmed = trim_prefix(line, "C");
		if (parse_color(trimmed, &config->ceiling))
			return (-1);
	}
	else
		return (2); // Not a recognized texture or color line
	return (0);
}


int parse_line_by_line(char *filename, t_game *game, char **map_text)
{
	int		fd;
	char	*line;
	char	*tmp;
	int		is_map_started = 0;
	int		res_texture;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (free(*map_text), perror("Failed to open .cub"), -1);

	while ((line = get_next_line(fd)))
	{
		if (!is_map_started)
		{
			res_texture = parse_till_map(line, &game->texture);
			if (res_texture == 1)
				return (printf("Error\nInvalid config line: %s\n", line), free(line), close(fd), free(*map_text), -1);
			else if (res_texture == 2)
				is_map_started = 1;
		}
		if (is_map_started)
		{
			tmp = *map_text;
			*map_text = ft_strjoin(*map_text, line);
			free(tmp);
		}
		free(line);
	}
	close(fd);
	return (0);
}


int parse_file(char *filename, t_game *game)
{
	char *map_text;

	map_text = ft_calloc(1, sizeof(char));
	if (!map_text)
		return (perror("Memory allocation failed"), -1);
	if (parse_line_by_line(filename, game, &map_text) != 0)
		return (-1);

	game->map.map = ft_split(map_text, '\n');
	free(map_text);

	if (!game->map.map)
		return (printf("Error\nFailed to allocate map\n"), -1);
	return (0);
}
