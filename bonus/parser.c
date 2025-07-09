/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:26:47 by pde-vara          #+#    #+#             */
/*   Updated: 2025/07/08 17:56:01 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	accumulate_map_text(char *line, char **map_text)
{
	char	*tmp;

	if (is_empty_line(line))
		return (0);
	tmp = *map_text;
	*map_text = ft_strjoin(*map_text, line);
	free(tmp);
	if (!*map_text)
		return (-1);
	return (0);
}

static int	handle_texture_line(char *line, t_game *game, int *map_started)
{
	int	res_texture;

	res_texture = parse_till_map(line, &game->path);
	if (res_texture == -1)
	{
		printf("Error\nInvalid config line: %s\n", line);
		return (-1);
	}
	if (res_texture == 2)
		*map_started = 1;
	return (0);
}

static int	process_line(char *line, t_game *game, \
			int *map_started, char **map_text)
{
	if (!*map_started)
	{
		if (handle_texture_line(line, game, map_started) == -1)
			return (-1);
	}
	if (*map_started)
	{
		if (accumulate_map_text(line, map_text) == -1)
			return (-1);
	}
	return (0);
}

int	parse_line_by_line(char *filename, t_game *game, char **map_text)
{
	int		fd;
	char	*line;
	int		map_started;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (free(*map_text), ft_puterr_fd(ERR_OPEN, 2), -1);
	map_started = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (process_line(line, game, &map_started, map_text) == -1)
		{
			free(line);
			free(*map_text);
			cleanup_get_next_line(fd);
			return (close(fd), -1);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
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

// int	parse_line_by_line(char *filename, t_game *game, char **map_text)
// {
// 	int		fd;
// 	char	*line;
// 	char	*tmp;
// 	int		is_map_started;
// 	int		res_texture;

// 	fd = open(filename, O_RDONLY);
// 	if (fd < 0)
// 		return (free(*map_text), ft_puterr_fd(ERR_OPEN, 2), -1);
// 	is_map_started = 0;
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		if (!is_map_started)
// 		{
// 			res_texture = parse_till_map(line, &game->path);
// 			if (res_texture == -1)
// 				return (printf("Error\nInvalid config line: %s\n", line),
// 					free(line), close(fd), free(*map_text), -1);
// 			else if (res_texture == 2)
// 				is_map_started = 1;
// 		}
// 		if (is_map_started)
// 		{
// 			tmp = *map_text;
// 			*map_text = ft_strjoin(*map_text, line);
// 			free(tmp);
// 			if (!*map_text)
// 				return (free(line), close(fd), -1);
// 		}
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	return (close(fd), 0);
// }