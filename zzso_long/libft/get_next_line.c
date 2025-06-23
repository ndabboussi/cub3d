/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:59:24 by pde-vara          #+#    #+#             */
/*   Updated: 2024/12/20 15:11:17 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*join_free(char *buffer_static, char *buffer)
{
	char	*temp;

	if (!buffer_static || !buffer)
		return (free(buffer_static), NULL);
	temp = ft_strjoin(buffer_static, buffer);
	if (!temp)
		return (free(buffer_static), NULL);
	return (free(buffer_static), temp);
}

char	*delete_line(char *buffer_static)
{
	int		i;
	char	*temp;

	i = 0;
	if (!buffer_static)
		return (NULL);
	while (buffer_static[i] && buffer_static[i] != '\n')
		i++;
	if (buffer_static[i] == '\0')
	{
		return (free(buffer_static), NULL);
	}
	temp = ft_strdup(&buffer_static[i + 1]);
	if (!temp)
	{
		return (free(buffer_static), NULL);
	}
	return (free(buffer_static), temp);
}

char	*ft_line(char *buffer_static)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer_static[i])
		return (NULL);
	while (buffer_static[i] && buffer_static[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (free(line), free(buffer_static), NULL);
	i = 0;
	while (buffer_static[i] && buffer_static[i] != '\n')
	{
		line[i] = buffer_static[i];
		i++;
	}
	if (buffer_static[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*read_file(int fd, char *buffer_static, int byte_read)
{
	char	*buffer;

	if (!buffer_static)
	{
		buffer_static = ft_calloc(1, sizeof(char));
		if (!buffer_static)
			return (NULL);
	}
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read < 0)
			return (free(buffer), NULL);
		buffer[byte_read] = '\0';
		buffer_static = join_free(buffer_static, buffer);
		if (!buffer_static)
			return (free(buffer), NULL);
		if (ft_strchr(buffer_static, '\n'))
			break ;
	}
	return (free(buffer), buffer_static);
}

char	*get_next_line(int fd)
{
	static char	*buffer_static;
	char		*line;
	int			byte_read;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (free(buffer_static), buffer_static = NULL, NULL);
	byte_read = 1;
	buffer_static = read_file(fd, buffer_static, byte_read);
	if (!buffer_static || !buffer_static[0])
		return (free(buffer_static), buffer_static = NULL, NULL);
	line = ft_line(buffer_static);
	if (!line)
		return (free(buffer_static), buffer_static = NULL, NULL);
	buffer_static = delete_line(buffer_static);
	return (line);
}

/* int	main(int ac, char **av)
{
	char	*line;
	int		fd;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
 */