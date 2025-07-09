/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_till_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:43:53 by ndabbous          #+#    #+#             */
/*   Updated: 2025/07/08 16:04:10 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_color(char *str, t_color *color)
{
	int		i;
	char	**components;

	if (count_commas(str) != 2)
		return (1);
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
	if (color->r < 0 || color->r > 255
		|| color->g < 0 || color->g > 255
		|| color->b < 0 || color->b > 255)
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
		return (-1);
	trimmed = trim_prefix(line, prefix);
	stripped = ft_strtrim(trimmed, " \n\t");
	if (!stripped || *stripped == '\0')
		return (free(trimmed), -1);
	*dest = stripped;
	return (1);
}

int	assign_color(char *line, char *prefix, t_color *dest)
{
	char	*trimmed;
	char	*content;
	int		result;

	trimmed = ft_strtrim(line, " \t\n");
	if (!trimmed)
		return (-1);
	if (ft_strncmp(trimmed, prefix, ft_strlen(prefix)) != 0)
		return (free(trimmed), 0);
	if (dest->r != -1 || dest->g != -1 || dest->b != -1)
		return (free(trimmed), -1);
	content = ft_strtrim(trimmed + ft_strlen(prefix), " \t\n");
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
