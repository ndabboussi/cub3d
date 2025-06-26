/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:26:47 by pde-vara          #+#    #+#             */
/*   Updated: 2025/06/25 14:54:32 by pde-vara         ###   ########.fr       */
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

int parse_color(char *str, t_color *color)
{
	if (sscanf(str, "%d,%d,%d", &color->r, &color->g, &color->b) != 3)
		return (1);
	if (color->r < 0 || color->r > 255 ||
		color->g < 0 || color->g > 255 ||
		color->b < 0 || color->b > 255)
		return (1);
	return (0);
}


static int	is_empty_line(const char *line)
{
	char *trimmed = ft_strtrim(line, " \t\n");
	if (!trimmed)
		return (1);
	if (ft_strlen(trimmed) == 0)
	{
		free(trimmed);
		return (1);
	}
	free(trimmed);
	return (0);
}

static int	assign_texture(char *line, t_path *cfg)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		cfg->no_texture = ft_strdup(trim_prefix(line, "NO"));
	else if (ft_strncmp(line, "SO ", 3) == 0)
		cfg->so_texture = ft_strdup(trim_prefix(line, "SO"));
	else if (ft_strncmp(line, "WE ", 3) == 0)
		cfg->we_texture = ft_strdup(trim_prefix(line, "WE"));
	else if (ft_strncmp(line, "EA ", 3) == 0)
		cfg->ea_texture = ft_strdup(trim_prefix(line, "EA"));
	else
		return (2); // Not a texture directive
	return (0);
}

static int	assign_color(char *line, t_path *cfg)
{
	if (ft_strncmp(line, "F ", 2) == 0)
	{
		if (parse_color(trim_prefix(line, "F"), &cfg->floor))
			return (1);
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
	{
		if (parse_color(trim_prefix(line, "C"), &cfg->ceiling))
			return (1);
	}
	else
		return (2); // Not a color line
	return (0);
}

int	parse_texture_color(char *line, t_path *cfg)
{
	if (is_empty_line(line))
		return (0);

	if (assign_texture(line, cfg) == 0)
		return (0);

	if (assign_color(line, cfg) == 0)
		return (0);

	return (2); // Not a texture or color line
}

int parse_textures_and_map_lines(char *filename, t_game *game, char **map_text)
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
			res_texture = parse_texture_color(line, &game->texture);
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
	if (parse_textures_and_map_lines(filename, game, &map_text) != 0)
		return (-1);

	game->map.map = ft_split(map_text, '\n');
	free(map_text);

	if (!game->map.map)
		return (printf("Error\nFailed to allocate map\n"), -1);
	return (0);
}
