/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndabbous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:38:54 by ndabbous          #+#    #+#             */
/*   Updated: 2024/11/21 15:40:17 by ndabbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

/*#include <unistd.h>
#include <fcntl.h>
int	main()
{
	int fd = open("test.txt", O_WRONLY);
	ft_putchar_fd('A', fd);
	close(fd);
}*/
