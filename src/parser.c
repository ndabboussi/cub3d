/* ************************************************************************** */
/*		                                                                    */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:26:47 by pde-vara          #+#    #+#             */
/*   Updated: 2025/07/02 11:54:36 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*trim_prefix(char *line, char *prefix)
{
	line += ft_strlen(prefix);
	while (*line == ' ' || *line == '\t')
		line++;
	return (line);
}

static int	is_empty_line(const char *line)
{
	char	*trimmed;
	int		result;

	trimmed = ft_strtrim(line, " \t\n");
	if (!trimmed)
		return (-1);
	result = (ft_strlen(trimmed) == 0);
	free(trimmed);
	return (result);
}

int	parse_color(char *str, t_color *color)
{
	int		i;
	char	**components;

	components = ft_split(str, ',');
	if (!components)
		return (-1);
	i = 0;
	while (components[i])
		i++;
	if (i != 3)
		return (free_double_tab(components), 1);
	color->r = ft_atoi(components[0]);
	color->g = ft_atoi(components[1]);
	color->b = ft_atoi(components[2]);
	free_double_tab(components);
	if (color->r < 0 || color->r > 255 ||\
		color->g < 0 || color->g > 255 ||\
		color->b < 0 || color->b > 255)
		return (-1);
	return (0);
}

int	assign_texture(char *line, char *prefix, char **dest)
{
	char	*trimmed;
	char	*stripped;

	if (ft_strncmp(line, prefix, ft_strlen(prefix)) != 0)
		return (0);
	if (*dest != NULL)
		return (-1); // Already assigned
	trimmed = trim_prefix(line, prefix);
	stripped = ft_strtrim(trimmed, " \n\t");
	if (!stripped || *stripped == '\0')
		return (free(trimmed), -1); // Trim or allocation failed
	*dest = stripped;
	return (1); // Match and assignment successful
}

int	assign_color(char *line, char *prefix, t_color *dest)
{
	char	*trimmed;
	char	*content;
	int		result;

	trimmed = ft_strtrim(line, " \t\n");
	if (!trimmed)
		return (-1);
	if (ft_strncmp(trimmed, prefix, ft_strlen(prefix)) != 0)// Check prefix match
		return (free(trimmed), 0);
	if (dest->r != -1 || dest->g != -1 || dest->b != -1) // Already assigned
		return (free(trimmed), -1);
	content = ft_strtrim(trimmed + ft_strlen(prefix), " \t\n"); // Extract and trim the part after prefix
	free(trimmed);
	if (!content)
		return (-1);
	result = parse_color(content, dest);
	free(content);
	if (result == 0)
		return (1);
	else
		return (-1);
}

int	parse_till_map(char *line, t_path *config)
{
	int	res;

	if (is_empty_line(line))
		return (0);
	res = assign_texture(line, "NO", &config->no_texture);
	if (res != 0)
		return (res);
	res = assign_texture(line, "SO", &config->so_texture);
	if (res != 0)
		return (res);
	res = assign_texture(line, "WE", &config->we_texture);
	if (res != 0)
		return (res);
	res = assign_texture(line, "EA", &config->ea_texture);
	if (res != 0)
		return (res);
	res = assign_color(line, "F", &config->floor);
	if (res != 0)
		return (res);
	res = assign_color(line, "C", &config->ceiling);
	if (res != 0)
		return (res);
	return (2);
}


int	parse_line_by_line(char *filename, t_game *game, char **map_text)
{
	int		fd;
	char	*line;
	char	*tmp;
	int		is_map_started;
	int		res_texture;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		free(*map_text);
		return (ft_puterr_fd(ERR_OPEN, 2), -1);
	}
	is_map_started = 0;
	while ((line = get_next_line(fd)))
	{
		if (!is_map_started)
		{
			res_texture = parse_till_map(line, &game->path);
			if (res_texture == -1)
			{
				printf("Error\nInvalid config line: %s\n", line);
				free(line);
				close(fd);
				free(*map_text);
				return (-1);
			}
			else if (res_texture == 2)
				is_map_started = 1;
		}
		if (is_map_started)
		{
			tmp = *map_text;
			*map_text = ft_strjoin(*map_text, line);
			free(tmp);
			if (!*map_text)
				return (free(line), close(fd), -1);
		}
		free(line);
	}
	return (close(fd), 0);
}


int	check_config_complete(t_path *config)
{
	if (!config->no_texture || !config->so_texture || !config->we_texture
		|| !config->ea_texture)
		return (ft_puterr_fd(ERR_NO_T_PATH, 2), -1);
	if (config->floor.r == -1 || config->floor.g == -1 || config->floor.b == -1)
		return (ft_puterr_fd(ERR_NO_F_COLOR, 2), -1);
	if (config->ceiling.r == -1 || config->ceiling.g == -1 \
		|| config->ceiling.b == -1)
		return (ft_puterr_fd(ERR_NO_C_COLOR, 2), -1);
	return (0);
}

int	parse_file(char *filename, t_game *game)
{
	char	*map_text;

	map_text = ft_calloc(1, sizeof(char));
	if (!map_text)
		return (ft_puterr_fd(ERR_ALLOC, 2), -1);
	if (parse_line_by_line(filename, game, &map_text) != 0)
		return (-1);
	game->map.map = ft_split(map_text, '\n');
	free(map_text);
	if (!game->map.map)
		return (ft_puterr_fd(ERR_MAP, 2), -1);
	if (check_config_complete(&game->path) < 0)
		ft_exit_all(game, 1);
	return (0);
}
