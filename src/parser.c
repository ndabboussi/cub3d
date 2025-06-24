/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:26:47 by pde-vara          #+#    #+#             */
/*   Updated: 2025/06/24 15:06:15 by pde-vara         ###   ########.fr       */
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


int parse_texture(char *line, t_texture *cfg)
{
	line = ft_strtrim(line, " \t\n");

	if (ft_strncmp(line, "NO ", 3) == 0)
		cfg->no_texture = ft_strdup(trim_prefix(line, "NO"));
	else if (ft_strncmp(line, "SO ", 3) == 0)
		cfg->so_texture = ft_strdup(trim_prefix(line, "SO"));
	else if (ft_strncmp(line, "WE ", 3) == 0)
		cfg->we_texture = ft_strdup(trim_prefix(line, "WE"));
	else if (ft_strncmp(line, "EA ", 3) == 0)
		cfg->ea_texture = ft_strdup(trim_prefix(line, "EA"));
	else if (ft_strncmp(line, "F ", 2) == 0)
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
		return (2); // Not a texture line (likely map)
	return (0);
}


int parse_file(char *filename, t_game *game)
{
	int		fd;
	char	*line;
	char	*map_text;
	char	*tmp;
	int		is_map_started = 0;
	int		res_texture;

	map_text = ft_strdup("");
	if (!map_text)
        return (perror("Memory allocation failed"), -1);
	
	if (!game)
		return (perror("Game struct is NULL"), -1);
		
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (free(map_text), perror("Failed to open .cub"), -1);

	while ((line = get_next_line(fd)))
	{
		if (!is_map_started)
		{
			res_texture = parse_texture(line, &game->texture);
			if (res_texture == 1)
				return (printf("Error\nInvalid config line: %s\n", line), 1);
			else if (res_texture == 2)
				is_map_started = 1; // Line is not a config, must be map
		}
		if (is_map_started)
		{
			tmp = map_text;
			map_text = ft_strjoin(map_text, line); // Accumulate map
			free(tmp);
		}
		free(line);
	}
	close(fd);

	game->map.map = ft_split(map_text, '\n');
	free(map_text);

	if (!game->map.map)
		return (printf("Error\nFailed to allocate map\n"), 1);

	return (0);
}

int parse_textures_and_map_lines(char *filename, t_game *game, char **map_text_out)
{
	int		fd;
	char	*line;
	char	*tmp;
	int		is_map_started = 0;
	int		res_texture;

	*map_text_out = ft_strdup("");
	if (!*map_text_out)
		return (perror("Memory allocation failed"), -1);

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (free(*map_text_out), perror("Failed to open .cub"), -1);

	while ((line = get_next_line(fd)))
	{
		if (!is_map_started)
		{
			res_texture = parse_texture(line, &game->texture);
			if (res_texture == 1)
				return (printf("Error\nInvalid config line: %s\n", line), free(line), close(fd), free(*map_text_out), 1);
			else if (res_texture == 2)
				is_map_started = 1;
		}
		if (is_map_started)
		{
			tmp = *map_text_out;
			*map_text_out = ft_strjoin(*map_text_out, line);
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

	if (!game)
		return (perror("Game struct is NULL"), -1);

	if (parse_textures_and_map_lines(filename, game, &map_text) != 0)
		return (1);

	game->map.map = ft_split(map_text, '\n');
	free(map_text);

	if (!game->map.map)
		return (printf("Error\nFailed to allocate map\n"), 1);

	free(map_text);
	return (0);
}
