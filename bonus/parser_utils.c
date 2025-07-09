/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:37:45 by pde-vara          #+#    #+#             */
/*   Updated: 2025/07/07 18:30:12 by pde-vara         ###   ########.fr       */
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

int	is_empty_line(const char *line)
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

void	cleanup_get_next_line(int fd)
{
	char	*dummy;

	dummy = get_next_line(fd);
	while (dummy != NULL)
	{
		free(dummy);
		dummy = get_next_line(fd);
	}
}

int	count_commas(const char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == ',')
			count++;
		str++;
	}
	return (count);
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
